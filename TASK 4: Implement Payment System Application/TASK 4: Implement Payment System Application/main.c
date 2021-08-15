#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
#include "File_Handling.h"

#define Debug 0
#define Max_Transaction_Limit 5000

void Make_New_Transaction(void);
void Verify_Transaction(ST_Transaction_t*);

ST_AccountBalance_t Bank_Customers_Balance[10];
uint32_t Number_of_Transactions = 0;

int main()
{
    Import_Bank_Server_Data(Bank_Customers_Balance);
    
    Make_New_Transaction();
}

void Make_New_Transaction(void)
{
    system("clear");
    ST_Transaction_t New_Transaction;
    New_Transaction.Transaction_Data.Max_Transaction_Amount = Max_Transaction_Limit;
    
    printf("Please Enter Card Data :- \n");
    printf("--------------------------\n");

    printf("Please Enter the Card Holder Name : ");
    scanf("%[^\n]",New_Transaction.Card_Holder_Data.Holder_Name);
    
    printf("Please Enter the Primary Account Number : ");
    scanf("%s",New_Transaction.Card_Holder_Data.PAN);
    
    printf("Please Card Expiry Date (MM/YY) : ");
    scanf("%s",New_Transaction.Card_Holder_Data.Expiration_Date);
    
    printf("\n");
    printf("Please Enter Terminal Data:- \n");
    printf("-----------------------------\n");

    printf("Please Enter the Transaction Amount : ");
    scanf("%f",&New_Transaction.Transaction_Data.Transaction_Amount);

    printf("Please Enter Transaction Date (DD/MM/YYYY) : ");
    scanf("%s",New_Transaction.Transaction_Data.Transaction_Date);

    printf("\n \n \n");
    printf("Verifying Data From the Server... \n\n");
    
    Verify_Transaction(&New_Transaction);
    
    if(New_Transaction.Transaction_State == APPROVED)
    {
        printf("The Transaction is APPROVED ! \n");
    }
    else if(New_Transaction.Transaction_State == DECLINED)
    {
        printf("The Transaction is DECLINED ! \n");
    }
    
    printf("You Want To Make New Transaction ? (Y/N) : "); getchar();
    
    uint8_t Response = getchar();
    
    if(Response == 'Y' || Response == 'y')
    {
        printf("\n \n \n");
        getchar();
        Make_New_Transaction();
    }
    else
    {
        exit(0);
    }
    
    
}

void Verify_Transaction(ST_Transaction_t* Transaction)
{
    uint32_t Error = 0;
    
    uint32_t Transaction_Month = atoi((char*)(&Transaction->Transaction_Data.Transaction_Date[3]));
    uint32_t Transaction_Year = atoi((char*)(&Transaction->Transaction_Data.Transaction_Date[8]));
    
    uint32_t Card_Exp_Month = atoi((char*)(&Transaction->Card_Holder_Data.Expiration_Date[0]));
    uint32_t Card_Exp_Year = atoi((char*)(&Transaction->Card_Holder_Data.Expiration_Date[3]));
    
    if(Transaction_Year <= Card_Exp_Year)
    {
        if(Transaction_Month >= Card_Exp_Month)
        {
            Error = 1;
            goto End;
        }
    }
    else
    {
        Error = 1;
        goto End;
    }
    
    if(Transaction->Transaction_Data.Transaction_Amount > Transaction->Transaction_Data.Max_Transaction_Amount)
    {
        Error = 2;
        goto End;
    }
    
    uint32_t Card_PAN = atoi((char*)(Transaction->Card_Holder_Data.PAN));
    uint8_t Pan_Index = 'X';
    
    for(int C=0 ; C<Number_of_Bank_Customers ;C++)
    {
        uint32_t Temp = atoi((char*)Bank_Customers_Balance[C].PAN);
        
        if(Temp == Card_PAN)
        {
            Pan_Index = C;
            break;
        }
    }

    if(Pan_Index == 'X')
    {
        Error = 3;
        goto End;
    }
    
    
    if(Transaction->Transaction_Data.Transaction_Amount > Bank_Customers_Balance[Pan_Index].Balance)
    {
        Error = 4;
        goto End;
    }
    
    
    if(Error == 0)
    {
        Transaction->Transaction_State = APPROVED;
    }
    else
    {
        End:
        Transaction->Transaction_State = DECLINED;
        
        #if DEBUG
        switch (Error)
        {
            case 1:
                printf("\n Card Expired !\n");
                break;
            case 2:
                printf("\n Transaction amount larger than Maximum Transaction Amount ! \n");
                break;
            case 3:
                printf("\n Card Not Found in Bank Servers! \n");
                break;
            case 4:
                printf("\n Transaction amount larger than Card Balance ! \n");
                break;
        }
        #endif
    }
    
    Export_Transactions_Data(Transaction , Error);
}

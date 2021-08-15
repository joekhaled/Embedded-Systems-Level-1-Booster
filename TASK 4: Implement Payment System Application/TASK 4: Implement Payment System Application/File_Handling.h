#ifndef File_Handling_h
#define File_Handling_h

#define Number_of_Bank_Customers 10

void Import_Bank_Server_Data(ST_AccountBalance_t* Bank_Customers_Balance_Array)
{
    FILE *File_Ptr;
    
    File_Ptr = fopen("Bank_Server_Data.txt","r");

    for(int C=0 ; C<Number_of_Bank_Customers ; C++)
    {
        fscanf(File_Ptr,"PAN : %s , Balance : %f \n",Bank_Customers_Balance_Array[C].PAN,&Bank_Customers_Balance_Array[C].Balance);
        fscanf(File_Ptr,"---------------------------------------------------------------------------------------\n");
    }
    
    fclose(File_Ptr);
}

void Export_Transactions_Data(ST_Transaction_t* New_Transaction , uint32_t Reason)
{
    FILE *File_Ptr;
    
    File_Ptr = fopen("Transactions_Data.txt","a");

    fprintf(File_Ptr,"Card Holder Data :- \n");
    fprintf(File_Ptr,"--------------------\n");
    fprintf(File_Ptr,"Card Holder Name : %s\n",New_Transaction->Card_Holder_Data.Holder_Name);
    fprintf(File_Ptr,"Card Holder PAN : %s\n",New_Transaction->Card_Holder_Data.PAN);
    fprintf(File_Ptr,"Card Expiry Date : %s\n",New_Transaction->Card_Holder_Data.Expiration_Date);
    fprintf(File_Ptr,"Terminal Data :- \n");
    fprintf(File_Ptr,"-----------------\n");
    fprintf(File_Ptr,"Transaction Amount : %.2f\n",New_Transaction->Transaction_Data.Transaction_Amount);
    fprintf(File_Ptr,"Transaction Date : %s\n",New_Transaction->Transaction_Data.Transaction_Date);
    fprintf(File_Ptr,"Transaction State :- \n");
    fprintf(File_Ptr,"---------------------\n");
    if(New_Transaction->Transaction_State == APPROVED)
    {
        fprintf(File_Ptr,"Transaction State : APPROVED \n");
    }
    else if(New_Transaction->Transaction_State == DECLINED)
    {
        fprintf(File_Ptr,"Transaction State : DECLINED \n");
        
        switch (Reason)
        {
            case 1:
                fprintf(File_Ptr,"Reason : Card Expired \n");
                break;
            case 2:
                fprintf(File_Ptr,"Reason : Transaction amount larger than Maximum Transaction Amount \n");
                break;
            case 3:
                fprintf(File_Ptr,"Reason : Card Not Found in Bank Servers \n");
                break;
            case 4:
                fprintf(File_Ptr,"Reason : Transaction amount larger than Card Balance \n");
                break;
        }
    }
    
    
    fprintf(File_Ptr,"---------------------------------------------------------------------------------------\n");

    fclose(File_Ptr);
}

#endif

#include <stdio.h>
#include <string.h> //Used For bzero Function
#include "Types.h"

#define Max_Array_Size 255

//Functions Prototypes
void Bubble_Sort(uint32_t*);
uint8_t Binary_Search(uint32_t* ,uint8_t , uint32_t);

//Initialization
uint32_t Array[Max_Array_Size];
uint32_t Required_Number = 0;
uint32_t Array_Length = 0;

int main()
{
    while(1) //Infinite Loop to Restart Program After Every Search
    {
        bzero(Array,Max_Array_Size); //Standard Function to Clear Elements Array Every Time
        Required_Number = 0; //Variable to Store Required Number to Search
        Array_Length = 0;
        
        printf("Enter Array Elements : ");
        
        do
        {
            scanf("%d",&Array[Array_Length]); //Read & Stores Elemnt by Elemnt
            Array_Length++;
            
        }while(getchar() != '\n'); //Stop Loop When Reaches End
        
        Bubble_Sort(Array); //Function That Sort Given Array Elements Ascendingly
        
        printf("Array Elements After Sorting Ascendingly : ");
        
        for(int C=0 ; C<Array_Length ;C++) //Loop To Print Array Elements
        {
            printf("%d ",Array[C]);
        }
        
        printf("\n");
        
        printf("Enter Number You Want to Find : ");
        scanf("%d",&Required_Number);
        
        uint8_t Position = Binary_Search(Array,Array_Length,Required_Number); //Send Data to Binary Search Function and Return Position
        
        if(Position == 'X') //Binary Search Function Returns X Character if Number not Found in Array
        {
            printf("Number you Entered is Not Found \n\n");
        }
        else //If Number Found -> Prints it's Index
        {
            printf("Location of Required Number : %d \n\n",Position+1);
        }
        
    }
}

void Bubble_Sort(uint32_t* Array_Ptr)
{
    for (int C1=0 ; C1<Array_Length ; C1++)
     {
         for (int C2=0 ; C2<Array_Length-1 ; C2++)
         {
             int X = Array[C2+1];
             int Y = Array[C2];
         
             if(X<Y) //If Number is Less Than the Next Number Then Swap Them
             {
                 Array[C2+1] = Y;
                 Array[C2] = X;
             }
         }
     }
}

uint8_t Binary_Search(uint32_t* Array,uint8_t Size, uint32_t Required_Number)
{
    uint8_t Position = 0 , Found = 0;
    uint32_t Start = 0 , Mid , End = Size-1;
    
    while(Start <= End)
    {
        Mid = (End+Start)/2;
        
        if (Required_Number == Array[Mid])
        {
            Position = Mid;
            Found = 1;
            break;
        }
        else if (Required_Number < Array[Mid])
        {
            End = Mid - 1;
        }
        else
        {
            Start = Mid + 1;
        }
    }
    
    if(Found == 1)
    {
        return Position;
    }
    else
    {
        return 'X';
    }
}

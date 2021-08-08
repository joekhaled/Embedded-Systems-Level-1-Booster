#include <stdio.h>
#include <string.h> //Used For bzero Function
#include "Types.h"

#define Max_Array_Size 100

//Functions Prototypes
void Bubble_Sort(uint32_t*);
uint8_t Binary_Search(uint32_t* ,uint8_t , uint32_t);

//Initialization
uint32_t Array[Max_Array_Size];
uint32_t Required_Number = 0;
uint32_t Array_Length = 0;

int main()
{
    while(1)
    {
        bzero(Array,Max_Array_Size);
        Required_Number = 0;
        Array_Length = 0;
        
        printf("Enter Array Elemnts : ");
        
        do
        {
            scanf("%d",&Array[Array_Length]);
            Array_Length++;
            
        }while(getchar() != '\n');
        
        Bubble_Sort(Array);
        
        printf("Array Elemnts After Sorting : ");
        
        for(int C=0 ; C<Array_Length ;C++)
        {
            printf("%d ",Array[C]);
        }
        
        printf("\n");
        
        printf("Enter Number You Want to Find : ");
        scanf("%d",&Required_Number);
        
        uint8_t Position = Binary_Search(Array,Array_Length,Required_Number);
        
        if(Position == 'X')
        {
            printf("Number you Entered is Not Found \n\n");
        }
        else
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
         
             if(X<Y)
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

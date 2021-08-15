#ifndef Searching_Sorting_h
#define Searching_Sorting_h

void Bubble_Sort(uint32_t* Array)
{
    uint32_t Array_Length = 0;
    uint32_t *Ptr = Array;
    
    while(*Ptr != '\0')
    {
        Array_Length++;
        Ptr++;
    }
    
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

uint8_t Binary_Search(uint32_t* Array, uint32_t Required_Number)
{
    Bubble_Sort(Array);
    
    uint8_t Position = 0 , Found = 0;
    uint32_t Start = 0 , Mid , End = 0;
    
    uint32_t Size = 0;
    uint32_t *Ptr = Array;
    
    while(*Ptr != '\0')
    {
        Size++;
        Ptr++;
    }
    
    End = Size-1;
    
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
        return Position + 1;
    }
    else
    {
        return 'X';
    }
}

#endif

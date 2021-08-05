#include <stdio.h>
#include <stdlib.h>
#include "Types.h"

#define Max_Expression_Size 50

//Functions Prototypes
void Push(uint8_t);
uint8_t Pull(void);
void Print_Stack(void);
uint8_t* Balanced_Parentheses(uint8_t*);
void Expression_Parentheses_Checker(void);

//Strings Saved As Array of Characters
uint8_t B[9] = {'B','a','l','a','n','c','e','d','\0'};
uint8_t U[13] = {'N','o','t',' ','B','a','l','a','n','c','e','d','\0'};

//Stack Implementation
struct Stack
{
    uint8_t Expression[Max_Expression_Size];
    int32_t Top;
    
} Stack;

//Main Function
int main()
{
    while(1)
    {
        Expression_Parentheses_Checker();
    }
    
}

void Expression_Parentheses_Checker(void)
{
    Stack.Top = -1;
    uint8_t Temp;
    
    printf("Enter an Expression : ");
    scanf("%c",&Temp);
    do
    {
        Push(Temp);
        scanf("%c",&Temp);
    }while(Temp != '\n');
    
    
    printf("%s",Balanced_Parentheses(Stack.Expression));
    printf("\n \n");
    
//    Print_Stack();
    
}

uint8_t* Balanced_Parentheses(uint8_t* Exp)
{
    struct Stack Temp;
    Temp.Top = -1;
    uint8_t Character;
    int32_t Counter = 0;
    
    do
    {
        Character = Pull();
        
        if(Character == '}' || Character == ')')
        {
            Temp.Top ++;
            Temp.Expression[Temp.Top] = Character;
        }
        
        if(Character == '{' || Character == '(')
        {
            if(Character == '{' && Temp.Expression[Temp.Top] == '}')
            {
                Temp.Expression[Temp.Top] = '\0';
                Temp.Top --;
            }
            else if(Character == '(' && Temp.Expression[Temp.Top] == ')')
            {
                Temp.Expression[Temp.Top] = '\0';
                Temp.Top --;
            }
        }
        
        Counter++;
    }while(Character != '\0');
    
    
    if(Temp.Top == -1)
    {
        return B;
    }
    else
    {
        return U;
    }
}

void Push(uint8_t Character)
{
    if (Stack.Top == (Max_Expression_Size - 1))
    {
        printf ("Expression is Very Large\n");
        Expression_Parentheses_Checker();
    }
    else
    {
        Stack.Top ++;
        Stack.Expression[Stack.Top] = Character;
    }
}

uint8_t Pull(void)
{
    uint8_t Character;
    
    if (Stack.Top != -1)
    {
        Character = Stack.Expression[Stack.Top];
        Stack.Top = Stack.Top - 1;
        return Character;
    }
    return '\0';
}

void Print_Stack(void)
{
    printf("\n");
    
    while(Stack.Top != -1)
    {
        printf("%c",Pull());
    }
}

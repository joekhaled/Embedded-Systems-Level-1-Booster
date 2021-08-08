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
    uint8_t Elements[Max_Expression_Size];
    int32_t Top;
    
} Expression;

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
    Expression.Top = -1;
    uint8_t Temp;
    
    printf("Enter an Expression : ");
    
    do
    {
        scanf("%c",&Temp);
        if(Temp != '\n')
        {
            Push(Temp);
        }
    }while(Temp != '\n');
    
    
    printf("%s",Balanced_Parentheses(Expression.Elements));
    printf("\n \n");
    
//    Print_Stack();
    
}

uint8_t* Balanced_Parentheses(uint8_t* Exp)
{
    uint8_t Character;
    struct Stack Temp;
    Temp.Top = -1;
    
    do
    {
        Character = *Exp;
        
        if(Character == '{' || Character == '(')
        {
            Temp.Top++;
            Temp.Elements[Temp.Top] = Character;
        }
        else if(Character == '}' || Character == ')')
        {
            if(Character == '}' && Temp.Elements[Temp.Top] == '{')
            {
                Temp.Elements[Temp.Top] = '\0';
                Temp.Top--;
            }
            else if(Character == ')' && Temp.Elements[Temp.Top] == '(')
            {
                Temp.Elements[Temp.Top] = '\0';
                Temp.Top--;
            }
        }
        
        Exp++;
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
    if (Expression.Top == (Max_Expression_Size - 1))
    {
        printf ("Expression is Very Large\n");
        Expression_Parentheses_Checker();
    }
    else
    {
        Expression.Top ++;
        Expression.Elements[Expression.Top] = Character;
    }
}

uint8_t Pull(void)
{
    uint8_t Character;
    
    if (Expression.Top != -1)
    {
        Character = Expression.Elements[Expression.Top];
        Expression.Top --;
        return Character;
    }
    else
    {
        return '\0';
    }
    
}

void Print_Stack(void)
{
    printf("\n");
    
    while(Expression.Top != -1)
    {
        printf("%c",Pull());
    }
}

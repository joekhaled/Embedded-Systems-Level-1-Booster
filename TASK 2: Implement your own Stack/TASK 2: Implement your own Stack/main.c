#include <stdio.h>
#include <string.h> //Used For bzero Function
#include "Types.h"

#define Max_Expression_Size 50

//Functions Prototypes
void Push(uint8_t);
uint8_t Pull(void);
void Print_Stack(void);
uint8_t* Balanced_Parentheses(uint8_t*);
void Expression_Parentheses_Checker(void);

//Strings
uint8_t B[9] = {"Balanced"};
uint8_t U[13] = {"Not Balanced"};

//Stack Implementation
struct Stack
{
    uint8_t Elements[Max_Expression_Size];
    int32_t Top;
    
} Expression;

//Main Function
int main()
{
    while(1) //Infinite Loop to Restart Program After Every Expression Check
    {
        Expression_Parentheses_Checker();
    }
}

void Expression_Parentheses_Checker(void)
{
    bzero(Expression.Elements, Max_Expression_Size); //Standard Function to Clear Elements Array Every Time
    Expression.Top = -1; //Initialization of Top with -1
    uint8_t Temp; //Temporary Variable To Store Characters to While Scanning
    
    printf("Enter an Expression : ");
    scanf("%c",&Temp); //Scan First Character
    
    while(Temp != '\n') //Check if Character isn't Enter Character so it stop Iteration When it's End of Expression
    {
        Push(Temp); //Push It Into Main Stack
        scanf("%c",&Temp); //Scan Character By Character
    }
    
    printf("%s",Balanced_Parentheses(Expression.Elements)); //Print The Result of Expression Parentheses Check
    printf("\n \n");
    
    //    Print_Stack(); //Function to Print Stack for Debugging
    
}

uint8_t* Balanced_Parentheses(uint8_t* Exp)
{
    uint8_t Character; //Temporary Variable To Store Character
    
    struct Stack Temp; //Temporary Stack To Store Parentheses to Compare
    Temp.Top = -1; //Initialization of Top with -1
    
    if(Expression.Top > 0) //Check if Expression is longer than one Character
    {
        do
        {
            Character = *Exp; //Temporary Variable stores Charcter of Array that Pointer Exp pointing on
            
            if(Character == '{' || Character == '(') //Check if Charcter is Opening Parenthes
            {
                Temp.Top++; //Increment Top of Temp Stack
                Temp.Elements[Temp.Top] = Character; //Add Charcter to Temp Stack
            }
            else if(Character == '}' || Character == ')') //Check if Charcter is Closing Parenthes
            {
                if(Character == '}' && Temp.Elements[Temp.Top] == '{') //Check if Last Charcter in Temp Stack is Closing Parenthes
                {
                    Temp.Elements[Temp.Top] = '\0'; //Remove Charcter to Temp Stack
                    Temp.Top--; //Decrement Top of Temp Stack
                }
                else if(Character == ')' && Temp.Elements[Temp.Top] == '(') //Check if Last Charcter in Temp Stack is Closing Parenthes
                {
                    Temp.Elements[Temp.Top] = '\0'; //Remove Charcter to Temp Stack
                    Temp.Top--; //Decrement Top of Temp Stack
                }
            }
            
            Exp++; //Increment Pointer Postion to Next Charcter
        }while(Character != '\0'); //Break Loop When it Reaches End of Expression
    }
    else
    {
        return U; //Case:If Expression is longer than one Character Return Not Balanced
    }
    
    
    if(Temp.Top == -1) //If Temp Stack is Empty at the End of the Check Return Balanced
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
    if (Expression.Top == (Max_Expression_Size - 1)) //Check to Handle Stack Overflow
    {
        printf ("Expression is Very Large\n");
        Expression_Parentheses_Checker(); //Restart Program
    }
    else
    {
        Expression.Top ++; //Increment Top
        Expression.Elements[Expression.Top] = Character; //Add Character to Stack
    }
}

uint8_t Pull(void)
{
    uint8_t Character;
    
    if (Expression.Top != -1)
    {
        Character = Expression.Elements[Expression.Top]; //Return Character From Stack
        Expression.Elements[Expression.Top] = '\0'; //Extra Step to Clean Stack from Garbage Values
        Expression.Top --; //Decrement Top
        return Character;
    }
    else
    {
        return '\0'; //Handle Pulling From Empty Stack
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

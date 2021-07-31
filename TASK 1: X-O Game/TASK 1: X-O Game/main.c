//Libraries
#include <stdio.h>
#include <stdlib.h>

//Functions Prototypes
void Tic_Tac_Toe(void);
void xo_logo(void);
int  game(char, char);

//Main Function
int main()
{
    
   Tic_Tac_Toe(); //Calls The Game Function Once
    
}

// Tic-Tac-Toe Game Main Function
void Tic_Tac_Toe(void)
{
    int R, Result;
    char P1, P2 = '\0';
    
    system("clear"); //Clear Command Screen
    xo_logo(); //Shows Tic-Tac-Toe Logo
    printf("\n");
    printf("Please Enter Player 1 Symbol (X or O) : "); P1 = getchar();
    
    
    if ((P1 == 'X') || (P1 == 'x')) //If Player 1 is X -> Player 2 is O
    {
        P2 = 'o';
    }
    else if ((P1 == 'O') || (P1 == 'o')) //If Player 1 is O -> Player 2 is X
    {
        P2 = 'x';
    }
    else //If User Enters Neither X nor O , Then it's Wrong Entry and Program Restart and Waits for Correct Entry
    {
        printf("Wrong Entry !\n");
        Tic_Tac_Toe();
    }
    
    system("clear"); //Clear Command Screen
    
    
    Result = game(P1, P2); //Game Function Takes Player 1 & Player 2 Symbols and Start The Game then Return The Result
    
    
    if (Result == 1) //Player X Wins
    {
        printf("\n\nX Player Wins !");
    }
    else if (Result == 2) //Player O Wins
    {
        printf("\n\nO Player Wins !");
    }
    else //Tie
    {
        printf("\n\nNo One Wins !");
    }
    
    //After Game Options
    printf("\n\nType 1 To Start The Game Again \n");
    printf("Type 0 To Exit \n");
    printf("Your Choice is : ");
    scanf("%d", &R);
    
    switch (R)
    {
        case 1: //Re-Start The Game
            system("clear");
            Tic_Tac_Toe();
            break;
            
        case 0: //Close Game and Exit Terminal
            exit(0);
            break;
            
        default:
            printf("Wrong Entry !\n\n");
            break;
    }
}

// Tic Tac Toe Game Sub Function
int game(char P1, char P2)
{
    int Res = 0, ro, co;
    char Board[3][3] = { { '-','-','-' } ,{ '-','-','-' } ,{ '-','-','-' } }, T; //Board Initialization with Empty Blocks
    
    T = P2;
    
    
    printf("-------\n"); //Horizontal Game Border
    
    
    for (int c1 = 0; c1<3; c1++)
    {
        printf("|");//Vertical Game Border
        
        for (int c2 = 0; c2<3; c2++) //Blocks Printer
        {
            printf("%c|", Board[c1][c2]);
        }
        
        printf("\n");
        printf("-------\n");//Horizontal Game Border
    }
    
    
    while(1) //Infinite Loop that Stops When The Game Ends
    {
        //Switch Player Turn
        if ((T == 'X') || (T == 'x'))
        {
            T = 'O';
        }
        else if ((T == 'O') || (T == 'o'))
        {
            T = 'X';
        }
        
        Check_Point_1 :
        
        //Asks User For His Next Move Location as Rows and Columns
        printf("%c Player Turn : What is the location you want to use (as Row and Column)?\n", T);
        
        printf("Row : "); scanf("%d", &ro);
        
        //Check if User Enters Row Out of Boundaries if He did it will ask Him again for Correct Entry
        
        if (ro<1 || ro>3)
        {
            system("clear");
            printf("\nWorng Entry !\n\n");
            goto Check_Point_1 ;
        }
        
        Check_Point_2 :
        
        printf("Column : "); scanf("%d", &co);
        
        //Check if User Enters Column Out of Boundaries if He did it will ask Him again for Correct Entry
        if (co<1 || co>3)
        {
            system("clear");
            printf("\nWorng Entry !\n\n");
            goto Check_Point_2 ;
        }
        
        system("clear");
        
        //Check if Desired Location is Taken
        if (Board[ro - 1][co - 1] == 'X' || Board[ro - 1][co - 1] == 'O')
        {
            printf("Location is Already Taken !\n");
            
            //If Location is already Taken It Will Switch Player Turn , So When the Loop iterates and Switch the Turn Again The Turn Remains Correct until the Player Enters Location That's Not already Taken
            if ((T == 'X') || (T == 'x'))
            {
                T = 'O';
            }
            else if ((T == 'O') || (T == 'o'))
            {
                T = 'X';
            }
        }
        else //If Location is Free Then it will Assign the Player Symbol on The Desired Location
        {
            Board[ro - 1][co - 1] = T;
        }
        
        //Update The Board After the New Move
        printf("-------\n");
    
        for (int c1 = 0; c1<3; c1++)
        {
            printf("|");
            for (int c2 = 0; c2<3; c2++)
            {
                printf("%c|", Board[c1][c2]);
            }
            
            printf("\n");
            printf("-------\n");
            
        }
        
        
        if ((Board[0][0] == 'X' && Board[0][1] == 'X' && Board[0][2] == 'X') || (Board[1][0] == 'X' && Board[1][1] == 'X' && Board[1][2] == 'X') || (Board[2][0] == 'X' && Board[2][1] == 'X' && Board[2][2] == 'X'))//X Horitzontal Check
        {
            Res = 1;
            break;
        }
        
        else if ((Board[0][0] == 'O' && Board[0][1] == 'O' && Board[0][2] == 'O') || (Board[1][0] == 'O' && Board[1][1] == 'O' && Board[1][2] == 'O') || (Board[2][0] == 'O' && Board[2][1] == 'O' && Board[2][2] == 'O'))//O Horitzontal Check
        {
            Res = 2;
            break;
        }
        
        
        else if ((Board[0][0] == 'X' && Board[1][0] == 'X' && Board[2][0] == 'X') || (Board[0][1] == 'X' && Board[1][1] == 'X' && Board[2][1] == 'X') || (Board[0][2] == 'X' && Board[1][2] == 'X' && Board[2][2] == 'X'))//X Vertical Check
        {
            Res = 1;
            break;
        }

        else if ((Board[0][0] == 'O' && Board[1][0] == 'O' && Board[2][0] == 'O') || (Board[0][1] == 'O' && Board[1][1] == 'O' && Board[2][1] == 'O') || (Board[0][2] == 'O' && Board[1][2] == 'O' && Board[2][2] == 'O'))//O Vertical Check
        {
            Res = 2;
            break;
        }
        
        
        else if ((Board[0][0] == 'X' && Board[1][1] == 'X' && Board[2][2] == 'X') || (Board[0][2] == 'X' && Board[1][1] == 'X' && Board[2][0] == 'X'))//X Diagnonal Check
        {
            Res = 1;
            break;
        }
        
        else if ((Board[0][0] == 'O' && Board[1][1] == 'O' && Board[2][2] == 'O') || (Board[0][2] == 'O' && Board[1][1] == 'O' && Board[2][0] == 'O'))//O Diagnonal Check
        {
            Res = 2;
            break;
        }
        
        
        else if ((Board[0][0] == 'X' || Board[0][0] == 'O') && (Board[0][1] == 'X' || Board[0][1] == 'O') && (Board[0][2] == 'X' || Board[0][2] == 'O') && (Board[1][0] == 'X' || Board[1][0] == 'O') && (Board[1][1] == 'X' || Board[1][1] == 'O') && (Board[1][2] == 'X' || Board[1][2] == 'O') && (Board[2][0] == 'X' || Board[2][0] == 'O') && (Board[2][1] == 'X' || Board[2][1] == 'O') && (Board[2][2] == 'X' || Board[2][2] == 'O')) // Check If Board is Full
        {
            Res = 0;
            break;
        }
    }
    
    return (Res);
}


//Function That Draws The Tic-Tac-Toe Logo
void xo_logo(void)
{
    printf("d888888P oo          d888888P                   d888888P                    \n");
    printf("   88                   88                         88                       \n");
    printf("   88    dP .d8888b.    88    .d8888b. .d8888b.    88    .d8888b. .d8888b.  \n");
    printf("   88    88 88'  `\"\"    88    88'  `88 88'  `\"\"    88    88'  `88 88ooood8  \n");
    printf("   88    88 88.  ...    88    88.  .88 88.  ...    88    88.  .88 88.  ...  \n");
    printf("   dP    dP `88888P'    dP    `88888P8 `88888P'    dP    `88888P' `88888P'  \n");
    printf("ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo \n");
}

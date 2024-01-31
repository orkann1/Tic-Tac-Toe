#include <stdio.h>
#include <stdlib.h>

#define R 6
#define C 7

void printBoard(char str1[2], char str2[R][C]);
int checkwin(char str2[R][C], int player);
void clearScreen();

int main()
{
    clearScreen();

    char str1[2] = {'X', 'O'};
    char str2[R][C] = {{' ', ' ', ' ', ' ',' ',' '}, {' ', ' ', ' ', ' ',' ',' '},{' ', ' ', ' ', ' ',' ',' '},{' ', ' ', ' ', ' ',' ',' '}, {' ', ' ', ' ', ' ',' ',' '}, {' ', ' ', ' ', ' ',' ',' '}};
    
    int a = 0, b = 0, player = 0;
    
    printf("--------------------------------------\n");
    printf("Rules:\n  -First you should enter the column.\n  -Then you should enter the row.\n  -It is similar to Tic Tac Toe.\n  -You should combine four X or Os.\n");
    printf("--------------------------------------\n");
    printf("Press enter to start: ");
    getchar();
    clearScreen();

    while (1)
    {
        printBoard(str1,str2);

        printf("\n     Enter row and column (R C): ");

        if (scanf("%d %d", &a, &b) != 2)
        {         
            getchar();
            
            clearScreen();
            printf("Invalid input. Please enter valid coordinates.\n");
            continue;
        }

        if (!(0 <= a-1 && a-1 < R && 0 <= b-1 && b-1 < C-1))
        {
            clearScreen();
            printf("Invalid coordinates. Please enter valid coordinates.\n");
            continue;
        }

        if(str2[a-1][b-1] == ' ')
        {
            str2[a-1][b-1] = str1[player];
            int checking = checkwin(str2, player);
            if (checking == 0)
            {
                clearScreen();
                printBoard(str1,str2);
                printf("\n\t     PLAYER %c WON!", str1[player]);
                break;
            }
            else if (checking == 2)
            {
                clearScreen();
                printBoard(str1,str2);
                printf("\n\t          Draw.");
                break;
            }

            player = (player + 1) % 2;
            clearScreen();
        }
        else
        {
            clearScreen();
            printf("Coordinate already filled.\n");
        }
    }

    return 0;
}

void printBoard(char str1[2], char str2[R][C])
{
    printf("        ----Connect Four----\n");
    printf(" ___________________________________\n");
    printf("|     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", str2[0][0],str2[0][1],str2[0][2],str2[0][3],str2[0][4],str2[0][5]);
    printf("|_____|_____|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", str2[1][0],str2[1][1],str2[1][2],str2[1][3],str2[1][4],str2[1][5]);
    printf("|_____|_____|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", str2[2][0],str2[2][1],str2[2][2],str2[2][3],str2[2][4],str2[2][5]);
    printf("|_____|_____|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", str2[3][0],str2[3][1],str2[3][2],str2[3][3],str2[3][4],str2[3][5]);
    printf("|_____|_____|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", str2[4][0],str2[4][1],str2[4][2],str2[4][3],str2[4][4],str2[4][5]);
    printf("|_____|_____|_____|_____|_____|_____|\n");
    printf("|     |     |     |     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n", str2[5][0],str2[5][1],str2[5][2],str2[5][3],str2[5][4],str2[5][5]);
    printf("|_____|_____|_____|_____|_____|_____|\n");

}

int checkwin(char str2[R][C], int player)
{
    //Horizonal
    if (str2[0][0] == str2[0][1] && str2[0][1] == str2[0][2] && str2[0][2] == str2[0][3] && str2[0][3] != ' ')
    {
        return 0;
    }
    else if (str2[0][1] == str2[0][2] && str2[0][2] == str2[0][3] && str2[0][3] == str2[0][4] && str2[0][4] != ' ')
    {
        return 0;
    }
    else if (str2[0][2] == str2[0][3] && str2[0][3] == str2[0][4] && str2[0][4] == str2[0][5] && str2[0][5] != ' ')
    {
        return 0;
    }
    else if (str2[1][0] == str2[1][1] && str2[1][1] == str2[1][2] && str2[1][2] == str2[1][3] && str2[1][3] != ' ')
    {
        return 0;
    }
    else if (str2[1][1] == str2[1][2] && str2[1][2] == str2[1][3] && str2[1][3] == str2[1][4] && str2[1][4] != ' ')
    {
        return 0;
    }
    else if (str2[1][2] == str2[1][3] && str2[1][3] == str2[1][4] && str2[1][4] == str2[1][5] && str2[1][5] != ' ')
    {
        return 0;
    }
    else if (str2[2][0] == str2[2][1] && str2[2][1] == str2[2][2] && str2[2][2] == str2[2][3] && str2[2][3] != ' ')
    {
        return 0;
    }
    else if (str2[2][1] == str2[2][2] && str2[2][2] == str2[2][3] && str2[2][3] == str2[2][4] && str2[2][4] != ' ')
    {
        return 0;
    }
    else if (str2[2][2] == str2[2][3] && str2[2][3] == str2[2][4] && str2[2][4] == str2[2][5] && str2[2][5] != ' ')
    {
        return 0;
    }
    else if (str2[3][0] == str2[3][1] && str2[3][1] == str2[3][2] && str2[3][2] == str2[3][3] && str2[3][3] != ' ')
    {
        return 0;
    }
    else if (str2[3][1] == str2[3][2] && str2[3][2] == str2[3][3] && str2[3][3] == str2[3][4] && str2[3][4] != ' ')
    {
        return 0;
    }
    else if (str2[3][2] == str2[3][3] && str2[3][3] == str2[3][4] && str2[3][4] == str2[3][5] && str2[3][5] != ' ')
    {
        return 0;
    }
    else if (str2[4][0] == str2[4][1] && str2[4][1] == str2[4][2] && str2[4][2] == str2[4][3] && str2[4][3] != ' ')
    {
        return 0;
    }
    else if (str2[4][1] == str2[4][2] && str2[4][2] == str2[4][3] && str2[4][3] == str2[4][4] && str2[4][4] != ' ')
    {
        return 0;
    }
    else if (str2[4][2] == str2[4][3] && str2[4][3] == str2[4][4] && str2[4][4] == str2[4][5] && str2[4][5] != ' ')
    {
        return 0;
    }
    else if (str2[5][0] == str2[5][1] && str2[5][1] == str2[5][2] && str2[5][2] == str2[5][3] && str2[5][3] != ' ')
    {
        return 0;
    }
    else if (str2[5][1] == str2[5][2] && str2[5][2] == str2[5][3] && str2[5][3] == str2[5][4] && str2[5][4] != ' ')
    {
        return 0;
    }
    else if (str2[5][2] == str2[5][3] && str2[5][3] == str2[5][4] && str2[5][4] == str2[5][5] && str2[5][5] != ' ')
    {
        return 0;
    }
    //Vertical
    else if (str2[0][0] == str2[1][0] && str2[1][0] == str2[2][0] && str2[2][0] == str2[3][0] && str2[3][0] != ' ')
    {
        return 0;
    }
    else if (str2[1][0] == str2[2][0] && str2[2][0] == str2[3][0] && str2[3][0] == str2[4][0] && str2[4][0] != ' ')
    {
        return 0;
    }
    else if (str2[2][0] == str2[3][0] && str2[3][0] == str2[4][0] && str2[4][0] == str2[5][0] && str2[5][0] != ' ')
    {
        return 0;
    }
    else if (str2[0][1] == str2[1][1] && str2[1][1] == str2[2][1] && str2[2][1] == str2[3][1] && str2[3][1] != ' ')
    {
        return 0;
    }
    else if (str2[1][1] == str2[2][1] && str2[2][1] == str2[3][1] && str2[3][1] == str2[4][1] && str2[4][1] != ' ')
    {
        return 0;
    }
    else if (str2[2][1] == str2[3][1] && str2[3][1] == str2[4][1] && str2[4][1] == str2[5][1] && str2[5][1] != ' ')
    {
        return 0;
    }
    else if (str2[0][2] == str2[1][2] && str2[1][2] == str2[2][2] && str2[2][2] == str2[3][2] && str2[3][2] != ' ')
    {
        return 0;
    }
    else if (str2[1][2] == str2[2][2] && str2[2][2] == str2[3][2] && str2[3][2] == str2[4][2] && str2[4][2] != ' ')
    {
        return 0;
    }
    else if (str2[2][2] == str2[3][2] && str2[3][2] == str2[4][2] && str2[4][2] == str2[5][2] && str2[5][2] != ' ')
    {
        return 0;
    }
    else if (str2[0][3] == str2[1][3] && str2[1][3] == str2[2][3] && str2[2][3] == str2[3][3] && str2[3][3] != ' ')
    {
        return 0;
    }
    else if (str2[1][3] == str2[2][3] && str2[2][3] == str2[3][3] && str2[3][3] == str2[4][3] && str2[4][3] != ' ')
    {
        return 0;
    }
    else if (str2[2][3] == str2[2][3] && str2[2][3] == str2[3][3] && str2[3][3] == str2[4][3] && str2[5][3] != ' ')
    {
        return 0;
    }
    else if (str2[0][4] == str2[1][4] && str2[1][4] == str2[2][4] && str2[2][4] == str2[3][4] && str2[3][4] != ' ')
    {
        return 0;
    }
    else if (str2[1][4] == str2[1][4] && str2[1][4] == str2[2][4] && str2[2][4] == str2[3][4] && str2[3][4] != ' ')
    {
        return 0;
    }
    else if (str2[2][4] == str2[3][4] && str2[3][4] == str2[4][4] && str2[4][4] == str2[5][4] && str2[5][4] != ' ')
    {
        return 0;
    }
    else if (str2[0][5] == str2[1][5] && str2[1][5] == str2[2][5] && str2[2][5] == str2[3][5] && str2[3][5] != ' ')
    {
        return 0;
    }
    else if (str2[1][5] == str2[2][5] && str2[2][5] == str2[3][5] && str2[3][5] == str2[4][5] && str2[4][5] != ' ')
    {
        return 0;
    }
    else if (str2[2][5] == str2[3][5] && str2[3][5] == str2[4][5] && str2[4][5] == str2[5][5] && str2[5][5] != ' ')
    {
        return 0;
    }
    //Diagonal
    else if (str2[0][0] == str2[1][1] && str2[1][1] == str2[2][2] && str2[2][2] == str2[3][3] && str2[3][3] != ' ')
    {
        return 0;
    }
    else if (str2[1][1] == str2[2][2] && str2[2][2] == str2[3][3] && str2[3][3] == str2[4][4] && str2[4][4] != ' ')
    {
        return 0;
    }
    else if (str2[2][2] == str2[3][3] && str2[3][3] == str2[4][4] && str2[4][4] == str2[5][5] && str2[5][5] != ' ')
    {
        return 0;
    }
    else if (str2[5][0] == str2[4][1] && str2[4][1] == str2[3][2] && str2[3][2] == str2[2][3] && str2[2][3] != ' ')
    {
        return 0;
    }
    else if (str2[4][1] == str2[3][2] && str2[3][2] == str2[2][3] && str2[2][3] == str2[1][4] && str2[1][4] != ' ')
    {
        return 0;
    }
    else if (str2[3][0] == str2[2][1] && str2[2][1] == str2[1][2] && str2[1][2] == str2[0][3] && str2[0][3] != ' ')
    {
        return 0;
    }
    //Small Diagonals
    else if (str2[0][2] == str2[1][3] && str2[1][3] == str2[2][4] && str2[2][4] == str2[3][5] && str2[3][5] != ' ')
    {
        return 0;
    }
    else if (str2[5][2] == str2[4][3] && str2[4][3] == str2[3][4] && str2[3][4] == str2[2][5] && str2[2][5] != ' ')
    {
        return 0;
    }
    else if (str2[2][0] == str2[3][1] && str2[3][1] == str2[4][2] && str2[4][2] == str2[5][3] && str2[5][3] != ' ')
    {
        return 0;
    }
    else if (str2[3][0] == str2[2][1] && str2[2][1] == str2[1][2] && str2[1][2] == str2[0][3] && str2[0][3] != ' ')
    {
        return 0;
    }
    //5 Diagonals
    else if (str2[4][0] == str2[3][1] && str2[3][1] == str2[2][2] && str2[2][2] == str2[1][3] && str2[1][3] != ' ')
    {
        return 0;
    }
    else if (str2[3][1] == str2[2][2] && str2[2][2] == str2[1][3] && str2[1][3] == str2[0][4] && str2[0][4] != ' ')
    {
        return 0;
    }
    //
    else if (str2[0][1] == str2[1][2] && str2[1][2] == str2[2][3] && str2[2][3] == str2[3][4] && str2[3][4] != ' ')
    {
        return 0;
    }
    else if (str2[1][2] == str2[2][3] && str2[2][3] == str2[3][4] && str2[3][4] == str2[4][5] && str2[4][5] != ' ')
    {
        return 0;
    }
    //
    else if (str2[5][1] == str2[4][2] && str2[4][2] == str2[3][3] && str2[3][3] == str2[2][4] && str2[2][4] != ' ')
    {
        return 0;
    }
    else if (str2[4][2] == str2[3][3] && str2[3][3] == str2[2][4] && str2[2][4] == str2[1][5] && str2[1][5] != ' ')
    {
        return 0;
    }
    //
    else if (str2[1][0] == str2[2][1] && str2[2][1] == str2[3][2] && str2[3][2] == str2[4][3] && str2[4][3] != ' ')
    {
        return 0;
    }
    else if (str2[2][1] == str2[3][2] && str2[3][2] == str2[4][3] && str2[4][3] == str2[5][4] && str2[5][4] != ' ')
    {
        return 0;
    }
    else 
    {
        int condition = 0;

        for (int i = 0; i < R && !condition; i++)
        {
            for (int j = 0; j < C - 1 && !condition; j++)
            {
                if (str2[i][j] == ' ')
                {
                    condition = 1;
                }
            }
        }

        if (!condition)
        {
            return 2;
        }
    }
    return 1;
}

void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
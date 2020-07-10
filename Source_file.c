//Author : Aditya Shidlyali
//Date : 05/May/2020
//Topic : TIC TAC TOE Game

/*Note : The main important thing here is the input clutter
(we should clean the input clutter everytime we take input)
Because alot of clutter is produced and the program also executes smoothly
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Functions Used
void start_game ();
void display ( char a[9] );
int check ( char *symbol, int, char );
void assign_x( char *symbol, int choice_x );
void assign_o ( char *symbol, int choice_o );
void play_again ();
//-------------------


int main () {
    start_game();
    return 0;
}


void start_game () {
    char symbol[9] = {'1','2','3','4','5','6','7','8','9'};
    display(symbol);

    int flag = 0, count = 0;
    while ( count < 9 ) {

        //Asking the choice for player X
        int choice_x;
        printf("\n\n\tEnter choice (X) : ");
        scanf("%d", &choice_x);
        assign_x ( symbol, choice_x);
        display(symbol);
        if ( check ( symbol, count, 'X' ) == 1 ) {
            play_again();
        }
        fflush(stdin); //clear the input clutter
        count++;

        //Asking the choice for player O
        int choice_o;
        printf("\n\n\tEnter choice (O) : ");
        scanf("%d", &choice_o);
        assign_o ( symbol, choice_o );
        display(symbol);
        if ( check ( symbol, count, 'O' ) == 1 ) {
            play_again();
        }
        fflush(stdin); //clear the input clutter
        count++;
    }
}


void assign_x ( char *symbol, int choice_x ) {
    while (1) {
        if ( symbol[choice_x - 1] != 'O' && symbol[choice_x - 1] != 'X' && choice_x <= 9 ) {
            symbol[choice_x - 1] = 'X';
            break; //if user enters the right input break the loop
        }
        else {
            printf("\n\tEnter valid option ! ");
            printf("\n\tPlayer X : ");
            scanf("%d", &choice_x);
        }
    }
}


void assign_o ( char *symbol, int choice_o) {
    while (1) {
        if ( symbol[choice_o - 1] != 'O' && symbol[choice_o - 1] != 'X' && choice_o <= 9 ) {
            symbol[choice_o - 1] = 'O';
            break; //if user enters the right input break the loop
        }
        else {
            printf("\n\tEnter valid option ! ");
            printf("\n\tPlayer O : ");
            scanf("%d", &choice_o);
        }
    }
}


int check ( char *symbol, int count, char ch ) {
    int i;
    for ( i = 0; i <= 6 ; i+=3 ) { // Check for the row
        if ( symbol[i] == ch && symbol[i+1] == ch && symbol[i+2] == ch ) {
            printf("  !The winner is %c!", ch);
            return 1;
        }
    }
    for ( i = 0 ; i < 3 ; i++ ) { //check for the column
        if ( symbol[i] == ch && symbol[i+3] == ch && symbol[i+6] == ch ) {
            printf("  !The winner is %c!", ch);
            return 1;
        }
    }

    //Diagonal comparison
    if ( symbol[0] == ch && symbol[4] == ch && symbol[8] == ch ) {
        printf("  !The winner is %c!", ch);
        return 1;
    }
    else if ( symbol[2] == ch && symbol[4] == ch && symbol[6] == ch ) {
        printf("  !The winner is %c!", ch);
        return 1;
    }
    else if ( count == 8 ) {
        printf("  !The game is DRAW!");
        play_again();
    }
    return 0;
}


void display( char updated_symbol[9] ) {
    system("cls");

    //Head of the game
    printf("\n\tT I C   T A C   T O E   G A M E");
    printf("\n\t-------------------------------");

    //Displaying the characters
    printf("\n\tPlayer 1 : X");
    printf("\n\tPlayer 2 : O");

    //Printing the blocks of position to get the position input by user
    printf("\n\n\t     ------|-------|------");
    printf("\n\t       %c   |   %c   |   %c", updated_symbol[0], updated_symbol[1], updated_symbol[2]);
    printf("\n\t     ------|-------|------");
    printf("\n\t       %c   |   %c   |   %c", updated_symbol[3], updated_symbol[4], updated_symbol[5]);
    printf("\n\t     ------|-------|------");
    printf("\n\t       %c   |   %c   |   %c", updated_symbol[6], updated_symbol[7], updated_symbol[8]);
    printf("\n\t     ------|-------|------");
}


void play_again() { // Check if player wants to play the game again
    char ch;
    printf("\n\n\n\tEnter 'Y' if you want to play again (or 'N' to exit): ");
    fflush(stdin); //clear the input clutter before taking the user choice
    scanf("%c", &ch);
    if (ch == 'Y' || ch == 'y') {
        start_game();
    }
    else {
        exit(0);
    }
}

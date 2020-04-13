//
// Created by Lili on 26/03/2020.
//

//
// Created by Lili on 24/03/2020.
//

#include <stdio.h>
#include "input_output.h"

/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    printf("************** The Board ****************\n");

    printf("   0    1    2    3    4    5    6    7\n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        printf(" ");
        for(int j = 0; j<BOARD_SIZE; j++){

            printf("%c%c%c%c%c", 197,196,196,196,196);
        }
        printf("%c\n",197);
        printf("%d",i);
            for (int j = 0; j < BOARD_SIZE; j++){

                if(board[i][j].type == VALID) {
                    if(board[i][j].stack == NULL)
                        printf("|    ");
                    else{
                        if (board[i][j].stack->p_colour == GREEN)
                            printf("%c%d G ",179, board[i][j].num_pieces);
                        else printf("%c%d R ",179,board[i][j].num_pieces);
                    }
                }
                else
                    printf("| -- ");
            }

            printf("|%d\n",i);

    }
    printf("   0    1    2    3    4    5    6    7\n");
}

bool first_turn() {
    int decider = rand() % 2;
    bool red_players_turn;
    if (decider == 1)
    {
        red_players_turn= true;
    }
    else
    {
        red_players_turn= false;
    }
    return red_players_turn;
}

void movement(int *coordinates, square board[BOARD_SIZE][BOARD_SIZE])
{
    printf("Coordinate:(%d,%d) can move %d spaces\n", coordinates[0],coordinates[1],board[coordinates[0]][coordinates[1]].num_pieces);
    printf("Please input where you would like the piece to move using the WASD.\n");
    printf("w = UP\n s=DOWN\n a=LEFT\n d=RIGHT\n");

    int number_of_pieces =board[coordinates[0]][coordinates[1]].num_pieces;
    printf("Number of pieces: %d\n", number_of_pieces);
    char *direction[number_of_pieces];
    int new_coordinates [2];
    new_coordinates[0]=0;
    new_coordinates[1]=0;
    //ask_direction(direction,number_of_pieces);

    check_coordinates(coordinates,number_of_pieces,new_coordinates);
    printf("HERE ARE THE NEW COORDINATES(%d,%d)\n" ,new_coordinates[0],new_coordinates[1]);
    board[new_coordinates[0]][new_coordinates[1]].num_pieces+=board[coordinates[0]][coordinates[1]].num_pieces;
    connect(&board[coordinates[0]][coordinates[1]],&board[new_coordinates[0]][new_coordinates[1]]);

    printf("\n\n\n");
    set_empty(&board[coordinates[0]][coordinates[1]]);
    
    print_board(board);
}

void check_coordinates( int coordinates[2], int number_of_pieces, int new_coordinates[2])
{

    new_coordinates[0]= coordinates[0];
    new_coordinates[1] =coordinates[1];
    int failure=0;
    char directions;

    for(int j = 0; j<number_of_pieces; j++) {
        printf("Please input a direction and then press enter:");
        while(getchar()!='\n');
        directions=getchar();
        switch (directions)
        {
            case'a' :
                new_coordinates[1] = (new_coordinates[1]) - 1;
                if(limits(new_coordinates)==1)
                {
                    failure=1;
                }
                break;
            case'd' :

                new_coordinates[1] = (new_coordinates[1]) + 1;
                if(limits(new_coordinates)==1)
                {
                    failure=1;
                }
                break;
            case'w' :
                new_coordinates[0] = (new_coordinates[0]) - 1;
                if(limits(new_coordinates)==1)
                {
                    failure=1;
                }
                break;
            case's' :
                new_coordinates[0] = (new_coordinates[0]) + 1;
                if(limits(new_coordinates)==1)
                {
                    failure=1;
                }
                break;
            default :
                failure = 1;
                break;
        }
    }
    if(failure==1)
    {
        check_coordinates(coordinates,number_of_pieces,new_coordinates);
    }
    printf("New: %d, %d", new_coordinates[0],new_coordinates[1]);
}

int limits(int coordinates[2])
{
    int out_of_bounds [12][2] = {{0,0},{0,1},{1,0},{6,0},{7,0},{7,1},{0,7},{0,6},{1,7},{6,7},{7,6},{7,7}};
    int failure=0;
    int check=0;
    if (coordinates[0] < 0 || coordinates[0] > 7) {
        check=1;
    }

    if ( coordinates[1]< 0 || coordinates[1] > 7)
    {
        if(check==1)
        {
            check=3;
        }
        else
        {
            check=2;
        }

    }
    for(int i=0;i<=12;i++)
    {
        if((out_of_bounds[i][0]==coordinates[0])&&(out_of_bounds[i][1]==coordinates[1]))
        {
            check=4;
        }
    }
    switch (check) {
        case 1:
        {
            printf("Horizontal completely out of bounds.Please try again.\n");
            failure=1;
            break;
        }
        case 2:
        {
            printf("Vertical completely out of bounds.Please try again.\n");
            failure=1;
            break;
        }
        case 3:
        {
            printf("Both coordinates are completely out of bounds. Please try again.\n");
            failure=1;
            break;
        }
        case 4:
        {
            printf("Squares with '--' are out of bounds. Please try again.\n");
            failure=1;
            break;
        }
    }
    return failure;
}
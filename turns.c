//
// Created by sarah on 04/04/2020.
//

#include "turns.h"

void turns(bool turn, player player[PLAYERS_NUM], square board[BOARD_SIZE][BOARD_SIZE])
{
    bool WIN = false;
    int stop = 1;
    while(WIN==false && stop!=0) {
        if (turn == true) {
            printf("%s : (Red Player's) turn\n", player[0].name);
        } else {
            printf("%s : (Green Player's) turn\n", player[1].name);
        }
        print_board(board);
        int coordinates[2];
        coordinates[0]=69;
        coordinates[1]=96;
        choose_coordinates(coordinates,turn,board);
        printf("Coordinates: (%d,%d)\n", coordinates[0],coordinates[1]);
        movement(coordinates,board);
        printf("Would you like to stop(0)\n");
        scanf("%d", &stop);


        turn=!turn;
    }
}

void choose_coordinates(int coordinates[2],bool turn, square board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\nPlease enter the number of the horizontal row of the stack you want to move:\n ");
    scanf("%d", &coordinates[0]);
    printf("\nPlease enter the number of the vertical column of the stack you want to move:\n ");
    scanf("%d", &coordinates[1]);
    //Checks that the index is valid.
    while(limits(coordinates)==1)
    {
        choose_coordinates(coordinates,turn,board);
    }
    check_colour(turn,board,coordinates);

}

void check_colour(bool red_turn, square board[BOARD_SIZE][BOARD_SIZE],int *coordinates)
{
    if(board[coordinates[0]][coordinates[1]].num_pieces==0)
    {
        printf("This square has no stack");
        choose_coordinates(coordinates,red_turn,board);
    }
    else if (board[coordinates[0]][coordinates[1]].stack->p_colour == GREEN)
    {
        if (red_turn == true) {
            printf("Green owns this stack. Please try again");
            choose_coordinates(coordinates, red_turn, board);
        }
    }
    else if(board[coordinates[0]][coordinates[1]].stack->p_colour == RED)
        {
            if(red_turn==false)
            {
                printf("Red owns this stack.Please try again.");
                choose_coordinates(coordinates,red_turn,board);
            }
        }

}
//
// Created by sarah on 04/04/2020.
//

#include "turns.h"


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
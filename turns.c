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
        printf("Would you like to stop(0)\n");
        scanf("%d", &stop);


        turn=!turn;
    }
}

void choose_coordinates(int *coordinates,bool turn, square board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\nPlease enter the number of the horizontal row of the stack you want to move:\n ");
    scanf("%d", &coordinates[0]);

    printf("\nPlease enter the number of the vertical column of the stack you want to move:\n ");
    scanf("%d", &coordinates[1]);
    //Checks that the index is valid.
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

    //if(((coordinates[0]>=0&& coordinates[0]<=1)||(coordinates[0]>=6&&coordinates[0]<=7))&&((coordinates[1]>=0&&coordinates[1]<=1)||(coordinates[1]>=6&&coordinates[1]<=7)))
    else if(coordinates[0]<=1||(coordinates[0]>=6)&&(coordinates[1]<=1||coordinates[1]>=6))
    {
        check=4;
    }
    switch (check) {
        case 1:
            {
                printf("Horizontal completely out of bounds.");
                choose_coordinates(coordinates,turn,board);
                break;
            }
        case 2:
            {
                printf("Vertical completely out of bounds.");
                choose_coordinates(coordinates,turn,board);
                break;
            }
        case 3:
            {
                printf("Both coordinates are completely out of bounds");
                choose_coordinates(coordinates,turn,board);
                break;
            }
        case 4:
            {
                printf("Squares with '--' are out of bounds");
                choose_coordinates(coordinates,turn,board);
                break;
            }
    }
    check_colour(turn,board,coordinates);
}

void check_colour(bool red_turn, square board[BOARD_SIZE][BOARD_SIZE],int *coordinates)
{

    if (board[coordinates[0]][coordinates[1]].stack->p_colour == GREEN)
    {
        if (red_turn == true) {
            printf("Green owns this stack. Please try again");
            choose_coordinates(coordinates, red_turn, board);
        }
    }
    else
        {
            if(red_turn==false)
            {
                printf("Red owns this stack.Please try again.");
                choose_coordinates(coordinates,red_turn,board);
            }
        }
}
//
// Created by sarah on 17/04/2020.
//
#include "movement.h"
#include "pieces.h"

void movement(int *coordinates,square board[BOARD_SIZE][BOARD_SIZE],bool red_turn,struct player players[2])
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
    check_stack(new_coordinates,board,red_turn,players);
    print_board(board);
    coordinates[0]=new_coordinates[0];
    coordinates[1]= new_coordinates[1];
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



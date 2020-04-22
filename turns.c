//
// Created by sarah on 04/04/2020.
//

#include "turns.h"
#include <string.h>
#include <stdlib.h>

//status = 0 =move      status = 1 = place
int choose_move_type(bool red_turn, struct player players[2], struct square board[BOARD_SIZE][BOARD_SIZE])
{
    //red=0 green =1
    int status;
    int player;
    if(red_turn == true)
    {
        player=0;
    } else{
        player=1;
    }
    int choose=2;//0=no 1=yes
    bool first_time=true;

    while ( choose != 0) {

        printf("Would you like to check a stack? \nType 0 for No. Type 1 for Yes\n");
        int temp; //Collects garbage characters
        int status = scanf("%d", &choose);
        //Protects against accidental character input
        while(status!=1){
            while((temp=getchar()) != EOF && temp != '\n');
            printf("Please enter a number: ");
            status = scanf("%d", &choose);
        }
        if (choose==1 ) {
            int coordinates[2];
            choose_coordinates(coordinates,red_turn,board);
            print_stack(&board[coordinates[0]][coordinates[1]]);
            }
            first_time=false;
        }


    if(players[player].placable==0 && check_board_stacks(board)==0)
    {
        printf("Currently you can only move.\nPlease enter the coordinates of the piece you wish to move.\n");
        status=0;
    }
    else if(players[player].placable>0 && check_board_stacks(board)==0)
    {
        char decision[7];
        getchar();//Cleans any buffer
        while(strcmp(decision,"MOVE\0")!=0 && strcmp(decision,"PLACE\0")!=0 && strcmp(decision,"CHECK\0")!=0) {
            printf("You can move or place a piece or check a stack. Type MOVE or type PLACE or CHECK then press enter.\n");
            fgets(decision,7,stdin);
            int newline = strcspn(decision,"\n");
            decision[newline]='\0';
        }
        if(strcmp(decision,"MOVE")==0)
        {
            status=0;
        } else if(strcmp(decision,"PLACE")==0){
            status = 1;
        } else
        {
            int coordinates[2];
            choose_coordinates(coordinates,red_turn,board);
            printf("It is this stack:");
            status=choose_move_type(red_turn,players,board);
        }
    } else if (players[player].placable>0 && check_board_stacks(board)==1)
    {
        printf("Currently you can only place pieces.\n Please enter the coordinate of where you would like to place a piece.\n");
        status=1;
    } else{
        printf("ERROR!");
    }
    return status;
}

//bool colour asks if colour should be checked.
void choose_coordinates(int coordinates[2],bool turn, square board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\nPlease enter the number of the horizontal row of the square you wish to select:\n ");
    int temp; //Collects garbage characters
    int status = scanf("%d", &coordinates[0]);
    //Protects against accidental character input
    while(status!=1){
        while((temp=getchar()) != EOF && temp != '\n');
        printf("Please enter a number: ");
        status = scanf("%d", &coordinates[0]);
    }

    printf("\nPlease enter the number of the vertical column of the square you wish to select:\n ");
    int temp1; //Collects garbage characters
    int status1 = scanf("%d", &coordinates[1]);
    //Protects against accidental character input
    while(status1!=1){
        while((temp1=getchar()) != EOF && temp1 != '\n');
        printf("Please enter a number: ");
        status1 = scanf("%d", &coordinates[1]);
    }


    //Checks that the index is valid.
    while(limits(coordinates)==1)
    {
        choose_coordinates(coordinates,turn,board);
    }
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
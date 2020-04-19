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



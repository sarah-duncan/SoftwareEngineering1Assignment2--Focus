//
// Created by sarah on 19/04/2020.
//

#include "win.h"

int win_condition(square board[BOARD_SIZE][BOARD_SIZE],struct player players[2],bool red_turn)
{
    int player;
    if(red_turn==true)
    {
        player=0;
    } else{
        player=1;
    }
    int left=check_board_stacks(board);
    if(left==1 && players[player].placable==0)
    {
        return 1;
    }
    else {
    return 0;
    }
}
//0 no winner. 1 winner
int check_board_stacks(square board[BOARD_SIZE][BOARD_SIZE])
{
    bool red_there= false;
    bool green_there= false;
    for(int i=0; i<BOARD_SIZE; i++)
    {
        for(int j=0; j<BOARD_SIZE; j++)
        {
            if(&board[i][j].stack->p_colour == RED)
            {
                red_there= true;
            }
            else if (board[i][j].stack->p_colour == GREEN)
            {
                green_there = true;
            }
            if(red_there==true && green_there==true)
            {
                return 0;
            }
        }
    }
    return 1;
}
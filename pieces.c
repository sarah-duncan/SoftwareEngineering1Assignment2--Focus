//
// Created by sarah on 17/04/2020.
//

#include "pieces.h"

void check_stack(int *coordinates, square board[BOARD_SIZE][BOARD_SIZE], bool red_turn, player players[PLAYERS_NUM])
{

    while(board[coordinates[0]][coordinates[1]].num_pieces>5)
    {
        piece_node_ptr previous_piece;
        piece_node_ptr current_piece = board[coordinates[0]][coordinates[1]].stack;
        while(current_piece->next!=NULL)
       {
            previous_piece = current_piece;
            current_piece = current_piece->next;
        }
       colour *removing = &current_piece->p_colour;
       if(red_turn==true)
       {
            if(current_piece->p_colour==RED)
            {
                players[0].placable++;
            } else
            {
                players[1].captured++;
            }
       } else
       {
           if(current_piece->p_colour==GREEN)
           {
               players[1].placable++;
           } else
           {
               players[0].captured++;
           }
       }
       previous_piece->next=NULL;
        board[coordinates[0]][coordinates[1]].num_pieces--;
    }
}

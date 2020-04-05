//
// Created by Lili on 26/03/2020.
//

#include <stdio.h>


#include "turns.h"

int main() {
    srand(time(0));
    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);



    bool turn = first_turn();
    if(turn == true)
    {
        printf("%s, the red player, goes first!\n", players[0].name);
    }
    else
    {
        printf("%s, the green player, goes first!\n", players[1].name);
    }
    turns(turn,players,board);

    return 0;
}

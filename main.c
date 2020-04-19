//
// Created by Lili on 26/03/2020.
//

#include <stdio.h>


#include "turns.h"
#include "movement.h"
#include "pieces.h"

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

    //turns(turn,players,board);
    bool WIN = false;
    int stop = 1;
    while(WIN==false && stop!=0) {
        if (turn == true) {
            printf("%s : (Red Player's) turn\n", players[0].name);
        } else {
            printf("%s : (Green Player's) turn\n", players[1].name);
        }
        print_board(board);
        int coordinates[2];
        coordinates[0]=69;
        coordinates[1]=96;
        choose_coordinates(coordinates,turn,board);
        printf("Coordinates: (%d,%d)\n", coordinates[0],coordinates[1]);
        movement(coordinates,board,turn,players);
        //check_stack(coordinates,board,turn,players);
        printf("Lost Pieces:\n Red Player: %d\t Green Player:%d\n", players[0].captured,players[1].captured);
        printf("Reserved:\n Red Player: %d\t Green Player:%d\n",players[0].placable,players[1].placable);
        printf("Would you like to stop(0)\n");
        scanf("%d", &stop);
        turn=!turn;
    }
    return 0;
}

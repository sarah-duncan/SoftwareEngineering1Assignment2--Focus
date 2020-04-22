//
// Created by sarah on 17/04/2020.
//

#ifndef FOCUS_MOVEMENT_H
#define FOCUS_MOVEMENT_H

#endif //FOCUS_MOVEMENT_H

#include <stdio.h>
#include "turns.h"
#include "pieces.h"


void movement(int *coordinates, square board[BOARD_SIZE][BOARD_SIZE], bool red_turn, struct player players[2]);
void place(int *coordinates, square board[BOARD_SIZE][BOARD_SIZE], bool red_turn, struct player players[2]);
void check_coordinates(int coordinates[2], int number_of_pieces, int new_coordinates[2]);
int limits(int coordinates[2]);


//
// Created by Lili on 24/03/2020.
//

#ifndef FOCUS_INPUT_OUTPUT_H
#define FOCUS_INPUT_OUTPUT_H

#endif //FOCUS_INPUT_OUTPUT_H

#include "turns.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


//Function to print the board
void print_board(square board[BOARD_SIZE][BOARD_SIZE]);


//Function to choose who goes first
bool first_turn();
//Runs each turn

//
// Created by sarah on 04/04/2020.
//
//Contains all functions used in the function turns except for input/output to the console

#ifndef FOCUS_TURNS_H
#define FOCUS_TURNS_H

#include <stdio.h>
#include <stdbool.h>
#include "game_init.h"
#include "input_output.h"
#include "pieces.h"
#include "movement.h"
#endif //FOCUS_TURNS_H

void choose_coordinates(int *coordinates,bool turn, struct square[BOARD_SIZE][BOARD_SIZE]);

void check_colour(bool red_turn, square board[BOARD_SIZE][BOARD_SIZE],int *coordinates);
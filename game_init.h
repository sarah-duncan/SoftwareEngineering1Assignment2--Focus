//
// Created by Lili on 24/03/2020.
//

#ifndef FOCUS_GAME_INIT_H
#define FOCUS_GAME_INIT_H

#endif //FOCUS_GAME_INIT_H


#define BOARD_SIZE 8
#define PLAYERS_NUM 2

//colours that a piece can have
typedef enum colour{
    RED,
    GREEN,
    EMPTY
}colour;

// Square types
//INVALID: squares that are on the sides and where no piece can be placed
//VALID: squares where it is possible to place a piece or a stack
typedef enum square_type {
    VALID,
    INVALID
}square_type;

//Player
typedef struct player{
    //the colour associated with the player
    colour player_colour;
    char name[30];
    int captured;
    int placable;
    /*
     * A player should also be characterized by:
     * name,
     * number of adversary's pieces captured,
     * number of own pieces kept.
     *
    */

}player;

// A piece
typedef struct piece {
    //the colour associated with a piece
    colour p_colour;

    // This is a pointer to the next pieces
    // to create a stack. For this lab you do not have to think too much about it.
    struct piece * next;

}piece;

typedef struct piece *piece_node_ptr;
// A Square of the board
typedef struct square {
    // type of the square (VALID/INVALID)
    square_type type;

    //the piece or the top piece on the stack
    piece *stack;

    //number of pieces on the square
    int num_pieces;

}square;

//Function to create the players
void initialize_players(player players[PLAYERS_NUM]);

//Function to create the board
void initialize_board(square board[BOARD_SIZE][BOARD_SIZE]);

void set_empty(square * s);
void set_red(square * s);
void set_green(square * s);

void connect(square *s, square *t);

void  connecting_stacks(piece_node_ptr *s_stack, square *t);

void print_stack(square *s);


//
// Created by Lili on 26/03/2020.
//

//
// Created by Lili on 24/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_init.h"


void initialize_players(player players[PLAYERS_NUM]){

    // implement here the functionality to initialize the players
    printf("Red Player: Please enter your name:");
    players[0].player_colour=RED;
    fgets(players[0].name,30,stdin);
    int newline = strcspn(players[0].name,"\n");
    printf("NEWLINE: %d",newline);
    players[0].name[newline]='\0';
    players[0].captured = 0;
    players[0].placable = 0;

    printf("\nGreen Player: Please enter your name:");
    players[1].player_colour=GREEN;
    fgets(players[1].name,30,stdin);
    int newline2 = strcspn(players[1].name,"\n");
    printf("NEWLINE: %d\n",newline2);
    players[1].name[newline2]='\0';
    players[1].captured = 0;
    players[1].placable = 0;
}

//Set Invalid Squares (where it is not possible to place stacks)
void set_invalid(square * s){
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
void set_empty(square * s){
s->type = VALID;
s->stack = NULL;
//Allows for empty squares on the board
//s->stack->p_colour = EMPTY;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
void set_green(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_colour = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
void set_red(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_colour = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}
//s=old t=new
void connect(square *s, square *t)
{
    connecting_stacks(&s->stack,t);
    print_stack(t);
}
void  connecting_stacks(piece_node_ptr *s_stack, square *t)
{
    piece_node_ptr current_piece = *s_stack;
    colour *new_colour = &current_piece->p_colour;
    colour new = *new_colour;
    current_piece = current_piece->next;
    if(current_piece!=NULL)
    {
        connecting_stacks(&current_piece, t);
    }
    piece_node_ptr new_piece = malloc(sizeof(piece));
    if(new_piece!=NULL)
    {
        //new_piece->p_colour = current_piece->p_colour;

        new_piece->p_colour= new;
        new_piece->next = t->stack;
        t->stack=new_piece;
    }
}
void print_stack(square *s)
{
    square temp;
    temp = *s;
    int num = temp.num_pieces;
    printf("num=%d",num);
    printf("Stack:\n");
    while(temp.stack!=NULL)
    {
        switch(temp.stack->p_colour) {
            case RED: printf("RED--> ");
                break;
            case GREEN: printf("GREEN--> ");
                break;
            default:
                printf("Failure");
        }
        temp.stack=temp.stack->next;
    }
}


//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){

    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }

    }


}

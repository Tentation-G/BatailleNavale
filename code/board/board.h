#ifndef BOARD_H
#define BOARD_H

#include "../types/game_types.h"

char** build_board(Board *board);
void print_board(char **tab, const Board *board);
char checkCase(char** tab, int ligne, int colonne);

#endif // BOARD_H
#include <stdio.h>
#include "game.h"
#include "../input/input.h"
#include "../board/board.h"

int hitBoat(char **tab, Board *board) {
    int x, y; // coord user
    askUserForCoords(&x, &y);

    char laCase = checkCase(tab, y, x);

    if (laCase == 'B') {
        tab[y][x] = 'T';
        printf("Touche en %c%d !\n", 'A' + (x - 1), y);
        return 1; // touché
    } else {
        tab[y][x] = 'X';
        printf("Rate en %c%d !\n", 'A' + (x - 1), y);
        return 0; // raté
    }
}
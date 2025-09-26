#include <stdio.h>
#include <stdlib.h>
#include "types/game_types.h"
#include "board/board.h"
#include "game/game.h"

int main(void) {

    Boat bateau1 = {
        .position = {'C', '5'},
        .length = 5,
        .orientation = G,
        .hit = 0,
        .sunk = 0,
    };

    Board joueur1 = {
        .largeur = 10,
        .hauteur = 10,
        .screen = 0,
        .joueur = 1,
        .boat = &bateau1
    };

    char **tab = build_board(&joueur1);

    //Bateau 1
    tab[5][3] = 'B'; // un bateau en C5
    tab[6][3] = 'B'; // un bateau en C6
    tab[7][3] = 'B'; // un bateau en C7
    tab[8][3] = 'B'; // un bateau en C8
    tab[9][3] = 'B'; // un bateau en C9

    //Bateau 2

    int countFoireux = 0;

    while (countFoireux != 6) {
        printf(" ==============================\n");
        printf(" ==Le jeu du bateau qui coule==\n");
        printf(" ==============================\n");

        //print la board du joueur1 (pendant un moment on pensait pouvoir faire deux joueurs)
        print_board(tab, &joueur1);
        //regarde si les coord de l'inputjoueur touche quelque chose
        hitBoat(tab, &joueur1);
        //oui
        countFoireux++;
    }

    //ca nous sort un score tout a faire basé sur la performance du joueur du jeu videal
    printf(" ==============================\n");
    printf(" = Victoire !  score : TipTop =\n");
    printf(" ==============================\n");

    return 0;
}
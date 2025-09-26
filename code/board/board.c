#include <stdio.h>
#include <stdlib.h>
#include "board.h"

char** build_board(Board *board) {
    int largeur = board->largeur + 1;
    int hauteur = board->hauteur + 1;

    // Allocation de la grille + init toute les cases a '.'
    char **tab = malloc(hauteur * sizeof(char *));
    for (int i = 0; i < hauteur; i++) {
        tab[i] = malloc(largeur * sizeof(char));
        for (int j = 0; j < largeur; j++) {
            tab[i][j] = '.';
        }
    }

    // Coin vide
    tab[0][0] = ' ';

    // Entêtes colonnes (A, B, C, ect..)
    for (int j = 1; j < largeur; j++) {
        tab[0][j] = 'A' + (j - 1);
    }

    // Entêtes lignes (1, 2, …, D(10))
    for (int i = 1; i < hauteur; i++) {
        if (i < 10) {
            tab[i][0] = '0' + i;  // '1' à '9'
        } else {
            tab[i][0] = 'D';      // D pour 10
        }
    }

    return tab;
}

// Affichage de truand de la galere
void print_board(char **tab, const Board *board) {
    int largeur = board->largeur + 1;
    int hauteur = board->hauteur + 1;

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            printf("%c  ", tab[i][j]);
        }
        printf("\n");
    }
}

char checkCase(char** tab, int ligne, int colonne) {
    return tab[ligne][colonne];
}
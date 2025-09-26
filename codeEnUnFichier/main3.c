#include <stdio.h>
#include <stdlib.h>


typedef struct Position {
    int x;
    int y;
} Position;

typedef enum BoatOrientation {
    G, //Gauche
    D, //Droite
    H, //Haut
    B, //Bas
} BoatOrientation;

typedef struct Boat {
    Position position;
    int length;
    int orientation;
    int hit;
    int sunk;
} Boat;

typedef struct Board {
    int largeur;
    int hauteur;
    short screen; // 0 ecran bateau du joueur | 1 ecran attaque joueur
    short joueur; // 1 joueur1 | 2 joueur 2
    Boat* boat;
} Board;


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

void askUserForCoords(int *x, int *y) {
    char lettre;
    int chiffre;

    // Pour la lettre (X)
    do {
        printf("Entrez une lettre (A-J) : ");
        scanf(" %c", &lettre);

        // Convertir minuscule en majuscule
        if (lettre >= 'a' && lettre <= 'z') {
            lettre = lettre - 32;  // ASCII : 'a' - 'A' = 32
        }

        if (lettre < 'A' || lettre > 'J') {
            printf("Erreur ! Lettre invalide.\n");
        }

    } while (lettre < 'A' || lettre > 'J');

    // Conversion directe en int (A=1, B=2, ..., J=10)
    *x = (lettre - 'A') + 1;

    // Pour le chiffre (Y)
    do {
        printf("Entrez un chiffre (1-10) : ");
        scanf("%d", &chiffre);

        if (chiffre < 1 || chiffre > 10) {
            printf("Erreur ! Chiffre invalide.\n");
        }

    } while (chiffre < 1 || chiffre > 10);

    *y = chiffre; // On stocke directement dans le pointeur
}

char checkCase(char** tab, int ligne, int colonne) {
    return tab[ligne][colonne];
}

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


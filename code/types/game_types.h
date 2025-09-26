#ifndef GAME_TYPES_H
#define GAME_TYPES_H

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

#endif // GAME_TYPES_H
#include <stdio.h>
#include "input.h"

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
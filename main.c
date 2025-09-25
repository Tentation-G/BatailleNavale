#include <stdio.h>
#include <stdlib.h>

int main() {
    int largeur = 11;
    int hauteur = 11;


    char **tab=malloc(sizeof(char*)*hauteur+1);
    for (int i = 0; i < hauteur; i++) {
        tab[i]=malloc(sizeof(char)*largeur);
        for (int j = 0; j < largeur; j++) {
            tab[i][j] =  '.';

            tab[0][0] = ' ';




        }

    }

    tab[0][1] = 'A';
    tab[0][2] = 'B';
    tab[0][3] = 'C';
    tab[0][4] = 'D';
    tab[0][5] = 'E';
    tab[0][6] = 'F';
    tab[0][7] = 'G';
    tab[0][8] = 'H';
    tab[0][9] = 'I';
    tab[0][10] = 'J';


    tab[1][0] = '1';
    tab[2][0] = '2';
    tab[3][0] = '3';
    tab[4][0] = '4';
    tab[5][0] = '5';
    tab[6][0] = '6';
    tab[7][0] = '7';
    tab[8][0] = '8';
    tab[9][0] = '9';
    tab[10][0] = 'D';

    //affichage
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            printf("%c  ", tab[i][j]);
        }
        printf("\n");
    }
return 0;
}
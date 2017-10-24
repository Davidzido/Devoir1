/* Tictactoe.h

*
*  Created on:
Oct 3, 2017
*      Author:
David-Gabriel Verrette et Antoine Fortin
*/
#ifndef TICTACTOE_H_
#define TICTACTOE_H_
#include <stdio.h>
#include <string.h>

/*Déclarations de variables globales*/
int i, j;
int tour = 1;
int partie;
int winsJ1;
int winsJ2;
char nomJ1[25];
char nomJ2[25];
int nbMax;
const char JOUEUR1 = 'X';
const char JOUEUR2 = 'O';
int choixJoueur = 0;
char tab[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };

struct Joueur
{
    char nom[25];
    unsigned int score;
};
struct Joueur joueur[3];

/*Déclarations des méthodes*/
void imprimer();
void initialiserManche();
void initialiserPartie();
void finDePartie();
void remplirTab();
void quiCommence();
void scoreManche();
void modifPal();
char aQuiLeTour();
int gagnantPartie();
int egalite();
int lirePal();


#endif /* TICTACTOE_H_ */

/*
 * Tictactoe.c
 *
 *  Created on: Oct 3, 2017
 *      Author: David-Gabriel Verrette et Antoine Fortin
 */

#include "Tictactoe.h"

/*Affiche le tableau de jeu*/
void imprimer() {
	printf("\n");
	printf(" %c | %c | %c\n", tab[0][0], tab[0][1], tab[0][2]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", tab[1][0], tab[1][1], tab[1][2]);
	printf("-----------\n");
	printf(" %c | %c | %c\n", tab[2][0], tab[2][1], tab[2][2]);
}
/*Détermine c'est à qui à commencer la partie*/
void quiCommence() {
	if (partie % 2 != 0 && partie > 1) {
		tour--;
	}
	if (partie % 2 == 0) {
		printf("\nC'est au tour du JOUEUR 2 de commencer");
		tour++;
	}
}
/*Détermine c'est à qui à joueur son tour*/
char aQuiLeTour() {
	if (tour % 2 == 0)
		return JOUEUR2;
	else
		return JOUEUR1;
}
/*Vérifie si un joueur à gagner la partie*/
int gagnantPartie() {
	for (i = 0; i < 3; i++) {
		// Vérifie les rangées.
		if (tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]
				&& (tab[i][0] == JOUEUR1 || tab[i][0] == JOUEUR2)) {
			return 1;
		}
		// Vérifie les colonnes.
		if (tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]
				&& (tab[0][i] == JOUEUR1 || tab[0][i] == JOUEUR2)) {
			return 1;
		}
		// Vérifie la diagonale du bas à gauche vers le haut à droite du
		// tableau.
		if (tab[2][0] == tab[1][1] && tab[1][1] == tab[0][2]
				&& (tab[2][0] == JOUEUR1 || tab[2][0] == JOUEUR2)) {
			return 1;
		}
		// Vérifie la diagonale du bas à droite vers le haut à gauche du
		// tableau.
		if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]
				&& (tab[0][0] == JOUEUR1 || tab[0][0] == JOUEUR2)) {
			return 1;
		}

	}
	return 0;
}
/*Vérifie s'il y a égalité dans une partie*/
int egalite() {
	if (gagnantPartie() == 0 && tab[0][0] != '1' && tab[0][1] != '2'
			&& tab[0][2] != '3' && tab[1][0] != '4' && tab[1][1] != '5'
			&& tab[1][2] != '6' && tab[2][0] != '7' && tab[2][1] != '8'
			&& tab[2][2] != '9') {
		return 1;
	}
	return 0;
}
/*Permet de réinitialiser le tableau de jeu après une partie*/
void remplirTab() {
	char n = '1';
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			tab[i][j] = n;
			n++;
		}
	}
}
/*Permet de jouer au Tictactoe*/
void initialiserJeu() {
	printf("Bienvenue au Jeu Tic-Tac-Toe !\n");
	printf("Le JOUEUR 1 joue les X et le JOUEUR 2 joue les O\n");
	initialiserManche();
}
/*Permet d'initialiser une manche de tictactoe comprenant un nombre nbMax de parties*/
void initialiserManche() {
	printf("JOUEUR 1 entrer votre nom (max. 24 caractères):");
	scanf("%24s", nomJ1);
	printf("JOUEUR 2 entrer votre nom (max. 24 caractères):");
	scanf("%24s", nomJ2);
	do {
		printf(
				"Entrer le nombre de parties dans une manche que vous voulez jouer (nombre impaire):");
		scanf("%d", &nbMax);
	} while (nbMax % 2 == 0);
	for (partie = 1; partie <= nbMax; partie++) {
		printf("\n\nDébut de la partie #%d:\n", partie);
		remplirTab();
		initialiserPartie();
		if ((winsJ1 == nbMax / 2 + 1) || winsJ2 == nbMax / 2 + 1) {
			break;
		}
	}
	scoreManche();
}
/*Permet de jouer une partie de Tictactoe*/
void initialiserPartie() {
	imprimer();
	quiCommence();
	do {
		printf("\nVeuillez choisir une case parmi les 9 suivantes:");
		scanf("%d", &choixJoueur);
		if (choixJoueur > 0 && choixJoueur < 10) {
			choixJoueur--;
			if (tab[choixJoueur / 3][choixJoueur % 3] != 'X'
					&& tab[choixJoueur / 3][choixJoueur % 3] != 'O') {
				tab[choixJoueur / 3][choixJoueur % 3] = aQuiLeTour();
				imprimer();
				tour++;
			}
		}
	} while (gagnantPartie() == 0 && egalite() == 0);
	finDePartie();
}
/*Vérifie s'il y a un gagnant ou une égalité à la fin d'une partie*/
void finDePartie() {
	tour--;
	if (gagnantPartie() == 1) {
		if (aQuiLeTour() == JOUEUR1) {
			printf("Le JOUEUR 1 a gagné la partie !");
			winsJ1++;
		} else if (aQuiLeTour() == JOUEUR2) {
			printf("Le JOUEUR 2 a gagné la partie !");
			winsJ2++;
		}
	}
	if (egalite() == 1) {
		printf("Égalité !");
		winsJ1++;
		winsJ2++;
	}
}
/*Affiche le score de la manche*/
void scoreManche() {
	printf("\nLa manche c'est terminée %d-%d pour les %c", winsJ1, winsJ2,
			aQuiLeTour());
}
int main() {
	setbuf(stdout, NULL);
	initialiserJeu();
	return 0;
}

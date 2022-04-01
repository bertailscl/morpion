#ifndef MORPION_H
#define MORPION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define ERREUR_ALLOCATION 0
#define ERREUR_JEU 1
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[37m"
#define EGALITE "\033[33m"



/*!
	*	\struct typedef struct grille;
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief stock la grille de jeu et sa taille
*/
typedef struct
{
  char** grilleJeu;
  int taille;
}grille;



/*!
	*	\struct typedef struct coord;
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief stock les coordonnees de la case choisie
*/
typedef struct
{
  int x;
  int y;
}coord;



/*!
	*	\struct typedef struct verif;
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief stock les resultats des verifications pour la victoire
*/
typedef struct
{
	int diagonales;
	int ligneColonnes;
	int continuer;
}verif;


#include "ia.h"


/*!
	*	\fn int verificationSaisieMenu(void);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief verifie que le choix du joueur est correct quand il choisi le mode de jeu
	*	\return int nb
*/
int verificationSaisieMenu(void);



/*!
	*	\fn grille creationGrille(grille morpion);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief creer la grille de jeu
	*	\param grille morpion
	*	\return grille morpion
*/
grille creationGrille(grille morpion);



/*!
	*	\fn void afficherGrille (grille morpion);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief afficher la grille de jeu
	*	\param grille morpion
*/
void afficherGrille (grille morpion);



/*!
	*	\fn int verificationSaisie(void);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief verifie que la ligne/colonne existe quand le joueur saisie la case ou jouer
	*	\return un nombre correspondant a une saisie valide du joueur
*/
int saisieCase(void);



/*!
	*	\fn grille tourJoueur (grille morpion, int joueur);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief tour du joueur
	*	\param grille morpion
	*	\param int joueur
	*	\return grille morpion
*/
grille tourJoueur (grille morpion, int joueur);



/*!
	*	\fn int verificationEmplacement(coord caseJeu, grille morpion);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief Permet de verifier si l emplacement choisi est vide ou non
	*	\param coord caseJeu
	*	\param grille morpion
	*	\return int continuer
*/
int verificationEmplacement(coord caseJeu, grille morpion);



/*!
	*	\fn grille tourOrdiAleatoire (grille morpion);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief permet de faire jouer l ordi aleatoirement
	*	\param grille morpion
	*	\return grille morpion
*/
grille tourOrdiAleatoire (grille morpion);



/*!
	*	\fn int verificationDiagonale(grille morpion);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief permet de verifier si une diagonale accorde la victoire a un joueur
	*	\param grille morpion
	*	\return int gagner
*/
int verificationDiagonale(grille morpion);



/*!
	*	\fn int verificationLigneColonne(grille morpion);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief permet de verifier si une ligne/colonne accorde la victoire a un joueur
	*	\param grille morpion
	*	\return int gagner
*/
int verificationLigneColonne(grille morpion);



/*!
	*	\fn void joueurVSjoueur(void);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief permet de faire jouer les joueurs tours a tours et d arreter le jeu si besoin
*/
void joueurVSjoueur(void);



/*!
	*	\fn void joueurVSiaAleatoire(void);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief permet de faire jouer le joueurs et l ia tours a tours et d arreter le jeu si besoin
*/
void joueurVSiaAleatoire(void);



/*!
	*	\fn grille tourJoueurIaAleatoire(grille morpion, int joueur);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief determine si le joueur doit jouer ou si l ia doit jouer
	*	\param grille morpion
	*	\param int joueur
	*	\return grille morpion
*/
grille tourJoueurIaAleatoire(grille morpion, int joueur);



/*!
	*	\fn verif verifier(int n, grille morpion);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief permet d effectuer toute les verifications de victoire
	*	\param int n
	*	\param grille morpion
	*	\return verif verifications
*/
verif verifier(int n, grille morpion);



/*!
	*	\fn void joueurVSia(void);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief permet de faire jouer le joueurs et l ia tours a tours et d arreter le jeu si besoin
*/
void joueurVSia(void);



/*!
	*	\fn grille tourJoueurIa(grille morpion, int joueur, int tour);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief determine si le joueur doit jouer ou si l ia doit jouer
	*	\param grille morpion
	*	\param int joueur
	*	\return grille morpion
*/
grille tourJoueurIa(grille morpion, int joueur, int tour);
#endif

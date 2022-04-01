#ifndef IA_H
#define IA_H
#include "morpion.h"

coord verifAttaqueDefenceDiago(grille morpion);

coord verifAttaqueDefenceLignes(grille morpion, coord retour);

coord verifAttaqueDefenceColonnes (grille morpion, coord retour);

coord verifLigne(grille morpion, int ligne);

coord verifColonne(grille morpion, int colonne);

coord verifDiagoGD(grille morpion);

coord verifDiagoDG(grille morpion);

// /*
// Designations du retour de verifAttaqueDefence :
// x :
//   1 - diagonale
//   2 - ligne
//   3 - colonne
// y :
//   si en diagonale :
//     1 - Haut gauche > Bas droite (diagoGD)
//     2 - Haut droite > Bas gauche (diagoDG)
//   si en ligne/colonne :
//       nb2 - index de la ligne / colonne
// */

coord verifAttaqueDefence(grille morpion);

coord trouverCaseDiago(grille morpion, coord retour);

coord trouverCaseLigneColonnes(grille morpion, coord retour);

coord trouverCase(grille morpion, coord retour);

coord trouverAngleLibre(grille morpion);

coord trouverBordLibre(grille morpion, int milieu);


/*!
	*	\fn grille tourIA(grille morpion, int tour);
	*	\author Bertails Clément <bertailscl@eisti.eu>
	*	\version 1
	*	\date 13 fevrier 2020
	*	\brief
	*	\param
	*	\return
*/
grille tourIA(grille morpion, int tour);

#endif
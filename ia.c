#include "ia.h"

coord verifAttaqueDefenceDiago(grille morpion)
{
	coord retour;
	coord diagoGD = verifDiagoGD(morpion);
	coord diagoDG = verifDiagoDG(morpion);
	retour.x = 0;
	retour.y = 0;

	if ( (diagoGD.x == morpion.taille-1 && diagoGD.y == 0) || (diagoGD.x == 0 && diagoGD.y == morpion.taille-1))
	{
		retour.x = 1;
		retour.y = 1;
	}
	else if ((diagoDG.x == morpion.taille-1 && diagoDG.y == 0) || (diagoDG.x == 0 && diagoDG.y == morpion.taille-1))
	{
		retour.x = 1;
		retour.y = 2;
 	}
 	return retour;
}

coord verifAttaqueDefenceLignes(grille morpion, coord retour)
{
	coord ligne;
	for (int i = 0; i < morpion.taille; i++)
	{
		ligne = verifLigne(morpion, i);
		if ( ((ligne.x + ligne.y) == morpion.taille-1) && (ligne.x == 0 || ligne.y == 0))
		{
			retour.x = 2;
			retour.y = i;
		}
	}
	return retour;
}

coord verifAttaqueDefenceColonnes (grille morpion, coord retour)
{
	coord colonne;
	for (int i = 0; i < morpion.taille; i++)
	{
		colonne = verifColonne(morpion, i);
		if (((colonne.x + colonne.y) == morpion.taille-1) && (colonne.x == 0 || colonne.y == 0))
		{
			retour.x = 3;
			retour.y = i;
		}
	}
	return retour;
}

coord verifLigne(grille morpion, int ligne)
{
	coord retour;
	retour.x = 0;
	retour.y = 0;
	for (int i = 0; i < morpion.taille; ++i)
	{
		if (morpion.grilleJeu[ligne][i] == 'X')
		{
			retour.x++;
		}
		else if (morpion.grilleJeu[ligne][i] == 'O')
		{
			retour.y++;
		}
	}
	return retour;
}

coord verifColonne(grille morpion, int colonne)
{
	coord retour;
	retour.x = 0;
	retour.y = 0;
	for (int i = 0; i < morpion.taille; ++i)
	{
		if (morpion.grilleJeu[i][colonne] == 'X')
		{
			retour.x++;
		}
		else if (morpion.grilleJeu[i][colonne] == 'O')
		{
			retour.y++;
		}
	}
	return retour;
}

coord verifDiagoGD(grille morpion)
{
	coord retour;
	retour.x = 0;
	retour.y = 0;
	for (int i = 0; i < morpion.taille; ++i)
	{
		if (morpion.grilleJeu[i][i] == 'X')
		{
			retour.x++;
		}
		else if (morpion.grilleJeu[i][i] == 'O')
		{
			retour.y++;
		}
	}
	return retour;
}

coord verifDiagoDG(grille morpion)
{
	coord retour;
	retour.x = 0;
	retour.y = 0;
	for (int i = 0; i < morpion.taille; ++i)
	{
		if (morpion.grilleJeu[i][morpion.taille-1-i] == 'X')
		{
			retour.x++;
		}
		else if (morpion.grilleJeu[i][morpion.taille-1-i] == 'O')
		{
			retour.y++;
		}
	}
	return retour;
}

coord verifAttaqueDefence(grille morpion)
{
	coord retour;
	retour = verifAttaqueDefenceDiago(morpion);
	retour = verifAttaqueDefenceLignes(morpion, retour);
	retour = verifAttaqueDefenceColonnes(morpion, retour);
	return retour;
}

coord trouverCaseDiago(grille morpion, coord retour)
{
	coord coordonnes;
	if (retour.x == 1) // su diagoGD : chercher case vide
	{
		for (int i = 0; i < morpion.taille; ++i)
		{
			if (morpion.grilleJeu[i][i] != 'X' && morpion.grilleJeu[i][i] != 'O')
			{
				coordonnes.x = i;
				coordonnes.y = i;
			}
		}
	}
	else // sinon dans diagoDG : chercher case vide
	{
		for (int i = 0; i < morpion.taille; ++i)
		{
			if (morpion.grilleJeu[i][morpion.taille-1-i] != 'X' && morpion.grilleJeu[i][morpion.taille-1-i] != 'O')
			{
				coordonnes.x = i;
				coordonnes.y = morpion.taille-1-i;
			}
		}
	}
	return coordonnes;
}

coord trouverCaseLigneColonnes(grille morpion, coord retour)
{
	coord coordonnes;
	if (retour.x == 2)
	{
		for (int i = 0; i < morpion.taille; ++i)
		{
			if (morpion.grilleJeu[retour.x][i] != 'X' && morpion.grilleJeu[retour.y][i] != 'O')
			{
				coordonnes.x = retour.y;
				coordonnes.y = i;
			}
		}
	}
	else
	{
		for (int i = 0; i < morpion.taille; ++i)
		{
			if (morpion.grilleJeu[i][retour.y] != 'X' && morpion.grilleJeu[i][retour.y] != 'O')
			{
				coordonnes.x = i;
				coordonnes.y = retour.y;
			}
		}
	}
	return coordonnes;
}

coord trouverCase(grille morpion, coord retour)
{
	coord coordonnes;
	coordonnes.x = 0;
	coordonnes.y = 0;
	if (retour.x == 1) // si mode diago
	{
		coordonnes = trouverCaseDiago(morpion, retour);
	}
	else if (retour.x == 2 || retour.x == 3) // si mode ligne/colonne 
	{
		coordonnes = trouverCaseLigneColonnes(morpion, retour);
	}
	return coordonnes;
}

coord trouverAngleLibre(grille morpion)
{
	coord coordonnes;
	coordonnes.x = 0;
	coordonnes.y = 0;
	if (morpion.grilleJeu[0][0] != 'X' && morpion.grilleJeu[0][0] != 'O') // angle haut gauche
 	{
		coordonnes.x = 0;
		coordonnes.y = 0;
	}
	if (morpion.grilleJeu[morpion.taille-1][morpion.taille-1] != 'X' && morpion.grilleJeu[morpion.taille-1][morpion.taille-1] != 'O') // angle bas droit
	{
		coordonnes.x = morpion.taille-1;
		coordonnes.y = morpion.taille-1;
	}
	if (morpion.grilleJeu[0][morpion.taille-1] != 'X' &&  morpion.grilleJeu[0][morpion.taille-1] != 'O') // angle haut droit
	{
		coordonnes.x = 0;
		coordonnes.y = morpion.taille-1;
	}
	if (morpion.grilleJeu[morpion.taille-1][0] != 'X' && morpion.grilleJeu[morpion.taille-1][0] != 'O') // angle bas gauche
	{
		coordonnes.x = morpion.taille-1;
		coordonnes.y = 0;
	}
	return coordonnes;
}

coord trouverBordLibre(grille morpion, int milieu)
{
	coord coordonnes;
	coordonnes.x = 0;
	coordonnes.y = 0;
	if (morpion.grilleJeu[0][milieu] != 'X' && morpion.grilleJeu[0][milieu] != 'O') // bord haut
	{
		coordonnes.x  = 0;
		coordonnes.y = milieu;
	}
	else if (morpion.grilleJeu[milieu][0] != 'X' && morpion.grilleJeu[milieu][0] != 'O') // bord gauche
	{
		coordonnes.x = milieu;
		coordonnes.y = 0;
	}
	else if (morpion.grilleJeu[milieu][morpion.taille-1] != 'X' && morpion.grilleJeu[milieu][morpion.taille-1] != 'O') // bord droit
	{
		coordonnes.x = milieu;
 		coordonnes.y = morpion.taille-1;
	}
	else if (morpion.grilleJeu[morpion.taille-1][milieu] != 'X' && morpion.grilleJeu[morpion.taille-1][milieu] != '0') // bord bas
	{
		coordonnes.x = morpion.taille-1;
		coordonnes.y = milieu;
	}
	return coordonnes;
}

grille tourIA(grille morpion, int tour)
{
	int milieu = morpion.taille/2;
	coord retourAttaqueDefence = verifAttaqueDefence(morpion);
	coord coordonnes = trouverCase(morpion, retourAttaqueDefence);
	coord angleLibre = trouverAngleLibre(morpion);
	coord bordLibre = trouverBordLibre(morpion, milieu);
	if (morpion.grilleJeu[milieu][milieu] != 'X' && morpion.grilleJeu[milieu][milieu] != 'O' && tour >= 2)
	{
		morpion.grilleJeu[milieu][milieu] = 'O';
	}
	else if (morpion.grilleJeu[milieu][milieu] == 'O' && tour == 4 && retourAttaqueDefence.x == 0)
	{
		morpion.grilleJeu[bordLibre.x][bordLibre.y] = 'O';
	}
	else if (retourAttaqueDefence.x != 0)
	{
		morpion.grilleJeu[coordonnes.x][coordonnes.y] = 'O';
	}
	else if (angleLibre.x != 0)
	{
		morpion.grilleJeu[angleLibre.x][angleLibre.y] = 'O';
	}
	else
	{
		morpion = tourOrdiAleatoire(morpion);
	}
	return morpion;
}
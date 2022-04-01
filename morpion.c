#include "morpion.h"

int verificationSaisieMenu(void)
{
  int continuer = 1; // tant que la saisie n'est pas bonne, continuer
  int nb; // nombre a retourner
  int retour; // verifier la saisie
  while (continuer == 1) 
  {
    retour = scanf("%d", &nb); // demander le nombre
    if (retour != 0 && nb >= 1 && nb <= 4) // verifier que le nombre soit correct
    {
      continuer = 0;
    }
    else // recommencer la saisie
    {
      printf("Erreur de saisie, veuillez recommencer\n");
      if (retour == 0)
      {
        nb = getchar();
      }
    }
  }
  return nb;
}

grille creationGrille(grille morpion)
{
  morpion.grilleJeu = malloc(sizeof(char*) * morpion.taille); // allouer le tableau 2 dimensions
  if (morpion.grilleJeu == NULL) // verifier l'allocation
  {
    printf("Erreur Allocation\n");
    exit(ERREUR_ALLOCATION);
  }
  for (int i = 0; i < morpion.taille; i++) // allouer tout les char* determiner precedemment
  {
    morpion.grilleJeu[i] = malloc(sizeof(char) * morpion.taille);
    if (morpion.grilleJeu[i] == NULL) // verifier l' allocation
    {
      printf("Erreur Allocation\n");
      exit(ERREUR_ALLOCATION);
    }
  }
  for (int i = 0; i < morpion.taille; i++) // initialiser la grille de jeu
  {
    for (int j = 0; j < morpion.taille; j++)
    {
      morpion.grilleJeu[i][j] = ' ';
    }
  }
  return morpion;
}

void afficherGrille (grille morpion)
{
  printf("╔═══╦═══╦═══╗\n"); // haut de la grille
  for (int i = 0; i < morpion.taille; i++) // lignes
  {
    for (int j = 0; j < morpion.taille; j++) // colonnes
    {
      if (morpion.grilleJeu[i][j] == 'X')
      {
        printf("║ %s%c%s ", RED, morpion.grilleJeu[i][j], RESET); // afficher les X
      }
      else if (morpion.grilleJeu[i][j] == 'O')
      {
        printf("║ %s%c%s ", BLUE, morpion.grilleJeu[i][j], RESET); // afficher les O
      }
      else
      {
        printf("║ %c ", morpion.grilleJeu[i][j]); // afficher ' '
      }
    }
    printf("║\n");
    if (i == 0 || i == 1)
    {
      printf("╠═══╬═══╬═══╣\n" ); // milieu
    }
  }
  printf("╚═══╩═══╩═══╝\n"); // bas de la grille
}

int saisieCase(void)
{
  int continuer = 1; // tant que la saisie n'est pas bonne, continuer
  int nb; // nombre a retourner
  int retour; // verifier la saisie
  while (continuer == 1) 
  {
    retour = scanf("%d", &nb); // demander le nombre
    if (retour != 0 && nb >= 1 && nb <= 3) // verifier que le nombre soit correct
    {
      continuer = 0;
    }
    else // recommencer la saisie
    {
      printf("Erreur saisie, veuillez ressaisir\n");
      nb = getchar();
    }
  }
  return nb;
}

grille tourJoueur(grille morpion, int joueur)
{
  coord caseJeu; // coordonnee de la case
  int continuer = 1; // tant que la saisie de la case n'est pas bonne
  while (continuer == 1) {
    printf("Choisissez la ligne\n");
    caseJeu.x = saisieCase(); // saisie de la ligne
    printf("Choisissez la colonne\n");
    caseJeu.y = saisieCase(); // saisie de la colonne
    continuer = verificationEmplacement(caseJeu, morpion); // verifier que l'emplacement est libre
    if (continuer == 1)
    {
      printf("L'emplacement est deja pris, veuillez ressaisir\n"); // si l emplacement n'est pas libre recommencer
    }
  }
  if (joueur == 1) // si le joueur est le joueur 2
  {
    morpion.grilleJeu[caseJeu.x-1][caseJeu.y-1] = 'O';
  }
  else // si le joueur est le joueur 1
  {
    morpion.grilleJeu[caseJeu.x-1][caseJeu.y-1] = 'X';
  }
  return morpion;
}

int verificationEmplacement(coord caseJeu, grille morpion)
{
  int nb = 0; // 0 si la case est bonne, 1 si elle est deja prise
  if (morpion.grilleJeu[caseJeu.x - 1][caseJeu.y - 1] == 'O' || morpion.grilleJeu[caseJeu.x - 1][caseJeu.y - 1] == 'X') // verifier l'emplacement saisie
  {
    nb = 1;
  }
  return nb;
}

grille tourOrdiAleatoire (grille morpion)
{
  coord caseJeu; // coordonnee de la case
  int continuer = 1;
  while (continuer == 1) {
    caseJeu.x = rand()%(morpion.taille-1+1) + 1; // ligne aleatoire
    caseJeu.y = rand()%(morpion.taille-1+1) + 1; // colonne aleatoire
    continuer = verificationEmplacement(caseJeu, morpion); // verifier que l emplacement est vide
  }
  morpion.grilleJeu[caseJeu.x-1][caseJeu.y-1] = 'O';
  return morpion;
}

int verificationDiagonale(grille morpion)
{
  int gagner = 1; // variable d'arret du jeu
  if ((morpion.grilleJeu[0][0] == 'X' && morpion.grilleJeu[1][1] == 'X' && morpion.grilleJeu[2][2] == 'X') || (morpion.grilleJeu[0][2] == 'X' && morpion.grilleJeu[1][1] == 'X' && morpion.grilleJeu[2][0] == 'X')) // verifier diagonales pour les X
  {
    printf("Le %sjoueur 1%s a gagner\n", RED, RESET); // si le joueur 1 a gagner
    gagner = 0; // arret du jeu
  }
  else if ((morpion.grilleJeu[0][0] == 'O' && morpion.grilleJeu[1][1] == 'O' && morpion.grilleJeu[2][2] == 'O') || (morpion.grilleJeu[0][2] == 'O' && morpion.grilleJeu[1][1] == 'O' && morpion.grilleJeu[2][0] == 'O'))
  {
    printf("Le %sjoueur 2%s a gagner\n", BLUE, RESET); // si le joueur 2 ou l ia a gagner
    gagner = 0; // arret du jeu
  }
  return gagner;
}

int verificationLigneColonne(grille morpion)
{
  int gagner = 1; // variable d'arret du jeu
  for (int i = 0; i < morpion.taille; i++)
  {
    if ((morpion.grilleJeu[i][0] == 'X' && morpion.grilleJeu[i][1] == 'X' && morpion.grilleJeu[i][2] == 'X') || (morpion.grilleJeu[0][i] == 'X' && morpion.grilleJeu[1][i] == 'X' && morpion.grilleJeu[2][i] == 'X')) // verifier les lignes/ colonnes pour les X
    {
      gagner = 0; // arret du jeu
      printf("Le %sjoueur 1%s a gagner\n", RED, RESET);
    }
    else if ((morpion.grilleJeu[i][0] == 'O' && morpion.grilleJeu[i][1] == 'O' && morpion.grilleJeu[i][2] == 'O') || (morpion.grilleJeu[0][i] == 'O' && morpion.grilleJeu[1][i] == 'O' && morpion.grilleJeu[2][i] == 'O')) // verifier les lignes/ colonnes pour les O
    {
      gagner = 0; // arret du jeu
      printf("Le %sjoueur 2%s a gagner\n", BLUE, RESET);
    }
  }
  return gagner;
}

void joueurVSjoueur(void)
{
  int continuer = 1; // tant que personne n'as gagner ou qu il ny a pas egaliter
  verif verifications; // resultats des verifications 
  int joueur = 0; // joueur 1%2 = 1 ou 2%2 = 0 
  int n = 0; // nombre de tours
  grille morpion; // plateau de jeu
  morpion.taille = 3; // taille du plateau
  morpion = creationGrille(morpion); // allocation de la grille
  while (continuer == 1) // tant que le jeu continu
  {
    n++; // ajout d'un tour
    system("clear"); 
    afficherGrille(morpion); // afficher la grille
    printf("Joueur %d a vous de jouer\n", joueur+1);
    morpion = tourJoueur(morpion, joueur); // tour du joueur 
    joueur = (joueur + 1)%2; // changement de joueur
    verifications = verifier(n, morpion); // verifier si il y a un gagnant
    continuer = verifications.continuer; // verifier si le jeu s arrete
  }
  if (n == 9 && verifications.diagonales != 0 && verifications.ligneColonnes != 0) // si le jeu s arrete, verifier si il y a egalite ou pas
  {
    printf("%sEgalité%s\n", EGALITE, RESET);
  }
  afficherGrille(morpion); // afficher la grille
}

void joueurVSiaAleatoire(void)
{
  int continuer = 1; // tant que personne n as gagner oui qu il n y a pas egaliter
  verif verifications; // resultats des verifications
  int joueur = rand()%2; // determiner si le joueur ou l ia commence
  int n = 0; // nombre de tours
  grille morpion; // plateau de jeu
  morpion.taille = 3; // taille de la grille
  morpion = creationGrille(morpion); // allocation de la grille
  while (continuer == 1) //
  {
    n++; // ajout d'un tour
    system("clear"); 
    morpion = tourJoueurIaAleatoire(morpion, joueur); // tour du joueur ou de l ia en fonction de la variable joueur
    joueur = (joueur + 1)%2; // joueur suivant
    verifications = verifier(n, morpion); // verifier si il y a un gagnant
    continuer = verifications.continuer; // verifier si le jeu s arrete
  }
  if (n == 9 && verifications.diagonales != 0 && verifications.ligneColonnes != 0) // si le jeu s arrete, verifier si il y a egalite ou pas
  {
    printf("%sEgalité%s\n", EGALITE, RESET);
  }
  afficherGrille(morpion); // afficher la grille
}

grille tourJoueurIaAleatoire(grille morpion, int joueur)
{
  if (joueur == 1) // ia qui joue
  {
    morpion = tourOrdiAleatoire(morpion); // tour ia
  }
  else // joueur qui joue
  {
    afficherGrille(morpion); // afficher la grille
    printf("Joueur a vous de jouer\n");
    morpion = tourJoueur(morpion, joueur); // tour joueur
  }
  return morpion;
}

verif verifier(int n, grille morpion)
{
  verif verifications; // resultats des verifications
  verifications.diagonales = verificationDiagonale(morpion); // verifier si quelqu un a gagner en diagonale
  verifications.ligneColonnes = verificationLigneColonne(morpion); // verifier si quelqu un a gagner en ligne / colonne
  verifications.continuer = 1;
  if (verifications.diagonales == 0 || verifications.ligneColonnes == 0 || n == 9) // verifier si on doit arreter le jeu
  {
    verifications.continuer = 0; // le jeu s arrete si une des condition est verifier
  }
  return verifications;
}

void joueurVSia(void)
{
  int continuer = 1; // tant que personne n as gagner oui qu il n y a pas egaliter
  verif verifications; // resultats des verifications
  int joueur = rand()%2; // determiner si le joueur ou l ia commence
  int n = 0; // nombre de tours
  grille morpion; // plateau de jeu
  morpion.taille = 3; // taille de la grille
  morpion = creationGrille(morpion); // allocation de la grille
  while (continuer == 1) //
  {
    n++; // ajout d'un tour
    system("clear"); 
    morpion = tourJoueurIa(morpion, joueur, n); // tour du joueur ou de l ia en fonction de la variable joueur
    joueur = (joueur + 1)%2; // joueur suivant
    verifications = verifier(n, morpion); // verifier si il y a un gagnant
    continuer = verifications.continuer; // verifier si le jeu s arrete
  }
  if (n == 9 && verifications.diagonales != 0 && verifications.ligneColonnes != 0) // si le jeu s arrete, verifier si il y a egalite ou pas
  {
    printf("%sEgalité%s\n", EGALITE, RESET);
  }
  afficherGrille(morpion); // afficher la grille
}

grille tourJoueurIa(grille morpion, int joueur, int tour)
{
  if (joueur == 1) // ia qui joue
  {
    morpion = tourIA(morpion, tour); // tour ia
  }
  else // joueur qui joue
  {
    afficherGrille(morpion); // afficher la grille
    printf("Joueur a vous de jouer\n");
    morpion = tourJoueur(morpion, joueur); // tour joueur
  }
  return morpion;
}


#include "morpion.h"
#include "ia.h"

int main(void)
{
  srand(time(NULL));
  int choix;
  system("clear");
  printf("%s██      ██  %s████████  %s████████  %s████████  %s██  %s████████  %s██      ██%s\n", RED, BLUE, RED, BLUE, RED, BLUE, RED, RESET);
  printf("%s████  ████  %s██    ██  %s██    ██  %s██    ██  %s██  %s██    ██  %s████    ██%s\n", RED, BLUE, RED, BLUE, RED, BLUE, RED, RESET);
  printf("%s██  ██  ██  %s██    ██  %s████████  %s████████  %s██  %s██    ██  %s██  ██  ██%s\n", RED, BLUE, RED, BLUE, RED, BLUE, RED, RESET);
  printf("%s██      ██  %s██    ██  %s██  ██    %s██        %s██  %s██    ██  %s██    ████%s\n", RED, BLUE, RED, BLUE, RED, BLUE, RED, RESET);
  printf("%s██      ██  %s████████  %s██    ██  %s██        %s██  %s████████  %s██      ██%s\n", RED, BLUE, RED, BLUE, RED, BLUE, RED, RESET);
  printf("╔═════════════════════════════════╗\n");
  printf("║                                 ║\n");
  printf("║  %s-------------Menu------------%s  ║\n", BLUE, RESET);
  printf("║                                 ║\n");
  printf("║  Choisissez le mode de jeux     ║\n");
  printf("║                                 ║\n");
  printf("║  %s[1] Joueur Vs Joueur%s           ║\n", EGALITE, RESET);
  printf("║                                 ║\n");
  printf("║  %s[2] Joueur Vs IA (facile)%s      ║\n", BLUE, RESET);
  printf("║                                 ║\n");
  printf("║  %s[3] Joueur Vs IA (Difficile)%s   ║\n", RED, RESET);
  printf("║                                 ║\n");
  printf("║  [4] Quitter                    ║\n");
  printf("║                                 ║\n");
  printf("╚═════════════════════════════════╝\n");
  choix = verificationSaisieMenu();
  switch (choix) 
  {
    case 1:
      joueurVSjoueur();
    break;
    case 2:
      joueurVSiaAleatoire();
    break;
    case 3:
      joueurVSia();
    break;
    default:
     exit(ERREUR_JEU);
    break;
  }
  return 0;
}

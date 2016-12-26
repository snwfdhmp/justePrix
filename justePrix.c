/*
	Le jeu du juste prix
	Allan CORRIERE - 2016 - optimisé par Martin JOLY
*/

//Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Cette bibliothèque est utilisée pour pouvoir génerer des nombres aléatoires

// Fonction principale

int main()
{
	int choix = 1;
	const unsigned int MIN = 1; // On a défini les bornes minimales et maximales
	int MAX = 100; // Par défaut : Facile
	int nb = 0;
	int nbAleat = 0;
	int debut, fin;
	// Menu
	do	
	{
		printf("\n\nBienvenue sur le jeu du juste prix !\n");
		printf("Veuillez choisir la difficulte:\n");
		printf("1. Facile - de 1 a 100\n");
		printf("2. Normal - de 1 a 1 000\n");
		printf("3. Difficile - de 1 a 10 000\n");
		printf("4. Extreme - de 1 a 100 000\n");
		printf("5. Cauchemars - de 1 a 1 000 000\n");
		printf("\n6. Quitter\n");
		printf("\nVotre choix: ");
		scanf("%d", &choix);
 
		// On va agir différement selon ce que l'utilisateur a rentré

		switch (choix)
		{
			case 1:
					MAX = 100;
				break;
			case 2:
				MAX = 1000;
				break;
			case 3:
				MAX = 10000;
				break;
			case 4:
				MAX = 100000;
				break;
			case 5:
				MAX = 1000000;
				break;
			case 6:
				printf("\n\n-- Merci d'avoir joue ! --\n\n\n");
				exit(0); // Permet de quitter un programme en cours de fonctionnement
				break;
			default:
				printf("\nVeuillez entrer un choix valide.\n\n");
				break;
		}
		srand(time(NULL));
		nbAleat = (rand() % (MAX - MIN + 1)) + MIN;
		time(&debut); // L'heure de début
		printf("\n\nEntrez un nombre entre %d et %d: ", MIN, MAX);
		scanf("%d", &nb);
		while (nb != nbAleat)
		{
			if (nb > nbAleat)
			{
				printf("\nC'est moins !\n");
			}
			else
			{
				printf("\nC'est plus !\n");
			}
			printf("Entrez un nouveau nombre: ");
			scanf("%d", &nb);
		}
		time(&fin); // L'heure de fin
		printf("\nC'est gagné ! Tu as mis %f secondes\n", difftime(fin, debut)); // On fait l'heure de fin - l'heure de début
	}
	while ((choix != '1') && (choix != '2') && (choix != '3') && (choix != '4') && (choix != '5') && (choix != '6'));
	return 0;
}
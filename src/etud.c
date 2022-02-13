#include "etud.h"

#include <stdlib.h>
#include <string.h>

#define SIZE_MAX 1000

/**
 *\brief ajouter un étudiant 
 *\param : char*
 *\param : char*
 *\param : float 
 *\return : int  0 si la liste est vide  1 sinon 
 */
int add_etud(char* nom, char* prenom, float note, int num){
	Etud* newEtud;

	if(pEtud == NULL)
		return -1;

	newEtud = malloc(sizeof *newEtud);
	
	strcpy(newEtud->nom, nom);
	strcpy(newEtud->prenom, prenom);
	newEtud->num = (num == -1)? id++ : num;
	newEtud->note = note;
	newEtud->next = pEtud->next;

	pEtud->next = newEtud;
  	
  	return 0;
}

/**
*\brief afficher la liste des étudiants 
*/
void print_list(){
	Etud* etud = pEtud->next;

	printf("Liste des etudiants \n");

	printf("-----------------\n");
	while(etud != NULL){
	  	printf("%s, %s, %d, %.2f\n", etud->nom, etud->prenom, etud->num, etud->note);
			etud = etud->next;
	}
	printf("-----------------\n");
}

/**
*\brief supprimer un étudiant 
*\param: int
*\return : int  -1 si la liste est vide , 1 s'il n'a pas trouvé l'élément saisi  , 0 sinon   et au même temps elle supprime l'élément 
*/
int delete_etud(int num){
	Etud *currentEtud, *lastEtud;

	if(pEtud == NULL)
		return -1;

	currentEtud = pEtud->next;
	lastEtud = pEtud;

	while(currentEtud != NULL){
		if(currentEtud->num == num){
			lastEtud->next = currentEtud->next;
			free(currentEtud);
			return 0;
		}
		lastEtud = currentEtud;
		currentEtud = currentEtud->next;
	}
	
	return 1;
}

/**
*\brief recherhcer un étudiant 
*\param: int
*\return : Etud* les informations relatives au numéro de l'étudiant tappé par l'utilisateur 
*/ 
Etud* find_etud(int num){
	Etud *currentEtud;
	
	if(pEtud == NULL)
		return NULL;

	currentEtud = pEtud->next;
	
	while(currentEtud != NULL){
		if(currentEtud->num == num){
			return currentEtud;
		}
		currentEtud = currentEtud->next;
	}

	return NULL;
}

/**
 *\brief calculer la moyenne 
  *\return:int 
*/
float average(){
	Etud* etud = pEtud->next;
	float average = 0.0;
	int count = 0;

	if (pEtud == NULL)
		return 0.0;
	
	while(etud != NULL){
		count++;
		average += etud->note;
		etud = etud->next;
	}
	
	return average / (float)count;
}


/**
 *\brief modifier la note d'un étudiant
 *\param: int
 *\param: float
 *\return:int 
 */
int setNote(int num, float note){
	Etud* etud = find_etud(num);
	
	if(etud == NULL)
		return -1;

	etud->note = note;

	return 0;
}

/**
 *\brief enregistrer les informations d'un étudiant
 */
void save(char* fileName){
	FILE* fichier = NULL;
	Etud* etud;
    
    fichier = fopen(fileName, "w+");

    if (fichier != NULL)
    {
    	printf("Saving ...\n");
    	
    	if (pEtud == NULL)
    		return;

    	etud = pEtud->next;

		while(etud != NULL){
			fprintf(fichier, "%s,%s,%d,%.2f\n", etud->nom, etud->prenom, etud->num, etud->note);
			etud = etud->next;
		}
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");
    }
}
/**
 *\brief chaarger la liste des étudiants lors du démmarage de l'application
 *\param: char*
*/
void load(char* fileName){
	FILE* fichier = NULL;
	char line[SIZE_MAX], *token, *nom, *prenom;
	int num;
	float note;

    fichier = fopen(fileName, "r+");

    if (fichier != NULL)
    {
    	printf("Loading ...\n");
		while(fgets(line, SIZE_MAX, fichier) != NULL){
			Etud* etud = malloc(sizeof *etud);
			token = strtok(line, ",");
			nom = token;

			token = strtok(NULL, ",");
			prenom = token;

			token = strtok(NULL, ",");
			num = atoi(token);

			token = strtok(NULL, ",");
			note = strtod(token, NULL);

			add_etud(nom, prenom, note, num);
		}
    }
    else
    {
        printf("Impossible d'ouvrir le fichier test.txt");
    }

}

/**
 *\brief trouver un étudiant en saisissant son nom
 *\param: char*
 *\return:int 
 */
int find_etud_by_name(char* nom){
	Etud *currentEtud;
	int count = 0;
	char* pch;

	if(pEtud == NULL)
		return -1;

	currentEtud = pEtud->next;
	
	while( currentEtud != NULL){
		pch = strstr(currentEtud->nom, nom);
		if(pch != NULL){
			printf("%s, %s, %d, %.2f\n", currentEtud->nom, currentEtud->prenom, currentEtud->num, currentEtud->note);
			count++;
		}
		currentEtud = currentEtud->next;
	}

	return count;
}

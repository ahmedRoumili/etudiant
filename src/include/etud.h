#include <stdio.h>

typedef struct etud
{
  unsigned int num;
  char  nom[50];
  char  prenom[50];
  float note;
  struct etud* next;
}Etud;


Etud* pEtud;
int id;

/**
 *\brief afficher la liste des étudiants 
*/

void print_list();

/**
 *\biref ajouter un étudiant 
 *\param : char*
 *\param : char*
 *\param : float 
 *\return : int
*/

int add_etud(char* nom, char* prenom, float note, int num);

/**
 *\brief supprimer un étudiant 
 *\param: int
 *\ return : int  -1 si la liste est vide , 1 s'il n'a pas trouvé l'élément saisi  , 0 sinon   et au même temps elle supprime l'élément 
*/ 

int delete_etud(int num);

/**
 *\brief recherhcer un étudiant 
 *\param: int
 *\ return : Etud* les informations relatives au numéro de l'étudiant saisi par l'utilisateur 
*/ 

Etud* find_etud(int num);

/**
 *\brief trouver un étudiant en saisissant son nom
 *\param: char*
 *\return:int 
*/

int find_etud_by_name(char* nom);

/**
 *\brief calculer la moyenne 
  *\return:int 
*/

float average();

/**
 *\brief modifier la note d'un étudiant
 *\param: int
 *\param: float
 *\return:int 
*/

int setNote(int num, float note);

/**
 *\brief enregistrer les informations d'un étudiant
*/
void save(char* fileName);

/**
 *\brief chaarger la liste des étudiants lors du démmarage de l'application
  *\param: char*
*/
void load(char* fileName);

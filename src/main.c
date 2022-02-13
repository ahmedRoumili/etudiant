#include "etud.h"
#include "appli.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Variable globale qui contient la liste chainé etudiants
 */
int main (int argc, char* argv[]){

    char* fileName = "list_etud.csv";
    id = 0;
    
    printf(" === Scola === \n");
    
    pEtud =  malloc(sizeof *pEtud);

    load(fileName);

    print_menu();

    save(fileName);
    
    return 0; 
}
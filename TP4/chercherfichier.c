/* Fichier: chercherfichier.c
* affiche  à l'écran.
* auteur: Paul Moreau et Gabin Jobert--Rollin
* Ceci est un commentaire sur plusieurs lignes
*/

#include <stdio.h>
#include "fichier.h"

int main(){

    char nom_de_fichier[] = "texte";
    char phrase[] = "j'adore la";

    rechercher_fichier(nom_de_fichier,phrase);

    return 0;
}
/* Fichier: fichier.c
* affiche  à l'écran.
* auteur: Paul Moreau et Gabin Jobert--Rollin
*/

#include <stdio.h>
#include "fichier.h"

int main(){

    char nom_de_fichier[] = "texte";
    char message[] = "j'adore CPE et jhon";

    ecrire_dans_fichier(nom_de_fichier,message);
    lire_fichier(nom_de_fichier);
    
    return 0;
}

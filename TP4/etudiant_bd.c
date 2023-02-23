/* Fichier etudiant_bd.c
*  Auteur : Paul MOREAU et JOBERT--ROLLIN
*  Déclare et initialise le détails de cinq étudiants dans un fichier .txt en utilisant des structures*/

#include <stdio.h>
#include <string.h>
#include "fichier.h"

struct etudiant{
/*Structure contenant les donnée d'un étudiant*/
        char prenom[30];
        char nom[30];
        char adresse[30];
        int note1;
        int note2;
    };

int main(){
    struct etudiant etu1;
    struct etudiant etu2;
    struct etudiant etu3;
    struct etudiant etu4;
    struct etudiant etu5;
    
    struct etudiant etudiants[5]={etu1,etu2,etu3,etu4,etu5};

    
    for(int i=0;i<5;i++){
        char noteA[3];
        char noteB[3];
        printf("SVP entrez premom, nom, adresse et les 2 notes");
        

        /*Demande à l'utilisateur de taper les informations*/
        scanf("%s",etudiants[i].prenom);
        scanf("%s",etudiants[i].nom);
        scanf("%s",etudiants[i].adresse);
        scanf("%i",&etudiants[i].note1);
        scanf("%i",&etudiants[i].note2);
        sprintf(noteA,"%d",etudiants[i].note1);
        sprintf(noteB,"%d",etudiants[i].note2);
        
        ecrire_dans_fichier("fichier.txt",noteB);
        ecrire_dans_fichier("fichier.txt",", ");

        ecrire_dans_fichier("fichier.txt",noteA);
        ecrire_dans_fichier("fichier.txt",", ");

        ecrire_dans_fichier("fichier.txt",etudiants[i].adresse);
        ecrire_dans_fichier("fichier.txt",", ");

        ecrire_dans_fichier("fichier.txt",etudiants[i].nom);
        ecrire_dans_fichier("fichier.txt",", ");

        ecrire_dans_fichier("fichier.txt",etudiants[i].prenom);
        ecrire_dans_fichier("fichier.txt","\n");

    }
    return 0;
}

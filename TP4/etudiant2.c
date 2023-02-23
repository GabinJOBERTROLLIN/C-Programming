/* Fichier etudiant2.c
*  Auteur : Paul MOREAU et JOBERT--ROLLIN
*  Déclare et initialise le détails de cinq étudiants en utilisant des structures*/

#include <stdio.h>
#include <string.h>

struct etudiant{
        char prenom[30];
        char nom[30];
        char adresse[30];
        int note1;
        int note2;
    };

int printfEtudiant(struct etudiant);

int main(){
    struct etudiant etu1;
    struct etudiant etu2;
    struct etudiant etu3;
    struct etudiant etu4;
    struct etudiant etu5;
    
    struct etudiant etudiants[5]={etu1,etu2,etu3,etu4,etu5};

    /* Remplis la structure d'informations*/
    for(int i=0;i<5;i++){
        strcpy(etudiants[i].prenom,"lui");
        strcpy(etudiants[i].nom,"lui");
        strcpy(etudiants[i].adresse,"ici");
        etudiants[i].note1=10;
        etudiants[i].note2=10;
        printfEtudiant(etudiants[i]);
    }
    
    return 0;
}


int printfEtudiant(struct etudiant etu){
/* Affichage de la structure*/
    printf("Nom : %s, Prenom : %s, Adresse : %s, Note1 : %i, Note2, %i\n",etu.prenom, etu.nom, etu.adresse, etu.note1, etu.note2);
}
/* Fichier: fichier.c
* affiche  à l'écran si une phrase a été une ou plusieur fois dans un fichier.
* auteur: Paul Moreau et Gabin Jobert--Rollin
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void lire_fichier(char *nom_de_fichier){

    FILE *fichier = NULL;
    int caractereActuel = 0;
    
    fichier = fopen(nom_de_fichier, "r");

    if (fichier != NULL)
    {
        // Boucle de lecture des caractères un à un
        
        while (caractereActuel != EOF){
            // On continue tant que fgetc n'a pas retourné EOF (fin de fichier)
            caractereActuel = fgetc(fichier); // On lit le caractère
            printf("%c", caractereActuel); // On l'affiche

        } 
        
        fclose(fichier);
    }

    return;
}


void ecrire_dans_fichier(char *nom_de_fichier, char *message){

    FILE *fichier = NULL;

    
    fichier = fopen(nom_de_fichier,"a");
    
    fputs(message,fichier);
    printf("\n");
    fclose(fichier);
    

    return;
}

void rechercher_fichier(char *nom_de_fichier, char *phrase){

    FILE *fichier = NULL;
    int compteur = 1;
    int compteur_presence = 1;

    fichier = fopen(nom_de_fichier,"r");

    char phrase_fichier[1000];

    while (fgets(phrase_fichier,1000,fichier) != NULL)
    {

        if (strstr(phrase_fichier, phrase) != NULL)
        {
            /*printf("'%s' trouvé dans '%s'\n", phrase,nom_de_fichier);*/
            printf("la phrase a été trouvée à la ligne %i\n", compteur);
            
            char *ptr_phrases=&phrase_fichier[0];
            char *ptr_recherche = &phrase[0];
            int iterator = 0;
            for(unsigned int i=0; i<=sizeof(phrase_fichier); i++){
                if (*(ptr_phrases+i)==*(ptr_recherche))
                {
                    iterator++;
                }

                if (iterator==sizeof(phrase)/sizeof(char))
                {
                    compteur_presence++;
                    printf("la phrase a été trouvée %i\n",compteur_presence);
                }
                
                else
                {
                    iterator = 0;
                }

                
            }
            
            compteur_presence =1;
        }

        compteur++;

    }
    
    fclose(fichier);

    return;
}


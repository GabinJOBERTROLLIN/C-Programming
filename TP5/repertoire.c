/* Fichier: repertoire.c
* Fonctions pour lire et écrire dans des répertoires de façon itérative
* auteur: Paul Moreau et Gabin Jobert--Rollin
*/
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void lire_fichier(char* a){
/*parcourt le répertoire saisi et affiche tous les noms de fichier*/
    DIR *dir;
    struct dirent *res;
    dir = opendir(a);

    while ((res=readdir(dir)) != NULL){
        printf("%s\n",res->d_name);
    }
}

void lire_fichier_recursif(char* a){
    /*parcourt le répertoire saisi et affiche tous les noms de fichier et des sous répertoire en récursif*/
    DIR *dir = opendir(a);
    struct dirent *res;
    
        while ((res=readdir(dir)) != NULL){
            if ((res->d_type)== DT_DIR){
                
                if (    (res->d_name[0]!='.')  &&  (strcmp(res->d_name,"..")!=0)  ){
                    printf("%s\n",res->d_name);
                    lire_fichier_recursif(res->d_name);
            }
            }
            else{
                printf("%s\n",res->d_name);
            }
        }

    }

void lire_dossier_iteratif(char* a){
    /*parcourt le répertoire saisi et affiche tous les noms de fichier et des sous repertoires de facon itératives*/
    /*ce programme ne fonctionne pas */
    DIR *dir;
    struct dirent *res;
    dir = opendir(a);
    DIR *ancienDir = dir;
    int iterateur = 1;
    while (iterateur!=0){
        res=readdir(dir);
        if ((res->d_type)== DT_DIR){
            closedir(dir);
            res = opendir(res->d_name);
            iterateur +=1;
        }
        if (res==NULL){
            res-=1;
            dir opendir()
        }
    }
    
    
}
    

int main(int c, char **args){
    /*lire_fichier(args[1]);*/
    lire_dossier_iteratif(args[1]);
    /*lire_fichier_recursif(args[1]);*/
}
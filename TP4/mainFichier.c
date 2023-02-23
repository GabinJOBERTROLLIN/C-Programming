#include <stdio.h>
#include "fichier.h"

int main(){
    char chaine[]= "une phrase en plus";
    lire_fichier("fichier.txt");
    ecrire_dans_fichier("fichier.txt",chaine);
    
}
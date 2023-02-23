/* Fichier calcul.c
*  Auteur : Paul MOREAU et JOBERT--ROLLIN
*  Calcul d'opération elementaire sur les paramètre fournis en ligne de commande grace aux
*  fonctions définis dans operator.c*/

#include <stdio.h>
#include <stdlib.h>
#include "operator.h"


int calcule(char,int,int);


int main(int argc, char *argv[]){
    if (argc==4){
        /*recueuille les paramètres envoyés en ligne de commande*/
        char op = *argv[1];
        int a=atoi(argv[2]);
        int b=atoi(argv[3]);
        
        printf("a :%i\n",a);
        printf("b :%i\n",b);
        int res=calcule(op,a,b);
        printf("result : %i\n",res);
    }
    return 0;
}

/*Calcule le résultat de l'opération en fonction de l'opération demandée et de 2 nombres*/
int calcule(char op,int a,int b){
    if (op=='+'){
        return somme(a,b);
    }
    if (op=='-'){
        return difference(a,b);
    }
    if (op=='*'){
        return produit(a,b);
    }
    if (op=='/'){
        return quotient(a,b);
    }
    if (op=='%'){
        return modulo(a,b);
    }
    if (op=='&'){
        return et(a,b);
    }
    if (op=='~'){
        return negation(a);
    }
    return 0
    ;
}

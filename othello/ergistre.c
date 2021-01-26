#include <stdio.h>
#include <stdlib.h>
#include "fonction_Tritement_fichier.h"




void main()
{
char *code=malloc(30);
joueur A;
/*
A=ccrerJoueur("zouheir",13,23);
ajouterjoureur(A);
A=ccrerJoueur("yhaha3",42,3);
ajouterjoureur(A);
A=ccrerJoueur("yhaha2",2,3);
ajouterjoureur(A);
A=ccrerJoueur("yhaha1",12,3);
ajouterjoureur(A);
A=ccrerJoueur("yhaha9",21,3);
ajouterjoureur(A);
A=ccrerJoueur("yhaha44",42,3);
ajouterjoureur(A);
A=ccrerJoueur("yhaha8",23,3);
ajouterjoureur(A);
A=ccrerJoueur("yhaha8",23,3);
ajouterjoureur(A);
A=ccrerJoueur("yhaha4",22,3);
ajouterjoureur(A);
A=ccrerJoueur("yhaha6",21,3);
ajouterjoureur(A);
A=ccrerJoueur("yhaha5",22,3);
ajouterjoureur(A);
A=ccrerJoueur("amine",29,5);
ajouterjoureur(A);
chargerdata();
printf("\naaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
A=ccrerJoueur("zouheir",992,23);
modifierbasedonnees(A);*/

//if(creerNouvauxCompt("zlcclo2","sanc2019")) printf("tout est bien \n");
//else printf("il ya un pb\n");
//if(creerNouvauxCompt("zloldl1","sanc2019")) printf("tout est bien \n");
//else printf("il ya un pb\n");
creerNouvauxCompt("zzwww","wwwwi");
FILE *flot;

flot=fopen("dataDeJoueur.dat","rb");

if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}

while (fread(&A,sizeof(A),1,flot))
{
 printf("(%d,%s,%d)\n",A.cle,A.usrname,A.score);
}

fclose(flot);
joueur B;
int x;

x=verfieUnCompt(&B,"zzzzz","123456");
printf("\n%d  je suis la %d\n",x,B.score);
 
afficher(DixMeilleursScores());

}

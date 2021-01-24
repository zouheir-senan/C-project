
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define JOUEURS "dataDeJoueur.dat"
 
typedef struct joueur{
    char usrname[20];
    int score;
    int cle;
}joueur;
typedef struct __ {
    char password[20];
    int cle;
}cc;
joueur ccrerJoueur(char *nom,int score,int cle){
 joueur A;
 A.cle=cle;
 A.score=score;
 strcpy(A.usrname,nom);
 return A;
} 

int joueurcmp(joueur X,joueur Y){
    if((X.cle==Y.cle)&&(X.score=Y.score)&&(strcmp(X.usrname,Y.usrname)==0)) return 1;
    else return 0;   
}



void  modifierbasedonnees(joueur A){
  char const *nouveau = "temp.bin";
  joueur Temp,B,X;
  FILE *donnees;
  donnees=fopen(JOUEURS,"rb");
  FILE *donnees2;

  donnees2 = fopen(nouveau,"wb");
  while (fread(&Temp,sizeof(Temp),1,donnees))
  {
    if (strcmp(Temp.usrname,A.usrname))
    {
      B=Temp;
    } 
  }
  fseek(donnees,0,SEEK_SET);
  fseek(donnees2,0,SEEK_SET);
  while(fread(&X,sizeof(X),1,donnees))
  {
  if(joueurcmp(X,B)!=0)
  fwrite (&X,sizeof(X),1,donnees2);
  }
  fwrite(&A,sizeof(A),1,donnees2);
 
  fclose(donnees);
  fclose(donnees2);
 
  remove(JOUEURS);
  rename(nouveau,JOUEURS);
}
int ajouterjoureur(joueur A){
    // if tout a fait bien return 0
    // if il ya deja le jeureur 1

FILE *flot;
joueur B;
flot=fopen(JOUEURS,"rb");
while (fread(&B,sizeof(B),1,flot))
{
  if(joueurcmp(A,B)) return 1;
}
fclose(flot);
flot=fopen(JOUEURS,"ab");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}

fwrite(&A,sizeof(A),1,flot);
fclose(flot);
return 0;    
} 
void chargerdata(void){
FILE *flot;
joueur A;
char nom[20];
flot=fopen(JOUEURS,"rb");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}
while (fread(&A,sizeof(A),1,flot))
{
printf("%d\n",A.score);
printf("%d\n",A.cle);
printf("%s\n",A.usrname);
printf("\n------------------------------\n");
}
fclose(flot);
}
void afficher(joueur *liste){
for (size_t i = 0; i < 10; i++)
{
printf("%d\n",liste[i].score);
printf("%d\n",liste[i].cle);
printf("%s\n",liste[i].usrname);
printf("\n------------------------------\n");
}
}

void main()
{
//remove(JOUEURS);
char *code=malloc(30);
joueur A;
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
chargerdata();
printf("\naaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
modifierbasedonnees(ccrerJoueur("yhaha1",100,3));
chargerdata();
//afficher(DixMeilleursScores());
//remove(JOUEURS);
}
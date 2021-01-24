#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

#define JOUEURS "dataDeJoueur.dat"
 
typedef struct joueur{
    char usrname[20];
    int score;
    int cle;
}joueur;



int hash(const char *password){
   // un petit fonction pour hash le mot de passe :)
     int c=0;
     int i;
     for( i=0;i<strlen(password);i++){
        c=c+(int)(password[i]*exp(i)+log10((int)password[i]));
        c%=1000;
     }
return c;
}

char *crypto(const char *password){
// un petit fonction pour crypte le mot de passe :) 
int i,len=strlen(password);
char *code=malloc(len);
for(i=0; i<len; i++)
code[i]=password[i]+len+i;
return code;
}
joueur ccrerJoueur(char *nom,int score,int cle){
    // creer un nouvaux structe de joueur :)
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



joueur *DixMeilleursScores(void){
FILE *flot;
joueur A,MAX;
joueur *DixM=(joueur*)malloc(sizeof(joueur)*10);

int i=0,bool,j;
while (i<10)
{
flot=fopen(JOUEURS,"rb");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}

bool=0;
MAX.score=0;
MAX.cle=0;
strcpy(MAX.usrname,"");
out1:
while(fread(&A,sizeof(A),1,flot)){
if((MAX.score<A.score)&&i==0)  MAX=A;
else if((MAX.score<A.score)&&(DixM[i-1].score>=A.score)){
    if(DixM[i-1].score==A.score)
    {
    j=1;
    while ((DixM[i-j].score==A.score)&&(j<=i))
    {
    if(joueurcmp(DixM[i-j],A)) goto out1;
    j++;
    }
    MAX=A;
    goto out2;   
    }
MAX=A;
} 

}
out2:
DixM[i]=MAX;
i++;
fclose(flot);}
return DixM;
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



void modifierbasedonnees(joueur B){
const char *nouvaux="temp.bin";
FILE *flot2;
FILE *flot;
flot=fopen(nouvaux,"wb");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}
flot2=fopen("dataDeJoueur.dat","rb");
if(!flot2){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}
joueur A;
while (fread(&A,sizeof(A),1,flot2))
{
    if(!strcmp(A.usrname,B.usrname)) continue;
  fwrite(&A,sizeof(A),1,flot);
}
fwrite(&B,sizeof(B),1,flot);
fclose(flot);
fclose(flot2);
remove("dataDeJoueur.dat");
rename(nouvaux,"dataDeJoueur.dat");
remove(nouvaux);

}

int creerNouvauxCompt(char *nom,const char  *password){
    // if retrun 1 si tout a fait bien si usrmame deja exite 0 ou -1 si le mot de passe went  wrong
FILE *flot;
int cle;
joueur A;


flot=fopen("dataDeJoueur.dat","rb");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}
while (fread(&A,sizeof(A),1,flot))
{
    if(!strcmp(A.usrname,nom)) return 0;

}


fclose(flot);

cle=hash(crypto(password));

flot=fopen("dataDeJoueur.dat","rb");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}

while (fread(&A,sizeof(A),1,flot))
{
    if(A.cle==cle) return -1;

}


fclose(flot);


cle=hash(crypto(password));
A=ccrerJoueur(nom,0,cle);

flot=fopen("dataDeJoueur.dat","ab");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}
fwrite(&A,sizeof(A),1,flot);
fclose(flot);
return 1;
}

int verfieUnCompt(joueur *A, const char *nom,const char *password){
     
    // si  return 0 si compte nexiste pas 
    //si return 1 vrai 
    //si return -1 mot de passe est faux 

int cle,a=0;
joueur B;
FILE *flot;  
cle=hash(crypto(password)); 
flot=fopen("dataDeJoueur.dat","rb");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}
while (fread(&B,sizeof(B),1,flot))
{
    if((!strcmp(B.usrname,nom)))
    {
    if(B.cle==cle){ 
        a=1;
        *A=B;
    }
    else
    {
      a=-1;  
    }
    break;
    }
}
fclose(flot);
return a;
}

  


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
printf("\n%d  hhh %d\n",x,B.score);

//afficher(DixMeilleursScores());

}

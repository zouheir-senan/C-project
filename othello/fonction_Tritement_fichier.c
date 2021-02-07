
#include "fonction_Tritement_fichier.h"




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

int i=0,j;
while (i<10)
{
flot=fopen(JOUEURS,"rb");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}


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
    // if retrun 1 si tout a fait bien si username deja exite 0 ou -1 si le mot de passe went  wrong
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
     
    //si return 0 si compte nexiste pas 
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



void sauvgarde(color T[][8],joueur A,int niveau,color round){
strcat(A.usrname,"jau.dat");  
char N[100]="jeusauvgarde/";
strcat(N,A.usrname);
FILE *flot;
flot=fopen(N,"wb");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}
int i,j;
for(i=0;i<8;i++){
    for ( j = 0; j < 8; j++)
    {
    fwrite(&T[i][j],sizeof(T[i][j]),1,flot);
    }  
}
fwrite(&niveau,sizeof(niveau),1,flot);
fwrite(&round,sizeof(round),1,flot);
fclose(flot);
}

void charegerjeu(joueur A,color T[][8],int *niveau,color *round){
strcat(A.usrname,"jau.dat");
char N[100]="jeusauvgarde/";
strcat(N,A.usrname);
int i,j;
 for (i=0;i<8;i++)
    {
       
        for (j=0;j<8;j++)
        {
            T[i][j]=vide;

        }
    }
FILE *flot;
flot=fopen(N,"rb");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}

for(i=0;i<8;i++){
    for ( j = 0; j < 8; j++)
    {
    fread(&T[i][j],sizeof(T[i][j]),1,flot);
    }  
}

fread(niveau,sizeof(*niveau),1,flot);
fread(round,sizeof(*round),1,flot);
fclose(flot);
return ;
}

void recomencer(color T[][8]){
    int i,j;
    
    for (i=0;i<8;i++)
    {
       
        for (j=0;j<8;j++)
        {
            T[i][j]=vide;

        }
    }
    T[3][3]=noire;
    T[3][4]=blanc;
    T[4][3]=blanc;
    T[4][4]=noire;
    return ;
}

void init_TabAvide(color T[][8]){
int i;
int j;

  
    for (i=0;i<8;i++)
    { 
         for (j=0;j<8;j++)
        {
            T[i][j]=vide;

        }
    }
}
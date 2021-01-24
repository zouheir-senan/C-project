#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define Jeu "jeusauvgarde/Jeu.dat"
typedef enum color color;//couleur
enum color
{
    noire,blanc,vide
};
typedef struct joueur{
    char usrname[20];
    int score;
    int cle;
}joueur;
int **init_tab_dynamic(int x,int y)
{
   int i=0,j=0;
   int **tab=(int**)malloc(x*sizeof(int*));
   if(tab!=NULL)
   {
   for (i=0;i<x;i++)
   {
      tab[i]=(int*)malloc(y*sizeof(int));
      for (j=0;j<y;j++)
      {
          tab[i][j]=-1;
      }
   }
   free(tab);
   }
   else
   {
       printf("erreur");
       exit(-1);
   }
   
   return tab;
}
color **char_tab_dynamic(int x,int y)
{

    int i=0,j=0;
    color **tab=malloc(x*sizeof(color*));
    if(tab!=NULL)
    {
    for (i=0;i<x;i++)
    {
        tab[i]=(color*)malloc(y*sizeof(color));
        for (j=0;j<y;j++)
        {
            tab[i][j]=vide;

        }
    }
//free(tab);
    }
    else
    {
        printf("erreur");
        exit(-1);
    }
    
    return tab;
}
void sauvgarde(color **T,joueur A){
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
fclose(flot);
}

color **charegerjeu(joueur A){
strcat(A.usrname,"jau.dat");
char N[100]="jeusauvgarde/";
strcat(N,A.usrname);

color **T=char_tab_dynamic(8,8);
FILE *flot;
flot=fopen(N,"rb");
if(!flot){
    printf("pb d'ouverture de fichier\n");
    getch();
    exit(-1);
}
int i,j;
for(i=0;i<8;i++){
    for ( j = 0; j < 8; j++)
    {
    fread(&T[i][j],sizeof(T[i][j]),1,flot);
    }  
}


fclose(flot);
return T;
}

color **recomencer(void){
    color **T=char_tab_dynamic(8,8);
    T[3][3]=noire;
    T[3][4]=blanc;
    T[4][3]=blanc;
    T[4][4]=noire;
    return T;
}


void main(){
color **T=char_tab_dynamic(8,8);

T[3][4]=noire;
T[3][5]=blanc;
joueur A;
A.score=0;
strcpy(A.usrname,"zouSr");
A.cle=0;
T[3][2]=blanc;
sauvgarde(T,A);

T[3][6]=blanc;
T=charegerjeu(A);
int i;
int j;
 for(i=0;i<8;i++)
           {
               for(j=0;j<8;j++)
               {
                   if(T[j][7-i]==blanc)
                   {
                       printf("B\t");
                   }
                   if(T[j][7-i]==noire)
                   {
                       printf("N\t");
                   }
                   if((T[j][7-i]!=noire)&&(T[j][7-i]!=blanc))
                   {
                       printf("*\t");
                   }
                   
               }

               
               printf("\n");
            }

} 
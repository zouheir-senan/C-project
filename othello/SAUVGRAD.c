#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "fonction_Tritement_fichier.h"





void main(){
int i;
int j;

color T[8][8];
init_TabAvide(T);
T[3][4]=noire;
T[3][5]=blanc;
joueur A;
A.score=0;
strcpy(A.usrname,"zouSr");
A.cle=0;
T[3][2]=blanc;
sauvgarde(T,A);

T[3][6]=blanc;
charegerjeu(A,T);

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
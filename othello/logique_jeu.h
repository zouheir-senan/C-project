#ifndef LOGIQUE_JEU
#define LOGIQUE_JEU

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>
    #include"fonction_Tritement_fichier.h"

    int min1(int a,int b);
    int max1(int a,int b);
    void remplissage(int K[2][25],color T[8][8],color pi,int *nb);
    void transformerpierre(color T[8][8],int x,int y,color pi);
    int calculnum(color T[][8],color pi);
    int alphabeta(int depth,int etatAI,color COPIE[8][8],color pi,int K[2][25],int alpha,int beta);
    void testvalue(int nb,int K[2][25],int value,int depth,color COPIE[8][8],color pi,int K2[2]);
    int jeu(color T[][8],int K[2][25],int *nb,color pi,int x,int y);
    void jeualeatoire(color T[][8],int K[2][25],int *nb,color pi);
    void jeuAI(color T[][8],int K[2][25],int *nb,color pi,int depth,int K2[2]);
    int testcase(int K[][25],int nb,int x,int y);
    color Adversaire(color pi); 



#endif
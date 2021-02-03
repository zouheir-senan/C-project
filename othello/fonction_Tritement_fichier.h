#ifndef __FONCTION_TRITEMENT_FICHIER
#define __FONCTION_TRITEMENT_FICHIER
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <conio.h>
    #include <math.h>
    #include <time.h>
    #define Jeu "jeusauvgarde/Jeu.dat"

    #define JOUEURS "dataDeJoueur.dat"
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



    int verfieUnCompt(joueur *A, const char *nom,const char *password);
    int creerNouvauxCompt(char *nom,const char  *password);
    void modifierbasedonnees(joueur B);
    void afficher(joueur *liste);
    void chargerdata(void);
    joueur *DixMeilleursScores(void);
    int ajouterjoureur(joueur A);
    int joueurcmp(joueur X,joueur Y);
  joueur ccrerJoueur(char *nom,int score,int cle);
  char *crypto(const char *password);
  int hash(const char *password);
  void sauvgarde(color T[][8],joueur A);
  void init_TabAvide(color T[][8]);
  void recomencer(color T[][8]);
  void charegerjeu(joueur A,color T[][8]);
   
#endif // __FONCTION_TRITEMENT_FICHIER

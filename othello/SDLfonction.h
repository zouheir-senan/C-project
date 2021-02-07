#ifndef __SDLFONCTION_
#define __SDLFONCTION_
        #include <stdio.h>
        #include "SDL2/SDL.h"
        #include <stdlib.h>
        #include <string.h>
        #include "SDL2/SDL_image.h"
        #include "SDL2/SDL_ttf.h"
        
        #ifndef __FONCTION_TRITEMENT_FICHIER
            #include "fonction_Tritement_fichier.h"
        #endif

        
        
        #ifndef LOGIQUE_JEU
         
            #include"logique_jeu.h"
            

        #endif

        #define widthtab_surwidthwin 0.53
        #define heighthtab_surheighthwin 0.841099163
        #define N2 3
        #define N3 5
        typedef struct jeuSDL
            {
                color joueur;
                int x;
                int y;
            }move;

        typedef struct pilemove  // plie des move 
        {   
        int nbr;
        move toutMove[65]; 
        }pilemove;

        int testpile(pilemove pile);
        void ajouterMOVE(int x,int y,color joueur,pilemove *pile);
        void jeupresdent(color T[][8],pilemove *pile);
        int SDL_click(SDL_Rect rec,SDL_Event evt );
        void SDL_ExitWithError(const char *message,SDL_Window *win,SDL_Renderer *renderer);
        void forcerK(int K[2][25],int *nb);
        void Copiejeu(color C[][8],color T[][8]);
        int GitXetYdejeu(int *x,int *y,color C[][8],color T[][8]);
        SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer);
        int SDL_GetCaseclick(SDL_Rect rectab,int x,int y,int *corx,int *cory);
        int makerect(SDL_Rect *rect, int x, int y, int w, int h);
        int Score(color T[][8],color jou);
        SDL_Renderer *changerlatableaux(color T[][8],SDL_Renderer *renderer,SDL_Texture *textblac,SDL_Texture *textnoire,SDL_Texture *textpoint,int K[][25],int nb,SDL_Rect rectab,SDL_Rect rectjeu[][8],int Boll);
        
        // fonction prencipale
        
        SDL_Renderer *Game(SDL_Window *win,SDL_Renderer *renderer,joueur player);

      SDL_Renderer *intrefaceLogin(SDL_Window *win,SDL_Renderer *renderer,joueur *player,int *enterjeu);
        
         
#endif
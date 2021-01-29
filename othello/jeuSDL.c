#include <stdio.h>
#include "SDL2/SDL.h"
#include <stdlib.h>
#include <string.h>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "fonction_Tritement_fichier.h"
#include "logique_jeu.h"
#define widthtab_surwidthwin 0.53
#define heighthtab_surheighthwin 0.841099163

void SDL_ExitWithError(const char *message,SDL_Window *win,SDL_Renderer *renderer)
{

    SDL_Log("ERREUR: %s SDL =>%s\n",message,SDL_GetError());
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    SDL_Quit();
    exit(EXIT_FAILURE);
    
}
int makerect(SDL_Rect *rect, int x, int y, int w, int h)
{
	if (!rect) return -1;
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
	return 0;
}


int SDL_GetCaseclick(SDL_Rect rectab,int x,int y,int *corx,int *cory)
{

int i=0,j=0;
int a=rectab.w/8,b=rectab.h/8;
printf("%d,%d1\n",a,b);
int X=x-rectab.x,Y=y-rectab.y;

while (i<8)
{
    if((X>(a*i))&&(X<(a*(i+1)))) break;
    i++;
}

while (j<8)
{
    if((Y>(b*j))&&(Y<(b*(j+1)))) break;
    j++;
}


if(i>=8||j>=8)
    { *corx=-1,*cory=-1;
    return 0;
    }
*corx=i,*cory=j;

return 1;
}
SDL_Renderer *changerlatableaux(color T[][8],SDL_Renderer *renderer,SDL_Texture *textjeu[][8],int K[][25],int nb,SDL_Rect rectab,SDL_Rect rectjeu[][8]){

SDL_Surface *Noire=IMG_Load("noir.png");
SDL_Surface *Blanc=IMG_Load("blanc.png");
SDL_Surface *Point=IMG_Load("pointvert.png");

    int i=0,j=0;

    int a=rectab.x,b=rectab.y;
    int w=rectab.w/8,h=rectab.h/8;
  

        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                    if(T[i][j]==blanc)
                    {
                    textjeu[i][j]=SDL_CreateTextureFromSurface(renderer,Blanc); 
                    makerect(&rectjeu[i][j],a+w*i,b+h*j,w,h);
                    SDL_RenderCopy(renderer,textjeu[i][j],NULL,&rectjeu[i][j]);
                    }
                    if(T[i][j]==noire)
                    {
                    textjeu[i][j]=SDL_CreateTextureFromSurface(renderer,Noire);  
                    makerect(&rectjeu[i][j],a+w*i,b+h*j,w,h);
                    SDL_RenderCopy(renderer,textjeu[i][j],NULL,&rectjeu[i][j]);
                    }
                   
            }
        }
for(int k=0;k<nb;k++)
{
    i=K[0][k],j=K[1][k];
    textjeu[i][j]=SDL_CreateTextureFromSurface(renderer,Point);  
    makerect(&rectjeu[i][j],a+w*i,b+h*j,w,h);
    SDL_RenderCopy(renderer,textjeu[i][j],NULL,&rectjeu[i][j]);
}
SDL_FreeSurface(Blanc);
SDL_FreeSurface(Noire);
SDL_FreeSurface(Point);
return renderer;


}



SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer)
{
 SDL_Surface *tmp = NULL;
 SDL_Texture *texture = NULL;
 tmp = SDL_LoadBMP(path);
 if(NULL == tmp)
{
 fprintf(stderr, "Erreur SDL_LoadBMP : %s",SDL_GetError());
return NULL;
}
 texture = SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp);
 if(NULL == texture)
{
fprintf(stderr,
"Erreur SDL_CreateTextureFromSurface : %s",
SDL_GetError());
return NULL;
}
return texture;
}


int main(int argc, char* argv[])
{
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    int posX = SDL_WINDOWPOS_CENTERED, posY = SDL_WINDOWPOS_CENTERED, width = 1020, height = 600;
    // intiSDL
    if(SDL_Init(SDL_INIT_VIDEO)!=0) SDL_ExitWithError("Initialisation",NULL,NULL);
    // win
    win=SDL_CreateWindow("Otholle", posX, posY, width, height, SDL_WINDOW_MAXIMIZED|SDL_WINDOW_RESIZABLE);
    if(win==NULL) SDL_ExitWithError("CreateWindow",win,NULL);
    // renderer
    renderer=SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if(renderer==NULL) SDL_ExitWithError("CreateRenderer",win,renderer);
    // player informartion 
    joueur player;

    // fin 

    //texture declartion
    SDL_Texture *TexMain=NULL;
    SDL_Texture *Textab=NULL;
    SDL_Texture *textjeu[8][8];
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++)
        {
            textjeu[i][j]=NULL;
        }
    }

    //fin

    //texture surface
    SDL_Surface *SurfaceMain=NULL;
    SDL_Surface *Surfacetab=NULL;


    //fin
    //IMG_Load
    SurfaceMain=IMG_Load("image1.jpg");
    Surfacetab=IMG_Load("tabe.png");

    //fin
    // ceration texture
    TexMain=SDL_CreateTextureFromSurface(renderer,SurfaceMain);
    Textab=SDL_CreateTextureFromSurface(renderer,Surfacetab);
    // fin
    // free Surface
    SDL_FreeSurface(SurfaceMain);
    SDL_FreeSurface(Surfacetab);

    // fin
    SDL_bool done = SDL_FALSE;
    int faitevnt=1;
     //jeu formatiom




        color T[8][8];
        init_TabAvide(T);
        
        recomencer(T);
        T[3][5]=blanc;
        int K[2][25];
        int K2[2]={-1,-1};
        int nb=9;
        int score;
        int x,y;
        remplissage(K,T,noire,&nb);
        
        //fin
    while (!done)
    {

       
        // rectangle
        SDL_Rect rectMain,rectTabe,rectjeu[8][8];
        SDL_GetWindowSize(win,&(rectMain.w),&(rectMain.h));
        makerect(&rectMain,0,0,rectMain.w,rectMain.h);
      
        makerect(&rectTabe,rectMain.x+rectMain.w*0.4,rectMain.y+rectMain.h*0.15,rectMain.w*widthtab_surwidthwin,rectMain.h*heighthtab_surheighthwin);

        // fin
        // prepartion de renderer 
        if(faitevnt){
        SDL_RenderClear(renderer);
        
        SDL_RenderCopy(renderer,TexMain,NULL,&rectMain);
        SDL_RenderCopy(renderer,Textab,NULL,&rectTabe);
        renderer=changerlatableaux(T,renderer,textjeu,K,nb,rectTabe,rectjeu);
        faitevnt=0;
        }
        SDL_RenderPresent(renderer);
        //fin
        SDL_Event event;
        
        while (SDL_PollEvent(&event))
        {
            
            switch (event.type)
            {


                case SDL_MOUSEBUTTONDOWN:
                
                    if(event.button.button==SDL_BUTTON_LEFT){
                        faitevnt=1;
                    if(SDL_GetCaseclick(rectTabe,event.button.x,event.button.y,&x,&y)) jeu(T,K,&nb,blanc,x,y);
                    else jeuAI(T,K,&nb,noire,3,K2);
                    }

                    break;
                case SDL_QUIT:
                    done=SDL_TRUE;
                 
                    break;
            
                default:
                    break;
            }



        }

    }

    SDL_DestroyTexture(textjeu);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return EXIT_SUCCESS;
}
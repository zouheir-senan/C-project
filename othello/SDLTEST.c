
#include "SDLfonction.h"




int main(int argc, char *argv[]) {

SDL_Window *win = NULL;
SDL_Renderer *renderer = NULL;
joueur player;

int posX = SDL_WINDOWPOS_CENTERED, posY = SDL_WINDOWPOS_CENTERED, width = 820, height = 600;
// init de sdl
if(SDL_Init(SDL_INIT_VIDEO)!=0)
         SDL_ExitWithError("Initialisation",NULL,NULL);
win=SDL_CreateWindow("Othello", posX, posY, width, height, SDL_WINDOW_MAXIMIZED|SDL_WINDOW_RESIZABLE);
    if(win==NULL)
        SDL_ExitWithError("CreateWindow",NULL,NULL);

renderer=SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if(renderer==NULL)
        SDL_ExitWithError("CreateRenderer",win,NULL);
// les intreface
SDL_Surface *icon=NULL;
icon=IMG_Load("image/icon.png");
SDL_SetWindowIcon(win,icon);
 SDL_FreeSurface(icon);

int enterjeu=0;
   renderer=intrefaceLogin(win,renderer,&player,&enterjeu);
   
  if(enterjeu) renderer=Game(win,renderer,player);
//destroy sdl
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(win);
SDL_Quit();



return EXIT_SUCCESS;
}
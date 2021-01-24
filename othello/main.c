#include <stdio.h>
#include "SDL2/SDL.h"
#include <stdlib.h>

void SDL_ExitWithError(const char *message){

    SDL_Log("ERREUR: %s SDL =>%s\n",message,SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
    
}

int main(int argc, char *argv[]) {
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    //SDL_Texture *bitmapTex = NULL;
    //SDL_Surface *bitmapSurface = NULL;
    int posX = 100, posY = 100, width = 320, height = 240;

    if(SDL_Init(SDL_INIT_VIDEO)!=0)
         SDL_ExitWithError("Initialisation");
 

    win = SDL_CreateWindow("Otholle", posX, posY, width, height, SDL_WINDOW_RESIZABLE|SDL_WINDOW_MAXIMIZED);
    if(win==NULL)
        SDL_ExitWithError("CreateWindow");

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if(renderer==NULL)
        SDL_ExitWithError("CreateRenderer");
    //if(SDL_SetRenderDrawColor(renderer,170,170,255,SDL_ALPHA_OPAQUE)!=0)
      //  SDL_ExitWithError("SetRenderDrawColor");
SDL_RenderClear(renderer);   
SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
SDL_Rect rectangle;

rectangle.x = 0;
rectangle.y = 0;
rectangle.w = 50;
rectangle.h = 50;
SDL_RenderFillRect(renderer, &rectangle);
    //bitmapSurface = SDL_LoadBMP("img/hello.bmp");

    if(SDL_RenderClear(renderer)!=0)
        SDL_ExitWithError("RenderClear");

    //if(bitmapSurface==NULL)
      //  SDL_ExitWithError("ERREUR:SDL_LoadBMP");

   /* bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
     if(bitmapTex==NULL)
        SDL_ExitWithError("CreateTextureFromSurface");
         SDL_RenderPresent(renderer);
        */

   
   // SDL_FreeSurface(bitmapSurface);

    while (1) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        SDL_RenderClear(renderer);
        //SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    //SDL_DestroyTexture(bitmapTex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);

    SDL_Quit();

    return EXIT_SUCCESS;
}
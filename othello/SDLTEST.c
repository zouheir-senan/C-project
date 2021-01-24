#include <stdio.h>
#include "SDL2/SDL.h"
#include <stdlib.h>
#include <string.h>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"



int makerect(SDL_Rect *rect, int x, int y, int w, int h)
{
	if (!rect) return -1;
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
	return 0;
}
void SDL_ExitWithError(const char *message){

    SDL_Log("ERREUR: %s SDL =>%s\n",message,SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
    
}
int SDL_click(SDL_Rect rec,SDL_Event evt ){

int x=evt.button.x;
int y=evt.button.y;

if((x>rec.x&&x<(rec.x+rec.w))&&(y>rec.y&&y<(rec.y+rec.h))) return 1;

return 0;
}

int main(int argc, char *argv[]) {

int Sign_in=0,Sign_up=0;

printf("%d\n",SDL_TTF_MAJOR_VERSION);    
SDL_Window *win = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *Tex = NULL;
SDL_Texture *Tex1 = NULL;
SDL_Texture *TexUSER = NULL;
SDL_Texture *TexSign_in = NULL;
SDL_Texture *TexSign_up = NULL;
SDL_Surface *SurfaceSign_up = NULL;
SDL_Surface *SurfaceSign_in = NULL;
SDL_Surface *Surface = NULL;
SDL_Surface *Surface1 = NULL;
SDL_Surface *SurfaceUSER = NULL;
char username[100]={""},T[100]={"1"};

int posX = SDL_WINDOWPOS_CENTERED, posY = SDL_WINDOWPOS_CENTERED, width = 820, height = 600;
if(SDL_Init(SDL_INIT_VIDEO)!=0)
         SDL_ExitWithError("Initialisation");


TTF_Init();
win=SDL_CreateWindow("Otholle", posX, posY, width, height, SDL_WINDOW_MAXIMIZED|SDL_WINDOW_RESIZABLE);
    if(win==NULL)
        SDL_ExitWithError("CreateWindow");





renderer=SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if(renderer==NULL)
        SDL_ExitWithError("CreateRenderer");
/* Creating the surface. */
Surface=SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
Surface1=SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
SurfaceSign_in=SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
SurfaceSign_up=SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
/* Filling the surface with. */

// SDL_FillRect(Surface1, NULL, SDL_MapRGB(Surface1->format, 40, 60, 65));
Surface1=IMG_Load("Login.png");
Surface=IMG_Load("image1.jpg");
SurfaceSign_in=IMG_Load("Sign_in.png");
SurfaceSign_up=IMG_Load("Sign_up.png");

//SDL_FillRect(Surface, NULL, SDL_MapRGB(Surface->format, 65, 65, 65));
Tex = SDL_CreateTextureFromSurface(renderer,Surface);

Tex1 = SDL_CreateTextureFromSurface(renderer,Surface1);
TexSign_in = SDL_CreateTextureFromSurface(renderer,SurfaceSign_in);
TexSign_up = SDL_CreateTextureFromSurface(renderer,SurfaceSign_up);

SDL_FreeSurface(SurfaceSign_in);
SDL_FreeSurface(SurfaceSign_up);

SDL_FreeSurface(Surface);
SDL_FreeSurface(Surface1);
/*  Creating font. */
TTF_Font *USER;
SDL_Color color_write={0,0,0};
USER=TTF_OpenFont("font.ttf",15);

            SDL_bool done = SDL_FALSE;
   SDL_StartTextInput();
            while (!done) {
                SDL_Event event;

                SDL_Rect rectangle,rectangle1,rectangleIN,rectangleUP,rectangleUsr,rectanglePasssWorrd,rectangleUserText;
                
                SDL_GetWindowSize(win,&(rectangle.w),&(rectangle.h));
                rectangle.x =0;
                rectangle.y =0;
                rectangle1.w=rectangle.w/4;
                rectangle1.h=rectangle.h/4;
                rectangle1.x=(rectangle.w*3)/8;
                rectangle1.y=(rectangle.h*3)/8;
                rectangleIN.x=rectangle1.x*1.05;
                rectangleIN.y=rectangle1.y*1.05+ rectangle1.h;
                rectangleIN.h=(rectangle1.h*2)/8;
                rectangleIN.w=(rectangle1.w*3)/8;
                rectangleUP.x= (rectangle1.x+rectangle1.w-rectangleIN.w)*0.95;
                rectangleUP.y=rectangle1.y*1.05+ rectangle1.h;
                rectangleUP.h=(rectangle1.h*2)/8;
                rectangleUP.w=(rectangle1.w*3)/8;
            rectangleUsr.x=rectangle1.x+rectangle1.w/3;
            rectangleUsr.y=rectangle1.y+rectangle1.h*0.2;
            rectangleUsr.w=rectangle1.w*0.6;
            rectangleUsr.h=rectangle1.h*0.2;
            rectanglePasssWorrd.x=rectangle1.x+rectangle1.w/3;
            rectanglePasssWorrd.y=rectangle1.y+rectangle1.h*0.6;
            rectanglePasssWorrd.w=rectangle1.w*0.6;
            rectanglePasssWorrd.h=rectangle1.h*0.2;
            

            
                SurfaceUSER=TTF_RenderText_Solid(USER,username,color_write);
                TexUSER = SDL_CreateTextureFromSurface(renderer,SurfaceUSER);
                int h,w;
                SDL_QueryTexture(TexUSER,NULL,NULL,&w,&h);
                makerect(&rectangleUserText,rectangleUsr.x,rectangleUsr.y*1.02,w,h);
                SDL_FreeSurface(SurfaceUSER);

                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer,Tex,NULL, &rectangle);
                if(Sign_in||Sign_up){
                    SDL_RenderCopy(renderer,Tex1,NULL, &rectangle1);
                if(Sign_in){
                    rectangleIN.x=rectangle1.x+rectangle1.w*0.5-rectangleIN.w*0.5;
                    rectangleUP.w=rectangleUP.h=0;
                    }
                else{
                    rectangleUP.x=rectangle1.x+rectangle1.w*0.5-rectangleIN.w*0.5;
                    rectangleIN.w=rectangleIN.h=0;
                    }
                    }
                if((!Sign_up&&Sign_in)||(!Sign_up&&!Sign_up))SDL_RenderCopy(renderer,TexSign_in,NULL, &rectangleIN);
                if((!Sign_in&&Sign_up)||(!Sign_up&&!Sign_up))SDL_RenderCopy(renderer,TexSign_up,NULL, &rectangleUP);
              

              
                
                if(strlen(username)>(int)(rectangleUsr.w*0.1)){

                  int  n=(int)(rectangleUsr.w*0.1);
                           for (size_t i = 0; i <n-1; i++)
                           {
                               T[i]=username[i];
                           }
                           T[n-1]='\0';
                            strcpy(username,T);
                        
                            puts(username);
                            printf("%d\n",n);
                        
                }
                SDL_SetRenderDrawColor(renderer,56,56,56, SDL_ALPHA_OPAQUE);
                // SDL_RenderFillRect(renderer,&rectangleIN);
                // SDL_RenderFillRect(renderer,&rectangleUP);
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                // SDL_RenderFillRect(renderer,&rectangleUsr);
                // SDL_RenderFillRect(renderer,&rectanglePasssWorrd);
                //SDL_SetTextInputRect(&rectangleUsr);
                //SDL_RenderSetClipRect(renderer,&rectangleUsr);
               SDL_RenderCopy(renderer,TexUSER,NULL, &rectangleUserText);
                //SDL_RenderCopy(renderer,TexUSER,NULL,&rectangleUsr);
                SDL_RenderPresent(renderer);
             
                while (SDL_PollEvent(&event)){

                    switch(event.type){
                         



                        case SDL_MOUSEBUTTONDOWN:
                            if(event.button.button==SDL_BUTTON_LEFT){
                                printf("passworrd %d\t ",SDL_click(rectanglePasssWorrd,event));
                                printf("User %d \t",SDL_click(rectangleUsr,event));
                                if(SDL_click(rectangleIN,event)) Sign_in=1;
                                if(SDL_click(rectangleUP,event)) Sign_up=1;
                                 printf("Sgin up %d\t",SDL_click(rectangleUP,event));
                                 printf("Sgin in %d\n",SDL_click(rectangleIN,event));


                            }

                            
                           break;
                        
                        case SDL_KEYDOWN:
                        if(event.key.keysym.sym==SDLK_BACKSPACE && strlen(username)>0) {
                          int  n=strlen(username);
                           for (size_t i = 0; i <n-1; i++)
                           {
                               T[i]=username[i];
                           }
                           T[n-1]='\0';
                            strcpy(username,T);
                        
                            puts(username);
                            printf("%d\n",n);
                        }

                        
                        break;
                        
                        case SDL_TEXTINPUT:

                            
                            if(event.type==SDL_TEXTINPUT&&strlen(username)<(int)(rectangleUsr.w*0.1)) {strcat(username,event.text.text);
                             int  n=strlen(username);
                            puts(username);
                             printf("%d\n", rectangleUsr.w);}
                            
                       
                           break;

                        case SDL_QUIT:
                            done=SDL_TRUE;
                            break;


                        default:
                        
                        
                            break;

                    }
                    
                  

                }
            }
SDL_StopTextInput();
TTF_Quit();
SDL_DestroyTexture(Tex);
SDL_DestroyTexture(Tex1);
SDL_DestroyTexture(TexUSER);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(win);
SDL_Quit();

    return EXIT_SUCCESS;
}
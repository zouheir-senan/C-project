#include <stdio.h>
#include "SDL2/SDL.h"
#include <stdlib.h>
#include <string.h>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "fonction_Tritement_fichier.h"
#include "logique_jeu.h"
#include<time.h>
#define widthtab_surwidthwin 0.53
#define heighthtab_surheighthwin 0.841099163
typedef struct jeuSDL
{
    color joueur;
    int x;
    int y;
}move;
typedef struct pliemove  // plie des move 
{   
int nbr;
move toutMove[65]; 
}pliemove;

int testpile(pliemove pile)
{
if(pile.nbr==-1) return 0;
else return 1;
}
void ajouterMOVE(int x,int y,color joueur,pliemove *pile)
{
pile->nbr++;
pile->toutMove[pile->nbr].x=x;
pile->toutMove[pile->nbr].y=y;
pile->toutMove[pile->nbr].joueur=joueur;
return;
}
void jeupresdent(color T[][8],pliemove pile)
{
    color COPIE[8][8];
    init_TabAvide(COPIE);
    recomencer(COPIE);
    if(testpile(pile))
    {
        int x=pile.toutMove[pile.nbr].x;
        int y=pile.toutMove[pile.nbr].y;
        T[x][y]=vide;
        pile.nbr--;
    for(int g=0;g<pile.nbr;g++)
    {
    transformerpierre(COPIE,pile.toutMove[g].x,pile.toutMove[g].y,pile.toutMove[g].joueur);       
    }
    for(int m=0;m<8;m++)
    {
    for(int j=0;j<8;j++)
    {
                    T[m][j]=COPIE[m][j];
    }
    }
    }
    return;


}
 
int SDL_click(SDL_Rect rec,SDL_Event evt ){

int x=evt.button.x;
int y=evt.button.y;

if((x>rec.x&&x<(rec.x+rec.w))&&(y>rec.y&&y<(rec.y+rec.h))) return 1;

return 0;
}

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
SDL_Renderer *changerlatableaux(color T[][8],SDL_Renderer *renderer,SDL_Texture *textblac,SDL_Texture *textnoire,SDL_Texture *textpoint,int K[][25],int nb,SDL_Rect rectab,SDL_Rect rectjeu[][8],int Boll){



    int i=0,j=0;

    int a=rectab.x,b=rectab.y;
    int w=rectab.w/8,h=rectab.h/8;
  

        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                    if(T[i][j]==blanc)
                    {
                    
                    makerect(&rectjeu[i][j],a+w*i,b+h*j,w,h);
                    SDL_RenderCopy(renderer,textblac,NULL,&rectjeu[i][j]);
                    }
                    if(T[i][j]==noire)
                    {
                    
                      
                    makerect(&rectjeu[i][j],a+w*i,b+h*j,w,h);
                    SDL_RenderCopy(renderer,textnoire,NULL,&rectjeu[i][j]);
                    }
                   
            }
        }
if (Boll)
{
  for(int k=0;k<nb;k++)
    {
        i=K[0][k],j=K[1][k];
        
        makerect(&rectjeu[i][j],a+w*i,b+h*j,w,h);
        SDL_RenderCopy(renderer,textpoint,NULL,&rectjeu[i][j]);
    }
}

return renderer;


}



SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer)
{
 SDL_Surface *tmp = NULL;
 SDL_Texture *texture = NULL;
 tmp=IMG_Load(path);
 if(NULL==tmp)
{
 fprintf(stderr, "Erreur SDL_LoadBMP : %s",SDL_GetError());
return NULL;
}
 texture=SDL_CreateTextureFromSurface(renderer, tmp);
 SDL_FreeSurface(tmp);
 if(NULL==texture)
{
fprintf(stderr,"Erreur SDL_CreateTextureFromSurface : %s",SDL_GetError());
return NULL;
}
return texture;
}

int Score(color T[][8],color jou)
{
int n=0;
for (int i = 0; i <8; i++)
{
    for (int j=0; j<8;j++)
    {
        if(T[i][j]==jou) n++;
    }
    
}
return n;
}

int main(int argc, char* argv[])
{
    SDL_Window *win = NULL;
    SDL_Renderer *renderer = NULL;
    int posX = SDL_WINDOWPOS_CENTERED, posY = SDL_WINDOWPOS_CENTERED, width = 1020, height = 600;
    int machine=0,deujoueur=0,joueur1,joueur2,recm=0,bloq1=0,bloq=0,afficheTop=0,affichemove=0,nivaux=0,win1=1,win2=0,win3=0,Boll=1;
    // intiSDL
    if(SDL_Init(SDL_INIT_VIDEO)!=0) SDL_ExitWithError("Initialisation",NULL,NULL);
    // win
    win=SDL_CreateWindow("Otholle", posX, posY, width, height,SDL_WINDOW_MAXIMIZED|SDL_WINDOW_RESIZABLE); //
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
    SDL_Texture *textBlanc=NULL;
    SDL_Texture *textNoire=NULL;
    SDL_Texture *textPoint=NULL;
    SDL_Texture *text2joueur=loadImage("image/2joueur.png",renderer);
    SDL_Texture *textcolorblanc=loadImage("image/colorblach.png",renderer);
    SDL_Texture *textcolornoire=loadImage("image/colornoire.png",renderer);
    SDL_Texture *textdifficle=loadImage("image/Difficile.png",renderer);
    SDL_Texture *textfacile=loadImage("image/facile.png",renderer);
    SDL_Texture *textliste=loadImage("image/list desmovement.png",renderer);
    SDL_Texture *textmove=loadImage("image/move.png",renderer);
    SDL_Texture *textmoyen=loadImage("image/moyen.png",renderer);
    SDL_Texture *textrecm=loadImage("image/RECOMMENCER.png",renderer);
    SDL_Texture *text10top=loadImage("image/TOP10.png",renderer);




   

    //fin



    //texture surface
    SDL_Surface *SurfaceMain=NULL;
    SDL_Surface *Surfacetab=NULL;
    SDL_Surface *Noire=NULL;
    SDL_Surface *Blanc=NULL;
    SDL_Surface *Point=NULL;    
    //fin
    //IMG_Load
    SurfaceMain=IMG_Load("image1.jpg");
    
    Surfacetab=IMG_Load("tabe.png");
    Noire=IMG_Load("noir.png");
    Blanc=IMG_Load("blanc.png");
    Point=IMG_Load("pointvert.png");
    
    //fin
    // ceration texture
    TexMain=SDL_CreateTextureFromSurface(renderer,SurfaceMain);
    Textab=SDL_CreateTextureFromSurface(renderer,Surfacetab);
    textBlanc=SDL_CreateTextureFromSurface(renderer,Blanc);
    textNoire=SDL_CreateTextureFromSurface(renderer,Noire);
    textPoint=SDL_CreateTextureFromSurface(renderer,Point);


    // fin
    // free Surface
    SDL_FreeSurface(SurfaceMain);
    SDL_FreeSurface(Surfacetab);
    SDL_FreeSurface(Blanc);
    SDL_FreeSurface(Noire);
    SDL_FreeSurface(Point);

    // fin
    SDL_bool done = SDL_FALSE;
    int faitevnt=1;
     //jeu formatiom




        color T[8][8];
        init_TabAvide(T);
        
        recomencer(T);
 
        int K[2][25];
        int K2[2]={-1,-1};
        int nb=9;
        int score;
        int x,y;

       color pi=vide,round=vide;
       
        srand(time(NULL));
        
       int n=rand()%2;
       if(n)round=noire;
       else round=blanc;
        remplissage(K,T,round,&nb);
        printf("%d\n",n);
        //fin
    while (!done)
    {

       
        // rectangle
        SDL_Rect rectMain,rectTabe,rectjeu[8][8],rectVSjoueur,rectVSOrdiN1,rectVSOrdiN2,rectVSOrdiN3,rectBlanc,rectNoire,rectRecm,rectAffichierMove,rectTOPE10,rectlistemovem,rect1[3][64],rect2[2][10],rcetscorenoire,rectscoreblanc;
        SDL_GetWindowSize(win,&(rectMain.w),&(rectMain.h));
        makerect(&rectMain,0,0,rectMain.w,rectMain.h);
      
        makerect(&rectTabe,rectMain.x+rectMain.w*0.4,rectMain.y+rectMain.h*0.15,rectMain.w*widthtab_surwidthwin,rectMain.h*heighthtab_surheighthwin);
        
        int btn_x=rectMain.x+rectMain.w*0.5-rectMain.w*0.1;
        // fin
        // prepartion de renderer 
        // le coix de joueur
        if(win1)
        {
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,TexMain,NULL,&rectMain);
        
        
        makerect(&rectVSOrdiN1,btn_x,rectMain.y+rectMain.h*0.075+rectMain.h*0.05,rectMain.w*0.2,rectMain.h*0.15);
        SDL_RenderCopy(renderer,textfacile,NULL,&rectVSOrdiN1);

        makerect(&rectVSOrdiN2,btn_x,rectVSOrdiN1.y+rectMain.h*0.17,rectMain.w*0.2,rectMain.h*0.15);
        SDL_RenderCopy(renderer,textmoyen,NULL,&rectVSOrdiN2);
      
        makerect(&rectVSOrdiN3,btn_x,rectVSOrdiN2.y+rectMain.h*0.17,rectMain.w*0.2,rectMain.h*0.15);
        SDL_RenderCopy(renderer,textdifficle,NULL,&rectVSOrdiN3);
       
        makerect(&rectVSjoueur,btn_x,rectVSOrdiN3.y+rectMain.h*0.17,rectMain.w*0.2,rectMain.h*0.15);
        SDL_RenderCopy(renderer,text2joueur,NULL,&rectVSjoueur);



        SDL_RenderPresent(renderer);
        }
        //fin
       
        // le coix de color
       if(win2)
       {
        SDL_RenderClear(renderer);
         
        SDL_RenderCopy(renderer,TexMain,NULL,&rectMain);
        makerect(&rectBlanc,btn_x,rectMain.y+rectMain.h*0.075+rectMain.h*0.25,rectMain.w*0.2,rectMain.h*0.15);
        SDL_RenderCopy(renderer,textcolorblanc,NULL,&rectBlanc);
        makerect(&rectNoire,btn_x,rectBlanc.y+rectMain.h*0.17,rectMain.w*0.2,rectMain.h*0.15);
        SDL_RenderCopy(renderer,textcolornoire,NULL,&rectNoire);
        SDL_RenderPresent(renderer);

       
    
       }
       
        // fin

        // 
        
        if(win3)
        {
            if(nivaux==-1) Boll=1;

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,TexMain,NULL,&rectMain);
        SDL_RenderCopy(renderer,Textab,NULL,&rectTabe);
        
        makerect(&rectRecm,rectMain.x+rectMain.w*0.01,rectMain.y+rectMain.h*0.01,rectMain.w*0.1,rectMain.h*0.13);
        SDL_RenderCopy(renderer,textrecm,NULL,&rectRecm);
       
        makerect(&rectAffichierMove,rectRecm.x +rectRecm.w+rectMain.w*0.01 ,rectRecm.y,rectMain.w*0.1,rectMain.h*0.13);
        SDL_RenderCopy(renderer,textmove,NULL,&rectAffichierMove);
        
        makerect(&rectTOPE10,rectAffichierMove.x +rectAffichierMove.w+rectMain.w*0.01 ,rectRecm.y,rectMain.w*0.1,rectMain.h*0.13);
        SDL_RenderCopy(renderer,text10top,NULL,&rectTOPE10);
       
        makerect(&rectlistemovem,rectRecm.x,rectRecm.y+rectRecm.h+ rectMain.h*0.01,rectMain.w-rectTabe.w-rectMain.w*0.2,rectMain.h*0.75);
        SDL_RenderCopy(renderer,textliste,NULL,&rectlistemovem);


        renderer=changerlatableaux(T,renderer,textBlanc,textNoire,textPoint,K,nb,rectTabe,rectjeu,Boll); 
       
        SDL_RenderPresent(renderer);
        }

      
        if(round==Adversaire(pi))
        {

                                
          SDL_Delay(500);                       
        jeualeatoire(T,K,&nb,Adversaire(pi)),Boll=1;

        round=Adversaire(round);
        }
        SDL_Event event;
        
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {


                case SDL_MOUSEBUTTONDOWN:
                
                    if(event.button.button==SDL_BUTTON_LEFT){
                        
                        
                       if(win3)
                        {
                            
                            if(nivaux==-1)
                            {
                                if(round==pi)
                                {
                                    if(SDL_GetCaseclick(rectTabe,event.button.x,event.button.y,&x,&y)) jeu(T,K,&nb,pi,x,y);
                                
                                }
                                else 
                                {
                                    if(SDL_GetCaseclick(rectTabe,event.button.x,event.button.y,&x,&y)) jeu(T,K,&nb,Adversaire(pi),x,y);
                                
                                }
                                round=Adversaire(round);

                            }
                            if(nivaux==1)
                            {
                                printf("aa");
                                if(round==pi)
                                {
                                if(SDL_GetCaseclick(rectTabe,event.button.x,event.button.y,&x,&y)) jeu(T,K,&nb,pi,x,y),Boll=0;
                                }
                            round=Adversaire(round);
                            }
                            //  if(SDL_GetCaseclick(rectTabe,event.button.x,event.button.y,&x,&y)) jeu(T,K,&nb,blanc,x,y);
                    // else jeuAI(T,K,&nb,noire,8,K2);//jeualeatoire(T,K,&nb,noire);
                        }
                    
                      
                        if(win2)
                        {
                        if(SDL_click(rectBlanc,event)) pi=blanc;
                        if(SDL_click(rectNoire,event)) pi=noire;
                        
                        if(pi!=vide) win1=0,win2=0,win3=1;
                        } 
                        if(win1){
                        if(SDL_click(rectVSjoueur,event)) nivaux=-1;
                        if(SDL_click(rectVSOrdiN1,event)) nivaux=1;
                        if(SDL_click(rectVSOrdiN2,event)) nivaux=2;
                        if(SDL_click(rectVSOrdiN3,event)) nivaux=3;
                        // if(nivaux==1)
                        // {
                        //     if(pi==round)
                        //     { 
                        //         Boll=1;
                        //     }
                        //     else  jeualeatoire(T,K,&nb,Adversaire(pi)), Boll=0;
                    
                        // }
                        if(nivaux!=0) {win1=0;win2=1;win3=0;}
                        }
                    }

                    break;
                     
                case  SDL_MOUSEBUTTONUP:
                
                    if(event.button.button==SDL_BUTTON_LEFT)
                    {
                           
                       if(win3)
                       {
                            if(nivaux==1)
                            {
                              
                                printf("bbaacc\n");
                               
                            }

                       }
                    
                            
                     
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

    SDL_DestroyTexture(textPoint);
    SDL_DestroyTexture(textBlanc);
    SDL_DestroyTexture(textNoire);


    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return EXIT_SUCCESS;
}
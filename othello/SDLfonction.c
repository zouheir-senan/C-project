#include "SDLfonction.h"
int testpile(pilemove pile)
{
if(pile.nbr==-1) return 0;
else return 1;
}
void ajouterMOVE(int x,int y,color joueur,pilemove *pile)
{
pile->nbr++;
pile->toutMove[pile->nbr].x=x;
pile->toutMove[pile->nbr].y=y;
pile->toutMove[pile->nbr].joueur=joueur;
return;
}
void jeupresdent(color T[][8],pilemove *pile)
{
    color COPIE[8][8];
    init_TabAvide(COPIE);
    recomencer(COPIE);
    if(testpile(*pile))
    {
        int x=(*pile).toutMove[pile->nbr].x;
        int y=(*pile).toutMove[pile->nbr].y;
        T[x][y]=vide;
        (*pile).nbr--;
    for(int g=0;g<=(*pile).nbr;g++)
    {
    transformerpierre(COPIE,(*pile).toutMove[g].x,(*pile).toutMove[g].y,(*pile).toutMove[g].joueur);       
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

int SDL_click(SDL_Rect rec,SDL_Event evt )
{

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
int GitXetYdejeu(int *x,int *y,color C[][8],color T[][8])
{
    for (int i = 0; i <8; i++)
    {
        for (int j=0; j<8;j++)
        {
            if(C[i][j]==vide && T[i][j]!=vide){*x=i;*y=j ;return 1;} 
        }
        
    }
    return 0;

}
void Copiejeu(color C[][8],color T[][8])
{
for (int i = 0; i <8; i++)
    {
        for (int j=0; j<8;j++)
        {
            C[i][j]=T[i][j];
        }
        
    }
    return;
}

 void forcerK(int K[2][25],int *nb)
 {
     if(*nb>=25)
     {
         for(int i=25;i<=(*nb);i++)
         { 
            K[0][i]=K[1][i]=-1;
   
         }
     }

 }
SDL_Renderer *intrefaceLogin(SDL_Window *win,SDL_Renderer *renderer,joueur *player,int *enterjeu)
{
    

int Sign_in=0,Sign_up=0,clickUser=0,clickPass=0,AfficherUser=0,AfficherPass=0,textinput=0,verfie=0,AfficherMessage=0;
int Sign_in1=0;
int Sign_up1=0;



SDL_Texture *Tex = NULL;
SDL_Texture *Tex1 = NULL;
SDL_Texture *TexUSER = NULL;
SDL_Texture *TexPass = NULL;
SDL_Texture *TexSign_in = NULL;
SDL_Texture *TexSign_up = NULL;
SDL_Texture *Texverfie = NULL;
SDL_Texture *TexverfieText = NULL;
SDL_Surface *SurfaceSign_up = NULL;
SDL_Surface *SurfaceSign_in = NULL;
SDL_Surface *Surface = NULL;
SDL_Surface *Surface1 = NULL;
SDL_Surface *SurfaceUSER = NULL;
SDL_Surface *SurfacePass = NULL;
SDL_Surface *Surfaceverfie = NULL;
SDL_Surface *SurfaceverfieText = NULL;
char username[100]={""},T[100]={"1"},PassWord[100]={""},MotDePasse[100]={""},message[100]={""};


TTF_Init();






/* Creating the surface. */
// Surface=SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
// Surface1=SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
// SurfaceSign_in=SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
// SurfaceSign_up=SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
/* Filling the surface with. */

// SDL_FillRect(Surface1, NULL, SDL_MapRGB(Surface1->format, 40, 60, 65));
Surface1=IMG_Load("image/Login.png");
Surface=IMG_Load("image/image1.jpg");
SurfaceSign_in=IMG_Load("image/Sign_in.png");
SurfaceSign_up=IMG_Load("image/Sign_up.png");
Surfaceverfie=IMG_Load("image/message.png");
//SDL_FillRect(Surface, NULL, SDL_MapRGB(Surface->format, 65, 65, 65));
Tex = SDL_CreateTextureFromSurface(renderer,Surface);

Tex1 = SDL_CreateTextureFromSurface(renderer,Surface1);
TexSign_in = SDL_CreateTextureFromSurface(renderer,SurfaceSign_in);
TexSign_up = SDL_CreateTextureFromSurface(renderer,SurfaceSign_up);
Texverfie=SDL_CreateTextureFromSurface(renderer,Surfaceverfie);
SDL_FreeSurface(Surfaceverfie);
SDL_FreeSurface(SurfaceSign_in);
SDL_FreeSurface(SurfaceSign_up);

SDL_FreeSurface(Surface);
SDL_FreeSurface(Surface1);
/*  Creating font. */
TTF_Font *USER;
SDL_Color color_write={0,0,0};
USER=TTF_OpenFont("image/font.ttf",15);
SDL_Surface *icon=NULL;
icon=IMG_Load("image/icon.png");
SDL_SetWindowIcon(win,icon);
 SDL_FreeSurface(icon);
    SDL_bool done = SDL_FALSE;
    SDL_StartTextInput();
     while (!done)
        {
                    SDL_Event event;

                    SDL_Rect rectangle,rectangle1,rectangleIN,rectangleUP,rectangleUsr,rectanglePasssWorrd,rectangleUserText,rectanglePassText,rectangleverfieText,rectangleverfie;
                    
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
                

                
                    if(textinput)
                        { 
                            SurfaceUSER=TTF_RenderText_Blended(USER,username,color_write);
                            TexUSER = SDL_CreateTextureFromSurface(renderer,SurfaceUSER);
                            int h,w;
                            SDL_QueryTexture(TexUSER,NULL,NULL,&w,&h);
                            makerect(&rectangleUserText,rectangleUsr.x,rectangleUsr.y*1.02,w,h);
                            SDL_FreeSurface(SurfaceUSER);
                            SurfacePass=TTF_RenderText_Blended(USER,MotDePasse,color_write);
                            TexPass = SDL_CreateTextureFromSurface(renderer,SurfacePass);
                            
                            SDL_QueryTexture(TexPass,NULL,NULL,&w,&h);
                            makerect(&rectanglePassText,rectanglePasssWorrd.x,rectanglePasssWorrd.y*1.02,w,h);
                            SDL_FreeSurface(SurfacePass);
                            textinput=0;
                        }

                    SDL_RenderClear(renderer);
                    SDL_RenderCopy(renderer,Tex,NULL, &rectangle);
                    if(Sign_in||Sign_up)
                    {
                        SDL_RenderCopy(renderer,Tex1,NULL, &rectangle1);
                    if(Sign_in)
                        {
                        Sign_in1=0;
                        rectangleIN.x=rectangle1.x+rectangle1.w*0.5-rectangleIN.w*0.5;
                        rectangleUP.w=rectangleUP.h=0;
                    
                        }
                    else
                        {
                        Sign_up1=0;
                        rectangleUP.x=rectangle1.x+rectangle1.w*0.5-rectangleIN.w*0.5;
                        rectangleIN.w=rectangleIN.h=0;
                        }
                    }
                    if((!Sign_up&&Sign_in)||(!Sign_up&&!Sign_up))SDL_RenderCopy(renderer,TexSign_in,NULL, &rectangleIN);
                    if((!Sign_in&&Sign_up)||(!Sign_up&&!Sign_up))SDL_RenderCopy(renderer,TexSign_up,NULL, &rectangleUP);
                
                    

                
                    
                    if(strlen(username)>(int)(rectangleUsr.w*0.1))
                    {

                              int  n=(int)(rectangleUsr.w*0.1);
                                for (size_t i = 0; i <n-1; i++)
                                {
                                    T[i]=username[i];
                                }
                                T[n-1]='\0';
                                    strcpy(username,T);
                            
                    }
                    if(strlen(PassWord)>(int)(rectangleUsr.w*0.1))
                        {

                        int  n=(int)(rectangleUsr.w*0.1);
                                for (size_t i = 0; i <n-1; i++)
                                {
                                    T[i]=PassWord[i];
                                }
                                T[n-1]='\0';
                                    strcpy(PassWord,T);      
                        }
                
                    
                    if(AfficherPass)SDL_RenderCopy(renderer,TexPass,NULL, &rectanglePassText);
                    if(AfficherUser)SDL_RenderCopy(renderer,TexUSER,NULL, &rectangleUserText);

                

                    if(verfie)
                    {
                        SurfaceverfieText=TTF_RenderText_Blended(USER,message,color_write);
                        TexverfieText= SDL_CreateTextureFromSurface(renderer,SurfaceverfieText);
                        int h,w;
                        SDL_QueryTexture(TexverfieText,NULL,NULL,&w,&h);
                        makerect(&rectangleverfieText,rectangle1.x+rectangle1.w*0.1,rectangle1.y-rectangle1.h*0.2,w,h);
                        
                        SDL_FreeSurface(SurfaceverfieText);
                    
                    
                        verfie=0;
                    }
                    makerect(&rectangleverfie,rectangle1.x,rectangle1.y-rectangle1.h*0.27,rectangle1.w,rectangle1.h*0.27);
                    if(AfficherMessage)SDL_RenderCopy(renderer,Texverfie,NULL, &rectangleverfie);

                    if(AfficherMessage)SDL_RenderCopy(renderer,TexverfieText,NULL, &rectangleverfieText);
                    //SDL_RenderCopy(renderer,TexUSER,NULL,&rectangleUsr);
                    SDL_RenderPresent(renderer);
                
                    while (SDL_PollEvent(&event))
                    {

                        switch(event.type)
                        {
                            

                            case SDL_WINDOWEVENT:
                                if((event.window.event==SDL_WINDOWEVENT_MOVED)||(event.window.event==SDL_WINDOWEVENT_RESIZED)||(event.window.event==SDL_WINDOWEVENT_SIZE_CHANGED)) verfie=1,textinput=1;

                            case SDL_MOUSEBUTTONDOWN:
                                if(event.button.button==SDL_BUTTON_LEFT){
                            
                                    if(SDL_click(rectangleIN,event)&&Sign_in==1) Sign_in1=1;
                                    if(SDL_click(rectangleUP,event)&&Sign_up==1) Sign_up1=1;
                                    if(SDL_click(rectangleIN,event)) Sign_in=1;
                                    if(SDL_click(rectangleUP,event)) Sign_up=1;
                                    
                                
                                    if(SDL_click(rectangleUsr,event)&&(Sign_in||Sign_up)) { clickUser=1;clickPass=0;AfficherUser=1;}
                                    if(SDL_click(rectanglePasssWorrd,event)&&(Sign_in||Sign_up)) {clickPass=1;clickUser=0;AfficherPass=1;}
                                    if(Sign_in1)
                                    {
                                        verfie=1;
                                        int a;
                                        a=verfieUnCompt(player,username,PassWord);
                                        if(a==-1)
                                        {
                                            strcpy(PassWord,""); 
                                            strcpy(MotDePasse,""); 
                                            strcpy(username,""); 
                                            textinput=1;
                                            strcpy(message,"le mot de passe est faux");
                                           
                                        }
                                        if(a==1)
                                        {
                                            *enterjeu=1;
                                            strcpy(message,"good welcome");
                                            SDL_DestroyTexture(TexSign_in);
                                            SDL_DestroyTexture(TexSign_in);
                                            SDL_DestroyTexture(TexPass);
                                            SDL_DestroyTexture(Tex);
                                            SDL_DestroyTexture(Tex1);
                                            SDL_DestroyTexture(TexUSER);
                                            return renderer;

                                        }
                                        if(a==0)
                                        {
                                            strcpy(PassWord,""); 
                                            strcpy(MotDePasse,""); 
                                            strcpy(username,""); 
                                            textinput=1;
                                            strcpy(message,"cette compte nexiste pas ");
                                            
                                        }
                                        AfficherMessage=1;
                                    }

                                    if(Sign_up1)
                                    {
                                        verfie=1;
                                        int b;
                                        b=creerNouvauxCompt(username,PassWord);
                                        if(b==1)
                                        {
                                            strcpy(PassWord,""); 
                                            strcpy(MotDePasse,""); 
                                            strcpy(username,""); 
                                            textinput=1;

                                            strcpy(message," fait maintenant  Sign in");
                                            Sign_in=1;
                                            Sign_in1=0;
                                            Sign_up=0;
                                            Sign_up1=0;
                                            AfficherMessage=1;
                                         }
                                        if(b==0)
                                        {
                                            strcpy(PassWord,""); 
                                            strcpy(MotDePasse,""); 
                                            strcpy(username,"");
                                            textinput=1; 

                                            strcpy(message,"vous avez deja Sign up");
                                            Sign_in=1;
                                            Sign_in1=0;
                                            Sign_up=0;
                                            Sign_up1=0;
                                            AfficherMessage=1;

                                        }
                                        if(b==-1)
                                        {
                                            strcpy(PassWord,""); 
                                            strcpy(MotDePasse,""); 
                                            textinput=1;

                                            strcpy(message," changer password");
                                            Sign_up=1;
                                            Sign_up1=0;
                                            Sign_in=0;
                                            Sign_in1=0;
                                            AfficherMessage=1;
                                        }
                                    }
                                    
                                }

                                
                            break;
                            
                            case SDL_KEYDOWN:
                            if(event.key.keysym.sym==SDLK_BACKSPACE ) {
                                textinput=1;
                            if(strlen(username)>0 && clickUser){
                            int  n=strlen(username);
                            for (size_t i = 0; i <n-1; i++)
                            {
                                T[i]=username[i];
                            }
                            T[n-1]='\0';
                            strcpy(username,T);
                            }
                            if(strlen(PassWord)>0 && clickPass)
                                {
                                int  n=strlen(PassWord);
                                for (size_t i = 0; i <n-1; i++)
                                {
                                T[i]=PassWord[i];
                                }
                                T[n-1]='\0';
                                strcpy(PassWord,T);
                            
                                for (size_t i = 0; i <n-1; i++)
                                {
                                T[i]=MotDePasse[i];
                                }
                                T[n-1]='\0';
                                strcpy(MotDePasse,T);
                                }
                            
                            }
                            

                            
                            break;
                            
                            case SDL_TEXTINPUT:

                                
                            textinput=1;
                                
                                if(clickUser){
                                if(strlen(username)<(int)(rectangleUsr.w*0.1))
                                {
                                
                                strcat(username,event.text.text);
                            
                                // puts(username);
                                }
                                }
                                if(clickPass){

                                if(strlen(PassWord)<(int)(rectanglePasssWorrd.w*0.1))
                                {
                                strcat(PassWord,event.text.text);
                                strcat(MotDePasse,"*");
                                
                                // puts(PassWord);
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
SDL_StopTextInput();
TTF_Quit();
SDL_DestroyTexture(TexSign_in);
SDL_DestroyTexture(TexSign_in);
SDL_DestroyTexture(TexPass);
SDL_DestroyTexture(Tex);
SDL_DestroyTexture(Tex1);
SDL_DestroyTexture(TexUSER); 
return renderer;
}



SDL_Renderer *Game(SDL_Window *win,SDL_Renderer *renderer,joueur player)
{
    
    pilemove pile;
    pile.nbr=-1;
    
 
    // int posX = SDL_WINDOWPOS_CENTERED, posY = SDL_WINDOWPOS_CENTERED, width = 1020, height = 600;

    // intiSDL
    
    // win
    
    
    // player informartion 




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
    SDL_Texture *textliste=loadImage("image/paper.png",renderer);
    SDL_Texture *textmove=loadImage("image/history.png",renderer);
    SDL_Texture *textmoyen=loadImage("image/moyen.png",renderer);
    SDL_Texture *textrecm=loadImage("image/refresh.png",renderer);
    SDL_Texture *text10top=loadImage("image/top-three.png",renderer);
    SDL_Texture *I_joueur2=loadImage("image/idee_j.png",renderer);
    SDL_Texture *I_joueur=loadImage("image/idee_j2.png",renderer);
    SDL_Texture *I_Machi=loadImage("image/en-pensant.png",renderer);
    SDL_Texture *VSB=loadImage("image/N_vs_B.png",renderer);
    SDL_Texture *VSN=loadImage("image/B_vs_N.png",renderer);
    SDL_Texture *T_UPload=loadImage("image/upload.png",renderer);
    SDL_Texture *T_download=loadImage("image/download.png",renderer);
    SDL_Texture *T_undo=loadImage("image/undo.png",renderer);
    SDL_Texture *T_ScoreB=NULL;
    SDL_Texture *T_ScoreN=NULL;
    SDL_Texture *T_Gameover=loadImage("image/gameover.png",renderer);
    SDL_Texture *T_textS1=NULL;
    SDL_Texture *T_textS2=NULL;



   

    //fin



    //texture surface
    SDL_Surface *SurfaceMain=NULL;
    SDL_Surface *Surfacetab=NULL;
    SDL_Surface *Noire=NULL;
    SDL_Surface *Blanc=NULL;
    SDL_Surface *Point=NULL;
    SDL_Surface *S_ScoreB=NULL;
    SDL_Surface *S_ScoreN=NULL;
    SDL_Surface *S_textS1=NULL;
    SDL_Surface *S_textS2=NULL;    
    //fin
    //IMG_Load
    SurfaceMain=IMG_Load("image/bg.jpg");
    
    Surfacetab=IMG_Load("image/board.png");
    Noire=IMG_Load("image/noire.png");
    Blanc=IMG_Load("image/blanc.png");
    Point=IMG_Load("image/hint.png");
    
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
  
     //jeu formatiom




        color T[8][8];
        color C[8][8];

       
  int bloq1=0,bloq=0,afficheTop=0,affichemove=0,nivaux=0,win1=1,win2=0,win3=0,Boll=1,actuliseTOP=1,actulisemove=0,update_score=1,a=0,new_score=player.score;
   init:  
     init_TabAvide(T);
     init_TabAvide(C);
     bloq1=0,bloq=0,afficheTop=0,affichemove=0,nivaux=0,win1=1,win2=0,win3=0,Boll=1,actuliseTOP=1,actulisemove=0,update_score=1,a=0,new_score=player.score;
        
        recomencer(T);
 
        int K[2][25];
        int K2[2]={-1,-1};
        int nb=9;
        int scoreb=2,scoren=2,scoreb_tmp=2,scoren_tmp=2;
       
        int x,y;
        pile.nbr=-1;
       color pi=vide,round=vide;
       
        srand(time(NULL));
        
       int n=rand()%2;
       if(n)round=noire;
       else round=blanc;
        remplissage(K,T,round,&nb);
        // for(int i=0;i<8;i++){
        //     printf("\n");
        //     for(int j=0;j<8;j++){
        //         if(T[i][j]==vide) printf("|   |");
        //         if(T[i][j]==blanc) printf("| B |");
        //         if(T[i][j]==noire) printf("| N |");
        //     }
        //     printf("\n");
        //     }
        

        //fin
        TTF_Init();
        TTF_Font *USER,*font_S;
    SDL_Color color_write={0,0,0};
    SDL_Color color_g={103,62,44};
    USER=TTF_OpenFont("image/font.ttf",15);
    font_S=TTF_OpenFont("image/Sansation-Italic.ttf",36);  
    SDL_Surface *S_text;
    SDL_Texture *T_text;
    

SDL_Surface *icon=NULL;
icon=IMG_Load("image/icon.png");
SDL_SetWindowIcon(win,icon);
 SDL_FreeSurface(icon);
   
// int yy=1,xx=0;
    while (!done)
    {
        
  

    //  if(win2&&xx){  
           
    //        for(int i=0;i<8;i++){
    //         printf("\n");
    //         for(int j=0;j<8;j++){
    //             if(T[i][j]==vide) printf("|   |");
    //             if(T[i][j]==blanc) printf("| B |");
    //             if(T[i][j]==noire) printf("| N |");
    //         }
    //         printf("\n");
    //         }
    //         yy=0;
    //         xx=0;

    //         }


    //  if(win2&&yy){  
           
    //        for(int i=0;i<8;i++){
    //         printf("\n");
    //         for(int j=0;j<8;j++){
    //             if(T[i][j]==vide) printf("|   |");
    //             if(T[i][j]==blanc) printf("| B |");
    //             if(T[i][j]==noire) printf("| N |");
    //         }
    //         printf("\n");
    //         }
    //         yy=0;
    //         xx=1;
    //         }



        scoreb_tmp=scoreb;
        scoren_tmp=scoren;  
       forcerK(K,&nb);
        // rectangle
        SDL_Rect rectMain,rectTabe,rectjeu[8][8],rectVSjoueur,rectVSOrdiN1,rectVSOrdiN2,rectVSOrdiN3,rectBlanc,rectNoire,rectRecm,rectAffichierMove,rectTOPE10,rectlistemovem,rect,rectscoreJ1,rectscoreJ2,rce_i_m,rce_i_a,recVS,rect_download,rect_upload,rect_undo,rectTexS1,rectTextS2,rct;
        SDL_GetWindowSize(win,&(rectMain.w),&(rectMain.h));
        makerect(&rectMain,0,0,rectMain.w,rectMain.h);
        
        makerect(&rectTabe,rectMain.x+rectMain.w*0.4,rectMain.y+rectMain.h*0.15,rectMain.w*widthtab_surwidthwin,rectMain.h*heighthtab_surheighthwin);
        makerect(&rce_i_a,rectTabe.x+(rectMain.h-rectTabe.h)*0.1,rectMain.y+(rectMain.h-rectTabe.h)*0.1,(rectMain.h-rectTabe.h)*0.8,(rectMain.h-rectTabe.h)*0.8);
        makerect(&rce_i_m,rectTabe.x+rectTabe.w-(rectMain.h-rectTabe.h),rectMain.y+(rectMain.h-rectTabe.h)*0.1,(rectMain.h-rectTabe.h)*0.8,(rectMain.h-rectTabe.h)*0.8);
        makerect(&recVS,rectTabe.x+rectTabe.w/2-rectMain.w*0.15,rectMain.y+(rectMain.h-rectTabe.h)*0.1,rectMain.w*0.3,rectMain.h-rectTabe.h);
        makerect(&rectscoreJ1,rectMain.w*0.5610,rectMain.h*0.06,0,0);
        makerect(&rectscoreJ2,rectMain.w*0.7493,rectMain.h*0.06,0,0);
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
        
        makerect(&rectRecm,rectMain.x+rectMain.w*0.01,rectMain.y+rectMain.h*0.01,rectMain.w*0.04,rectMain.h*0.05);
        SDL_RenderCopy(renderer,textrecm,NULL,&rectRecm);
       
        makerect(&rectAffichierMove,rectRecm.x +rectRecm.w+rectMain.w*0.01 ,rectRecm.y,rectMain.w*0.04,rectMain.h*0.05);
        SDL_RenderCopy(renderer,textmove,NULL,&rectAffichierMove);
        
        makerect(&rectTOPE10,rectAffichierMove.x +rectAffichierMove.w+rectMain.w*0.01 ,rectRecm.y,rectMain.w*0.04,rectMain.h*0.05);
        SDL_RenderCopy(renderer,text10top,NULL,&rectTOPE10);
        makerect(&rect_download,rectTOPE10.x +rectTOPE10.w+rectMain.w*0.01 ,rectRecm.y,rectMain.w*0.04,rectMain.h*0.05);
        SDL_RenderCopy(renderer,T_download,NULL,&rect_download);
        makerect(&rect_upload,rect_download.x +rect_download.w+rectMain.w*0.01 ,rectRecm.y,rectMain.w*0.04,rectMain.h*0.05);
        SDL_RenderCopy(renderer,T_UPload,NULL,&rect_upload);
        makerect(&rect_undo,rect_upload.x +rect_upload.w+rectMain.w*0.01 ,rectRecm.y,rectMain.w*0.04,rectMain.h*0.05);
        SDL_RenderCopy(renderer,T_undo,NULL,&rect_undo);
        
         


    
        if(round==pi) SDL_RenderCopy(renderer,I_joueur,NULL,&rce_i_a);
        if(round!=pi&&nivaux!=-1) SDL_RenderCopy(renderer,I_Machi,NULL,&rce_i_m);
        if(round!=pi&&nivaux==-1) SDL_RenderCopy(renderer,I_joueur2,NULL,&rce_i_m);
        if(pi==noire)SDL_RenderCopy(renderer,VSB,NULL,&recVS);
        else SDL_RenderCopy(renderer,VSN,NULL,&recVS);



        if(update_score)
        {
           
            char S_B[14],S_N[14];
          
            itoa(scoreb,S_B,10);
          
            itoa(scoren,S_N,10);
            
            
            S_ScoreB=TTF_RenderText_Blended(font_S,S_B,color_g);
            T_ScoreB= SDL_CreateTextureFromSurface(renderer,S_ScoreB);
            S_ScoreN=TTF_RenderText_Blended(font_S,S_N,color_g);
            T_ScoreN= SDL_CreateTextureFromSurface(renderer,S_ScoreN);
            
            
         
            SDL_FreeSurface(S_ScoreN);
            SDL_FreeSurface(S_ScoreB);
            update_score=0;
        }
      
 int h1,w1;
         if(pi==noire)
            { 
            SDL_QueryTexture(T_ScoreB,NULL,NULL,&w1,&h1);
            makerect(&rectscoreJ2,rectscoreJ2.x,rectscoreJ2.y,w1,h1);
            
            SDL_RenderCopy(renderer,T_ScoreB,NULL,&rectscoreJ2);
            SDL_QueryTexture(T_ScoreN,NULL,NULL,&w1,&h1);
            makerect(&rectscoreJ1,rectscoreJ1.x,rectscoreJ1.y,w1,h1);
            SDL_RenderCopy(renderer,T_ScoreN,NULL,&rectscoreJ1);
            
            }
            
            else
            {
            SDL_QueryTexture(T_ScoreN,NULL,NULL,&w1,&h1);
            makerect(&rectscoreJ2,rectscoreJ2.x,rectscoreJ2.y,w1,h1);
            SDL_RenderCopy(renderer,T_ScoreN,NULL,&rectscoreJ2);
            SDL_QueryTexture(T_ScoreB,NULL,NULL,&w1,&h1);
            makerect(&rectscoreJ1,rectscoreJ1.x,rectscoreJ1.y,w1,h1);
            SDL_RenderCopy(renderer,T_ScoreB,NULL,&rectscoreJ1);
            
            
            }

        

      if(affichemove||afficheTop)
        {
        makerect(&rectlistemovem,rectRecm.x,rectRecm.y+rectRecm.h+ rectMain.h*0.01,rectMain.w-rectTabe.w-rectMain.w*0.2,rectMain.h*0.75);
        SDL_RenderCopy(renderer,textliste,NULL,&rectlistemovem);
            
               if(actuliseTOP){ 
                    joueur *D;
                    D=DixMeilleursScores();
                    int a,b;
                    a=rectlistemovem.h;
                    b=rectlistemovem.w;
                    
                    a/=22;
                    b*=0.5;
                    int x_lis=rectlistemovem.x+rectlistemovem.w*0.05;
                    int y_lis=rectlistemovem.y +rectlistemovem.h*0.05;
                   
                   
                    char text[301]={},S_j[10];
                 
                    
                   
                    for(int i=0;i<261;i+=30)
                    {
                    itoa((D[i/30].score),S_j,10);
                    strcat(text,"");
                    strcat(text,D[i/30].usrname);
                    char split[12]={":"};
                    strcat(split,S_j);
                   
                   
                    
                    strcat(text,split); 
                    int Lenght_T=(i+30)-strlen(text);
                    char temp[Lenght_T+1];
                     for(int j=0;j<Lenght_T;j++) temp[j]=' ';
               
                     strcat(text,temp);
                    


                    }
                   
                    int T_w;
                    int T_h;

                    S_text=TTF_RenderText_Blended_Wrapped(USER,text,color_write,271);//TTF_RenderText_Solid(USER,text,color_write);
                    T_text=SDL_CreateTextureFromSurface(renderer,S_text);
                    SDL_QueryTexture(T_text,NULL,NULL,&T_w,&T_h);
                    makerect(&(rect),x_lis,y_lis,T_w,T_h);
                    actuliseTOP=0;
                    actulisemove=0;
                    SDL_FreeSurface(S_text);
            
                    free(D);

                }
              
                if(actulisemove){ 
                   
                    int a,b;
                    a=rectlistemovem.h;
                    b=rectlistemovem.w;
                    
                    a/=22;
                    b*=0.5;
                    int x_lis=rectlistemovem.x+rectlistemovem.w*0.05;
                    int y_lis=rectlistemovem.y +rectlistemovem.h*0.05;
                   
                   
                    char text1[64*15+1]={""},S_x[10],S_y[10];
                    
                   
                    for(int i=0;i<=((pile.nbr-1)*15);i+=15)
                    {
                    
                    // strcat(text,"");
                    itoa(pile.toutMove[i/15].x,S_x,8);
                    itoa(pile.toutMove[i/15].y,S_y,8);
                   if(pile.toutMove[i/15].joueur==blanc) strcat(text1,"Blanc (");
                   if(pile.toutMove[i/15].joueur==noire) strcat(text1,"noire (");
                    char split[12]={":"};
                    strcat(split,S_y);
                   
                   
                    
                    strcat(text1,S_x);
                    strcat(text1,split);
                    
                    strcat(text1,")");


                    int Lenght_T=(i+15)-strlen(text1);
                    char temp[Lenght_T+1];
                    for(int j=0;j<Lenght_T;j++) temp[j]=' ';
               
                    strcat(text1,temp);
                    


                    }
                   
                    int T_w;
                    int T_h;

                    S_text=TTF_RenderText_Blended_Wrapped(USER,text1,color_write,271);//TTF_RenderText_Solid(USER,text,color_write);
                    T_text=SDL_CreateTextureFromSurface(renderer,S_text);
                    SDL_QueryTexture(T_text,NULL,NULL,&T_w,&T_h);
                    makerect(&(rect),x_lis,y_lis,T_w,T_h);
                    actulisemove=0;actuliseTOP=0;
                    SDL_FreeSurface(S_text);
            
                    

                }
                  if(affichemove||afficheTop)
                {
                    SDL_RenderCopy(renderer,T_text,NULL,&rect);
                }


        } 
            

        renderer=changerlatableaux(T,renderer,textBlanc,textNoire,textPoint,K,nb,rectTabe,rectjeu,Boll);
         
        if(bloq1||(scoren+scoreb==64)||(scoreb==0||scoren==0))
        {
            a=1;
            makerect(&rct,rectMain.w/2-rectMain.w/6,rectMain.h/2-rectMain.h/6,rectMain.w/3,rectMain.h/3);
            if(player.score<scoreb&& pi==blanc) player.score=scoreb;
            if(player.score<scoren&& pi==noire) player.score=scoren;
            char C_oldscore[3],C_new[3],b[16]={"Score:"},t[16]={"Record:"};
            if(pi==blanc)
            {
                itoa(scoreb,C_new,10);
                itoa(player.score,C_oldscore,10);
            }
            if(pi==noire)
            {
                itoa(scoren,C_new,10);
                itoa(player.score,C_oldscore,10);
            }
            strcat(t,C_oldscore);
            strcat(b,C_new);
            int w,h;
            S_textS1=TTF_RenderText_Blended(font_S,t,color_write);//TTF_RenderText_Solid(USER,text,color_write);
            T_textS1=SDL_CreateTextureFromSurface(renderer,S_textS1);
            SDL_QueryTexture(T_textS1,NULL,NULL,&w,&h);
            makerect(&rectTexS1,rectMain.w*0.389,rectMain.h*0.5,w,h);
            S_textS2=TTF_RenderText_Blended(font_S,b,color_write);//TTF_RenderText_Solid(USER,text,color_write);
            T_textS2=SDL_CreateTextureFromSurface(renderer,S_textS2);
            SDL_QueryTexture(T_textS2,NULL,NULL,&w,&h);
            makerect(&rectTextS2,rectMain.w*0.52,rectMain.h*0.5,w,h);
            bloq=0,bloq1=0;
            // recomencer(T);
            // remplissage(K,T,round,&nb);
             if(pi==blanc)
            {
                 
             
                if(scoreb>new_score)
                {   
                    new_score=scoreb;
                   
                    
                }
            }
            else
            {
           

                if(scoren>new_score)
                {
                     new_score=scoren;
                    
                }
            }

            player.score=new_score;
                modifierbasedonnees(player);
                actuliseTOP=1;
            
            

        } 
       if(a) {
           SDL_RenderCopy(renderer,T_Gameover,NULL,&rct);
           SDL_RenderCopy(renderer,T_textS1,NULL,&rectTexS1);
           SDL_RenderCopy(renderer,T_textS2,NULL,&rectTextS2);
           
       
       }
       
        SDL_RenderPresent(renderer);
        

    if(nivaux==1)
    {
        if(round==Adversaire(pi))
        {

        Copiejeu(C,T);                       
        SDL_Delay(500);
        if(nb==0)
        {
             if(bloq) bloq1=1;
             else bloq=1,bloq1=0;
             remplissage(K,T,pi,&nb),Boll=1;

        }                    
        else
        {
        jeualeatoire(T,K,&nb,Adversaire(pi)),Boll=1;// jeuAI(T,K,&nb,Adversaire(pi),5,K2)
        if(!GitXetYdejeu(&x,&y,C,T)) round=Adversaire(round);
        ajouterMOVE(x,y,round,&pile);
        bloq=0;
        }
        round=Adversaire(round);
                                        
        }
    }
    if(nivaux==2)
    {

       if(round==Adversaire(pi))
        {

        Copiejeu(C,T);                       
        SDL_Delay(500);
        if(nb==0)
        {
             if(bloq) bloq1=1;
             else bloq=1,bloq1=0;
             remplissage(K,T,pi,&nb),Boll=1;
           

        }                    
        else
        {
        jeuAI(T,K,&nb,Adversaire(pi),N2,K2) ,Boll=1;// jeuAI(T,K,&nb,Adversaire(pi),5,K2)
        if(!GitXetYdejeu(&x,&y,C,T)) round=Adversaire(round);
        ajouterMOVE(x,y,round,&pile);
        bloq=0;
        }
        round=Adversaire(round);
                                        
        }
     
    }
      if(nivaux==3)
    {
     if(round==Adversaire(pi))
        {

        Copiejeu(C,T);                       
        SDL_Delay(500);
        if(nb==0)
        {
             if(bloq) bloq1=1;
             else bloq=1,bloq1=0;
              remplissage(K,T,pi,&nb),Boll=1;

        }                    
        else
        {
        jeuAI(T,K,&nb,Adversaire(pi),N3,K2) ,Boll=1;// jeuAI(T,K,&nb,Adversaire(pi),5,K2)
        if(!GitXetYdejeu(&x,&y,C,T)) round=Adversaire(round);
        ajouterMOVE(x,y,round,&pile);
        bloq=0;
        }
        round=Adversaire(round);
                                        
        }
     
    }
    }

        
        SDL_Event event;
        
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                // case SDL_MOUSEMOTION:
                
                // SDL_GetGlobalMouseState(&aa,&bb);
                //     printf("(%d,%d)\n",aa,bb);
                //     break;

                case SDL_MOUSEBUTTONDOWN:

                    if(event.button.button==SDL_BUTTON_LEFT){
                        a=0;
                         
                        
                    afficheTop=0; affichemove=0;
                       if(win3)
                        {

                        if(SDL_click(rectTOPE10,event))
                        { 
                        afficheTop=1;
                        affichemove=0;
                        actuliseTOP=1;
                        }
                         if(SDL_click(rectAffichierMove,event))
                        { 
                        afficheTop=0;
                        affichemove=1;
                        actulisemove=1;

                        }
                        if(SDL_click(rectRecm,event))
                        { 
                            // recomencer(T);
                            goto init;
                        }
                            
                        if(SDL_click(rect_undo,event))
                        {
                            if(nivaux==-1)
                            {
                            jeupresdent(T,&pile);
                            remplissage(K,T,pile.toutMove[pile.nbr].joueur,&nb);
                            round=Adversaire(pile.toutMove[pile.nbr].joueur),Boll=1;
                            }
                            if(nivaux!=-1)
                            {
                            jeupresdent(T,&pile);
                            jeupresdent(T,&pile);
                            remplissage(K,T,pile.toutMove[pile.nbr].joueur,&nb);
                            
                            }
                        }
                        if(SDL_click(rect_upload,event))
                        { 
                            sauvgarde(T,player,nivaux,round);
                        }
                        if(SDL_click(rect_download,event))
                        { 
                            charegerjeu(player,T,&nivaux,&round);
                            remplissage(K,T,pi,&nb);
                        }


                           if(SDL_click(rectTabe,event)){ 
                           
                                if(nivaux==-1)
                                {
                                    if(round==pi)
                                    {

                                        if(nb==0)
                                        {
                                            if(bloq)bloq1=1;
                                            else bloq=1,bloq1=0;
                                            remplissage(K,T,Adversaire(pi),&nb),Boll=0;
                                        }
                                        else
                                        {
                                                if(SDL_GetCaseclick(rectTabe,event.button.x,event.button.y,&x,&y))
                                                { 
                                                    if(jeu(T,K,&nb,pi,x,y))
                                                    {
                                                    ajouterMOVE(x,y,round,&pile);
                                                    bloq=0;
                                                    }
                                                    else
                                                    {
                                                        round=Adversaire(round);
                                                    }
                                                }
                                        }
                                    
                                    }
                                    else 
                                    {
                                         if(nb==0)
                                        {
                                            if(bloq)bloq1=1;
                                            else bloq=1,bloq1=0;
                                            remplissage(K,T,pi,&nb);
                                        }
                                        else
                                        {
                                                if(SDL_GetCaseclick(rectTabe,event.button.x,event.button.y,&x,&y))
                                                { 
                                                    if(jeu(T,K,&nb,Adversaire(pi),x,y))
                                                    {
                                                    ajouterMOVE(x,y,Adversaire(pi),&pile);
                                                    bloq=0;
                                                    }
                                                    else
                                                    {
                                                        round=Adversaire(round);
                                                    }
                                                }
                                        }
                                    
                                    
                                    }
                                    round=Adversaire(round);

                                }
                                if(nivaux!=-1)
                                {
                                    
                                    if(round==pi)
                                    {
                                     if(nb==0)
                                        {
                                            if(bloq)bloq1=1;
                                            else bloq=1,bloq1=0;
                                            remplissage(K,T,Adversaire(pi),&nb),Boll=0;
                                        }
                                        else
                                        {
                                                if(SDL_GetCaseclick(rectTabe,event.button.x,event.button.y,&x,&y))
                                                { 
                                                    if(jeu(T,K,&nb,pi,x,y))
                                                    {
                                                    ajouterMOVE(x,y,pi,&pile);
                                                    bloq=0;
                                                    }
                                                    else
                                                    {
                                                        round=Adversaire(round);
                                                    }
                                                }
                                        }
                                    }
                                    // jeu(T,K,&nb,pi,x,y),Boll=0;
                                     round=Adversaire(round);
                                    }
                                   
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

                        if(nivaux!=0) {win1=0;win2=1;win3=0;}

                        }
                    }

                    break;
                     
           
                case SDL_QUIT:
                  
                    // if(pi==blanc)  { if(scoreb>player.score) modifierbasedonnees(player);}
                    // else {if(scoreb>player.score) modifierbasedonnees(player);}
                    done=SDL_TRUE;
                 
                    break;
            
                default:
                    break;
            }



        }
        scoreb=Score(T,blanc);
        scoren=Score(T,noire);
       
        if((scoren!=scoren_tmp)||(scoreb!=scoreb_tmp)) update_score=1;
        

    }
 
    // if(bloq1==1)
    TTF_Quit();
    SDL_DestroyTexture(text2joueur);
    SDL_DestroyTexture(textcolorblanc);
    SDL_DestroyTexture(textcolornoire);
    SDL_DestroyTexture(textdifficle);
    SDL_DestroyTexture(textfacile);
    SDL_DestroyTexture(textliste);
    SDL_DestroyTexture(textmove);
    SDL_DestroyTexture(textmoyen);
    SDL_DestroyTexture(textrecm);
    SDL_DestroyTexture(text10top);
    SDL_DestroyTexture(I_joueur2);
    SDL_DestroyTexture(I_joueur);
    SDL_DestroyTexture(I_Machi);
    SDL_DestroyTexture(VSB);
    SDL_DestroyTexture(VSN);
    SDL_DestroyTexture(T_ScoreN);
    SDL_DestroyTexture(textPoint);
    SDL_DestroyTexture(textBlanc);
    SDL_DestroyTexture(textNoire);
    SDL_DestroyTexture(T_text);
    SDL_DestroyRenderer(renderer);

    return renderer;
}
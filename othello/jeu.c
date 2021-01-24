#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
typedef enum color color;//couleur
enum color
{
    noire,blanc,vide
};

int ** init_tab_dynamic(int x,int y)
{
   int i,j;
   int ** tab = malloc( x*sizeof(int*));
   for (i=0;i<x;i++)
   {
      tab[i]=malloc(y*sizeof(int));
      for (j=0;j<y;j++)
      {
          tab[i][j]=0;
      }
   }
   return tab;
}
color ** char_tab_dynamic(int x,int y)
{
   int i,j;
   color ** tab = malloc( x*sizeof(color*));
   for (i=0;i<x;i++)
   {
      tab[i]=malloc(y*sizeof(color));
      for (j=0;j<y;j++)
      {
          tab[i][j]=vide;
      }
   }
   return tab;
}





void couleur()
{
    printf("joueur1:si vous aimerez jouer avec la pierre noire\n");
    printf("joueur2:si  vous aimerez jouer avec la pierre blanche\n");
}

int **remplissage(color pi,color **T)
{
    int m,n;
    int **K=init_tab_dynamic(2,20);

    
    int i,j,b;
    b=0;
    color x;
    if(pi==noire)
    {
        x=blanc;
    }
    else if(pi==blanc)
    {
        x=noire;
    }
    
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(T[i][j]==pi)
                {
                    if((i+1)<8)
                    {
                        m=i+1;
                        if(T[m][j]==x)
                        {
                            while(((m)<8)&&(T[m][j]==x)&&(T[m][j]!=pi))
                            {
                                m++;
                            }
                            if((T[m][j]!=pi)&&(m<8))
                            {
                                printf("(%d,%d) est une case valable\n",m,j);
                                K[0][b]=m;
                                K[1][b]=j;
                                b++;
                            }
                        }
                    }
                    if(((i+1)<8)&&((j+1)<8))   
                    {    
                        m=i+1;
                        n=j+1;
                        if(T[m][n]==x)
                        {
                            while((m<8)&&(n<8)&&(T[m][n]==x)&&(T[m][j]!=pi))
                            {
                                m++;
                                n++;
                            }
                            if((T[m][n]!=pi)&&(m<8)&&(n<8))
                            {
                                printf("(%d,%d) est une case valable\n",m,n);
                                K[0][b]=m;
                                K[1][b]=n;
                                b++;
                            }
                            
                        }
                    }
                    if((j+1)<8)
                    {
                        n=j+1;
                        if(T[i][n]==x)
                        {
                            while((n<8)&&(T[i][n]==x)&&(T[m][j]!=pi))
                            {
                                n++;
                            }
                            if((T[i][n]!=pi)&&(n<8))
                            {
                                printf("(%d,%d) est une case valable\n",i,n);
                                K[0][b]=i;
                                K[1][b]=n;
                                b++;
                            }
                        }
                    }
                    if(((i+1)<8)&&((j-1)>=0))   
                    {
                        m=i+1;
                        n=j-1;    
                        if(T[m][n]==x)
                        {
                            while((m<8)&&(n>=0)&&(T[m][n]==x)&&(T[m][j]!=pi))
                            {
                                m++;
                                n--;
                            }
                            if((T[m][j]!=pi)&&(m<8)&&(n>=0))
                            {
                                printf("(%d,%d) est une case valable\n",m,n);
                                K[0][b]=m;
                                K[1][b]=n;
                                b++;
                            }
                        }
                    }
                    if((j-1)>=0)
                    {
                        n=j-1;
                        if(T[i][n]==x)
                        {
                            while((n>=0)&&(T[i][n]==x)&&(T[m][j]!=pi))
                            {
                                n--;
                            }
                            if((T[m][j]!=pi)&&(n>=0))
                            {
                                printf("(%d,%d) est une case valable\n",i,n);
                                K[0][b]=i;
                                K[1][b]=n;
                                b++;
                            }
                            
                        }
                    }
                    if((i-1)>=0)
                    {
                        m=i-1;
                        if(T[m][j]==x)
                        {
                            while((m>=0)&&(T[m][j]==x)&&(T[m][j]!=pi))
                            {
                                m--;
                            }
                            if((T[m][j]!=pi)&&(m>=0))
                            {
                                printf("(%d,%d) est une case valable\n",m,j);
                                K[0][b]=m;
                                K[1][b]=j;
                                b++;
                            }
                            
                        }
                    }
                    if(((i-1)>=0)&&((j+1)<8))   
                    { 
                        m=i-1;
                        n=j+1;   
                        if(T[m][n]==x)
                        {
                            while((m>=0)&&(n<8)&&(T[m][n]==x)&&(T[m][j]!=pi))
                            {
                                m--;
                                n++;
                            }
                            if((T[m][j]!=pi)&&(m>=0)&&(n<8))
                            {
                                printf("(%d,%d) est une case valable\n",m,n);
                                K[0][b]=m;
                                K[1][b]=n;
                                b++;
                            }
                        }
                    }
                    
                    if(((i-1)>=0)&&((j-1)>=0))   
                    {    
                        m=i-1;
                        n=j-1;
                        if(T[m][n]==x)
                        {
                            while((m>=0)&&(n>=0)&&(T[m][n]==x)&&(T[m][j]!=pi))
                            {
                                m--;
                                n--;
                            }
                            if((T[m][j]!=pi)&&(m>=0)&&(n>=0))
                            {
                                printf("(%d,%d) est une case valable\n",m,n);
                                K[0][b]=m;
                                K[1][b]=n;
                                b++;
                            }
                        }
                    }                    
                }
            }
        }

    return K;
    

    
}

color **transformerpierre(color **T,int x,int y,color pi)
{
    int i;
    int m,n;
    color c;
    if(pi==noire)  c=blanc;
    if(pi==blanc) c=noire;
    if(pi==vide) return T;
    
    if(x+1<8)
    {
        if(T[x+1][y]==c)
        {
            
            for(i=x+2;i<8;i++)
            {
                if(T[i][y]==pi) break;   
            }
            if(i<8)
            {
                for(m=x;m<i;m++) T[m][y]=pi;
            }

        }
        if(y+1<8)
        {
            if(T[x+1][y+1]==c)
            {
                i=2;
                while((T[x+i][y+i]!=pi)&&(y+i<8)&&(x+i<8)) i++;
                if((y+i<8)&&(x+i<8))
                {
                    for(m=0;m<i;m++) T[x+m][y+m]=pi;
                }
            }
        }
        if((y-1)>=0)
        {
            if(T[x+1][y-1]==c)
            {
                i=2;
                while((T[x+i][y-i]!=pi)&&(y-i>=0)&&(x+i<8)) i++;
                if((y-i>=0)&&(x+i<8))
                {
                    for(m=0;m<i;m++) T[x+m][y-m]=pi;  
                }
            }
        }

    }
    if(y+1<8)
    {
        if(T[x][y+1]==c)
        {
            i=2;
            while((T[x][y+2]!=pi)&&(y+i<8)) i++;
            if((y+i<8))
            {
                for(m=0;m<i;m++) T[x][y+m]=pi;
            }
        }

    }
    if(y-1>=0)
    {
        if(T[x][y-1]==c)
        {
            i=2;
            while((T[x][y-2]!=pi)&&(y-i>=0)) i++;
            if((y-i>=0))
            {
                for(m=0;m<i;m++) T[x][y-m]=pi;          
            }
        }
    }
    if(x-1>=0)
    {
        if(T[x-1][y]==c)
        {
            i=2;
            while((T[x-i][y]!=pi)&&(x-i>=0)) i++;
            if((x-i>=0))
            {
                for(m=0;m<i;m++) T[x-m][y]=pi;
            }


        }

    }
    if((x-1>=0)&&(y-1)>=0)
    {
        if(T[x-1][y-1]==c)
        {
            i=2;
            while((T[x-i][y-i]!=pi)&&(x-i>=0)&&(y-i)>=0)   i++;
            if((x-i>=0)&&(y-i>=0))
            {
                for(m=0;m<i;m++) T[x-m][y-m]=pi;
            }


        }

    }
    if((x-1>=0)&&(y+1)<8)
    {
        if(T[x-1][y+1]==c)
        {
            i=2;
            while((T[x-i][y+i]!=pi)&&(x-i>=0)&&(y+i)>=0) i++;
            if((x-i>=0)&&(y+i<8))
            {
                for(m=0;m<i;m++) T[x-m][y+m]=pi;
            }


        }

    }
    return T;
    
}


int main()

{
    int **K=init_tab_dynamic(2,20);
    color **T=char_tab_dynamic(8,8);
    
    int i,j,n;
    int x,y;
    T[3][3]=noire;
    T[3][4]=blanc;
    T[4][3]=blanc;
    T[4][4]=noire;
    T[5][3]=blanc;
    T[6][3]=noire;
    T[7][3]=noire;
    color c;
    color pi;
    char c1;
    char s1[30];
    printf("j/J:jouer\n");
    scanf("%c",&c1);
    if((c1=='j')||(c1=='J'))
    {
        couleur();
        scanf("%s",s1);
        if(strcmp("joueur1",s1)==0)
        {
            c=blanc;
            pi=noire;
        }
        else
        {
            c=noire;
            pi=blanc; 
        }
            K=remplissage(pi,T);
            n=0;
            do
            {
                printf("donner x:\n");
                scanf("%d",&x);
                printf("donner y:\n");
                scanf("%d",&y);
                for(j=0;j<20;j++)
                {
                    if(K[0][j]==x)
                    {
                        if(K[1][j]==y)
                        {
                            n=1;
                            break;
                        }
                    }
                }
            }while(n==0);

           for(i=0;i<8;i++)
           {
               printf("%d\t",i);
               for(j=0;j<8;j++)
               {

                if(i=0) 

                {
                    printf("%d\t",j);
                }
                   if(T[j][i]==c)
                   {
                       printf("B\t");
                   }
                   if(T[j][i]==pi)
                   {
                       printf("N\t");
                   }
                   if((T[j][i]!=pi)&&(T[j][i]!=c))
                   {
                       printf("-\t");
                   }
                   
               }

                printf("\n");
               printf("\n");
           }
           printf("----------------------------------------------------------\n");

           T=transformerpierre(T,x,y,pi);
           for(i=0;i<8;i++)
           {
               for(j=0;j<8;j++)
               {
                   if(T[j][i]==c)
                   {
                       printf("B\t");
                   }
                   if(T[j][i]==pi)
                   {
                       printf("N\t");
                   }
                   if((T[j][i]!=pi)&&(T[j][i]!=c))
                   {
                       printf("-\t");
                   }
                   
               }

               
               printf("\n");
           }
           
           



        
        





    }
    return 0;
}
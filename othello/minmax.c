#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  INFINITY INT_MAX
typedef enum color color;//couleur
enum color
{
    noire,blanc,vide
};
int min1(int a,int b)
{
  if (a>b) return b;
  else return a;
}
int max1(int a,int b)
{
  if (a>b) return a;
  else return b;
}

int **init_tab_dynamic(int x,int y)
{
   int i=0,j=0;
   int **tab=(int**)malloc(x*sizeof(int*));
   if(tab!=NULL)
   {
   for (i=0;i<x;i++)
   {
      tab[i]=(int*)malloc(y*sizeof(int));
      for (j=0;j<y;j++)
      {
          tab[i][j]=-1;
      }
   }
   free(tab);
   }
   else
   {
       printf("erreur");
       exit(-1);
   }
   
   return tab;
}

color **char_tab_dynamic(int x,int y)
{

    int i=0,j=0;
    color **tab=malloc(x*sizeof(color*));
    if(tab!=NULL)
    {
    for (i=0;i<x;i++)
    {
        tab[i]=(color*)malloc(y*sizeof(color));
        for (j=0;j<y;j++)
        {
            tab[i][j]=vide;

        }
    }
    free(tab);
    }
    else
    {
        printf("erreur");
        exit(-1);
    }
    
    return tab;
}





void couleur()
{
    printf("joueur1:si vous aimerez jouer avec la pierre noire\n");
    printf("joueur2:si  vous aimerez jouer avec la pierre blanche\n");
}

void remplissage(int K[2][25],color T[8][8],color pi,int *nb)
{
    
    int m=0;
    int n=0;
    *nb=0;
    
    

    
    int i=0,j=0;
    int b=0;
    
    color x=vide;
    if(pi==noire)
    {
        x=blanc;
    }
    if(pi==blanc)
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
                        while((m<8)&&(T[m][j]==x)&&(T[m][j]!=pi))
                        {
                            m++;
                        }
                        if((T[m][j]!=pi)&&(m<8))
                        {
                            printf("(%d,%d) est une case valable\n",m,j);
                            K[0][b]=m;
                            K[1][b]=j;
                            b++;
                            (*nb)++;
                        }
                    }
                }
                if(((i+1)<8)&&((j+1)<8))   
                {    
                    m=i+1;
                    n=j+1;
                    if(T[m][n]==x)
                    {
                        while((m<8)&&(n<8)&&(T[m][n]==x)&&(T[m][n]!=pi))
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
                            (*nb)++;
                        }
                            
                    }
                }
                if((j+1)<8)
                {
                    n=j+1;
                    if(T[i][n]==x)
                    {
                        while((n<8)&&(T[i][n]==x)&&(T[i][n]!=pi))
                        {
                            n++;
                        }
                        if((T[i][n]!=pi)&&(n<8))
                        {
                            printf("(%d,%d) est une case valable\n",i,n);
                            K[0][b]=i;
                            K[1][b]=n;
                            b++;
                            (*nb)++;
                        }
                    }
                }
                if(((i+1)<8)&&((j-1)>=0))   
                {
                    m=i+1;
                    n=j-1;    
                    if(T[m][n]==x)
                    {
                        while((m<8)&&(n>=0)&&(T[m][n]==x)&&(T[m][n]!=pi))
                        {
                            m++;
                            n--;
                        }
                        if((T[m][n]!=pi)&&(m<8)&&(n>=0))
                        {
                            printf("(%d,%d) est une case valable\n",m,n);
                            K[0][b]=m;
                            K[1][b]=n;
                            b++;
                            (*nb)++;
                        }
                    }
                }
                if((j-1)>=0)
                {
                    n=j-1;
                    if(T[i][n]==x)
                    {
                        while((n>=0)&&(T[i][n]==x)&&(T[i][n]!=pi))
                        {
                            n--;
                        }
                        if((T[i][n]!=pi)&&(n>=0))
                        {
                            printf("(%d,%d) est une case valable\n",i,n);
                            K[0][b]=i;
                            K[1][b]=n;
                            b++;
                            (*nb)++;
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
                            (*nb)++;
                        }
                            
                    }
                }
                if(((i-1)>=0)&&((j+1)<8))   
                { 
                    m=i-1;
                    n=j+1;   
                    if(T[m][n]==x)
                    {
                        while((m>=0)&&(n<8)&&(T[m][n]==x)&&(T[m][n]!=pi))
                        {
                            m--;
                            n++;
                        }
                        if((T[m][n]!=pi)&&(m>=0)&&(n<8))
                        {
                            printf("(%d,%d) est une case valable\n",m,n);
                            K[0][b]=m;
                            K[1][b]=n;
                            b++;
                            (*nb)++;
                        }
                    }
                }
                
                if(((i-1)>=0)&&((j-1)>=0))   
                {    
                    m=i-1;
                    n=j-1;
                    if(T[m][n]==x)
                    {
                        while((m>=0)&&(n>=0)&&(T[m][n]==x)&&(T[m][n]!=pi))
                        {
                            m--;
                            n--;
                        }
                        if((T[m][n]!=pi)&&(m>=0)&&(n>=0))
                        {
                            printf("(%d,%d) est une case valable\n",m,n);
                            K[0][b]=m;
                            K[1][b]=n;
                            b++;
                            (*nb)++;
                        }
                    }
                }                    
            }
        }
    }

    
        
}

void transformerpierre(color T[8][8],int x,int y,color pi)
{
    int i=0;
    int m=0,n=0;
    color c=vide;
    if(pi==noire)  c=blanc;
    if(pi==blanc) c=noire;
    
    
    
    if(x+1<8)
    {
        if(T[x+1][y]==c)
        {
            
            i=2;
            while((T[x+i][y]!=pi)&&(x+i<8)&&(T[x+i][y]!=vide)) i++; 
            if((x+i<8)&&(T[x+i][y]==pi))
            {
                for(m=0;m<i;m++) T[x+m][y]=pi;
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
                while((T[x+i][y+i]!=pi)&&(y+i<8)&&(x+i<8)&&(T[x+i][y+i]!=vide)) i++;
                if((y+i<8)&&(x+i<8)&&(T[x+i][y+i]==pi))
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
                while((T[x+i][y-i]!=pi)&&(y-i>=0)&&(x+i<8)&&(T[x+i][y-i]!=vide)) i++;
                if((y-i>=0)&&(x+i<8)&&(T[x+i][y-i]==pi))
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
            while((T[x][y+i]!=pi)&&(y+i<8)&&(T[x][y+i]!=vide)) i++;
            if((y+i<8)&&(T[x][y+i]==pi))
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
            while((T[x][y-i]!=pi)&&(y-i>=0)&&((T[x][y-i]!=vide))) i++;
            if((y-i>=0)&&(T[x][y-i]==pi))
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
            while((T[x-i][y]!=pi)&&(x-i>=0)&&(T[x-i][y]!=vide)) i++;
            if((x-i>=0)&&(T[x-i][y]==pi))
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
            while((T[x-i][y-i]!=pi)&&(x-i>=0)&&(y-i>=0)&&(T[x-i][y-i]!=vide))   i++;
            if((x-i>=0)&&(y-i>=0)&&(T[x-i][y-i]==pi))
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
            while((T[x-i][y+i]!=pi)&&(x-i>=0)&&(y+i>=0)&&(T[x-i][y+i]!=vide)) i++;
            if((x-i>=0)&&(y+i<8)&&(T[x-i][y+i]==pi))
            {
                for(m=0;m<i;m++) T[x-m][y+m]=pi;
            }


        }

    }
    
    
}

int calculnum(color T[][8],color pi)
{
    int n=0;
    int i=0,j=0;
    color x;
    if(pi==noire)
    {
        x=blanc;
    }
    if(pi==blanc)
    {
        x=noire;
    }
    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            if(T[i][j]==pi)
            {
                n+=1;
            }
            if(T[i][j]==x)
            {
                n-=1;
            }
            

        }    

    }
    return n;

}



int minimax(int depth,int etatAI,color COPIE[8][8],color pi)
{
    
    
   
    
    
    int nb;
    int i;
    int j;
    
    if(depth==0)
    {
        
        
        printf("%d i:\n",calculnum(COPIE,noire));
        return calculnum(COPIE,noire);

        
    }
    
    
        if(etatAI==1)
        {
            pi=noire;
            nb=0;
            int maxvalue=-INFINITY;
            remplissage(K,COPIE,pi,&nb);
            color copie1[8][8];
            for(int m=0;m<8;m++)
            {
                for(int j=0;j<8;j++)
                {
                    copie1[m][j]=COPIE[m][j];
                }
            }
            for(i=0;i<nb;i++)
            {
                for(int m=0;m<8;m++)
                {
                    for(int j=0;j<8;j++)
                    {
                        COPIE[m][j]=copie1[m][j];
                    }
                }
                
                transformerpierre(COPIE,K[0][i],K[1][i],pi);
                for(int m=0;m<8;m++)
                {
                for(int j=0;j<8;j++)
                {
                    if(COPIE[j][7-m]==blanc)
                    {
                       printf("%c\t",'B');
                    }
                   if(COPIE[j][7-m]==pi)
                   {
                       printf("%c\t",'N');
                   }
                   if((COPIE[j][7-m]!=pi)&&(COPIE[j][7-m]!=blanc))
                   {
                       printf("*\t");
                   }
                   
                }
                

               
                printf("\n");
                }
                
                
                int value=minimax(depth-1,h,0,COPIE,pi,K);
                printf("depth:%d\n",depth);
                maxvalue=max1(value,maxvalue);
            }
            
            
            
            
        }
        else
        {
            pi=blanc;
            nb=0;
            int minvalue=+999999;
            remplissage(K,COPIE,pi,&nb);
            color copie1[8][8];
            for(int m=0;m<8;m++)
            {
                for(int j=0;j<8;j++)
                {
                    copie1[m][j]=COPIE[m][j];
                }
            }
            for(i=0;i<nb;i++)
            {
                for(int m=0;m<8;m++)
                {
                    for(int j=0;j<8;j++)
                    {
                        COPIE[m][j]=copie1[m][j];
                    }
                }
                
                transformerpierre(COPIE,K[0][i],K[1][i],pi);
                for(int m=0;m<8;m++)
                {
                for(int j=0;j<8;j++)
                {
                    if(COPIE[j][7-m]==pi)
                    {
                       printf("%c\t",'B');
                    }
                    if(COPIE[j][7-m]==noire)
                    {
                       printf("%c\t",'N');
                    }
                    if((COPIE[j][7-m]!=pi)&&(COPIE[j][7-m]!=noire))
                    {
                       printf("*\t");
                    }
                   
                }

               
                printf("\n");
                }
                
                int value=minimax(depth-1,h,1,COPIE,pi,K);
                printf("depth:%d\n",depth);
                int minvalue=min1(value,minvalue);
            }

            
            
        }
    
}

int main()
{
    int r;
    int x1=0;
    int x2=0;
    int max2=0;
    int K1[2][25];
    int value=0;
    color COPIE[8][8];
    int h=0;
    int k=0;
    int nb;
    color T[8][8];
    int K[2][25];
    char co1;
    char co2;
    int i=0,j=0,n=0;
    int x=0,y=0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            T[i][j]=vide;
        }
    }

    T[3][3]=noire;
    T[4][3]=blanc;
    T[3][4]=blanc;
    T[4][4]=noire;
    r=calculnum(T,noire);
    printf("%d\n",r);
    
    
    color c=vide;
    color pi=vide;
    char s1[30];
    char c1;
    printf("j/J:jouer\n");
    scanf("%c",&c1);
    
    if((c1=='j')||(c1=='J'))
    {
        couleur();
        scanf("%s",s1);
        do{
            
            n=0;
            nb=0;
            
            if(strcmp(s1,"joueur2")==0)
            {
                
                c=noire;
                pi=blanc;
                co1='B';
                co2='N';
            }
            
            if(strcmp(s1,"joueur1")==0)
            {
                
                c=blanc;
                pi=noire;
                co1='N';
                co2='B'; 
            }
            remplissage(K,T,pi,&nb);
            printf("----------------------\n");
            
            if(pi==noire)
            {
            max2=0;
            
            
            for(int g=0;g<8;g++)
            {
                for(int j=0;j<8;j++)
                {
                    COPIE[g][j]=T[g][j];
                }
            }
            if(pi==noire)
            {
                value=minimax(2,2,1,COPIE,pi,K);
                printf("value:%d\n",value);
            }
            
            

            }
            
            
            
            

        
            
            
            if(nb!=0)
            {
            do
            {
                printf("donner x:\n");
                scanf("%d",&x);
                printf("donner y:\n");
                scanf("%d",&y);
                for(j=0;j<25;j++)
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
               for(j=0;j<8;j++)
               {
                   if(T[j][7-i]==c)
                   {
                       printf("%c\t",co2);
                   }
                   if(T[j][7-i]==pi)
                   {
                       printf("%c\t",co1);
                   }
                   if((T[j][7-i]!=pi)&&(T[j][7-i]!=c))
                   {
                       printf("-\t");
                   }
                   
               }

               
               printf("\n");
           }
           printf("----------------------------------------------------------\n");

           transformerpierre(T,x,y,pi);
           for(i=0;i<8;i++)
           {
               for(j=0;j<8;j++)
               {
                   if(T[j][7-i]==c)
                   {
                       printf("%c\t",co2);
                   }
                   if(T[j][7-i]==pi)
                   {
                       printf("%c\t",co1);
                   }
                   if((T[j][7-i]!=pi)&&(T[j][7-i]!=c))
                   {
                       printf("*\t");
                   }
                   
               }

               
               printf("\n");
            }
            }
            
            printf("nb:%d\n",nb);
            if(strcmp("joueur1",s1)==0)
            {
                
                strcpy(s1,"joueur2");
            }
            else
            {
                strcpy(s1,"joueur1");
            }
            printf("le role de %s\n",s1);
            k=0;
           for(i=0;i<8;i++)
           {
               for(j=0;j<8;j++)
               {
                   if((T[i][j]!=pi)&&(T[i][j]!=c))
                   {
                        k++;   
                   }
               }
           }
           if((h==0)&&(nb==0)) break;
           h=nb;


           


        }while(k>0);




           
           
           



        
        





    }
    
    return 0;
}
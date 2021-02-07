#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define INFINIE INT_MAX
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
/*function minimax(node, depth, maximizingPlayer) is
    if depth = 0 or node is a terminal node then
        return the heuristic value of node
    if maximizingPlayer then
        value := −∞
        for each child of node do
            value := max(value, minimax(child, depth − 1, FALSE))
        return value
    else (* minimizing player *)
        value := +∞
        for each child of node do
            value := min(value, minimax(child, depth − 1, TRUE))
        return value


fonction alphabeta(nœud, α, β)  α est toujours inférieur à β 
   si nœud est une feuille alors
       retourner la valeur de nœud
   sinon si nœud est de type Min alors
           v = +∞
           pour tout fils de nœud faire
               v = min(v, alphabeta(fils, α, β))                
               si α ≥ v alors 
                   retourner v
               β = Min(β, v)           
    sinon
           v = -∞
           pour tout fils de nœud faire
               v = max(v, alphabeta(fils, α, β))                
               si v ≥ β alors 
                   retourner v
               α = Max(α, v)
    retourner v*/


int alphabeta(int depth,int etatAI,color COPIE[8][8],color pi,int K[2][25],int alpha,int beta)
{
    int value=-1;
    
    
    
    
    
    int nb;
    int i;
    int j;
    
    if(depth==0)
    {
        
        return calculnum(COPIE,noire);

        
    }
    else
    {
        if(etatAI==1)
        {
            pi=noire;
            nb=0;
            int maxvalue=-999;
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
                remplissage(K,copie1,pi,&nb);
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
                
                
                value=alphabeta(depth-1,0,COPIE,pi,K,alpha,beta);
                printf("value1:%d\n",value);
                printf("depth:%d\n",depth);
                maxvalue=max1(value,maxvalue);
                if(maxvalue>=beta) 
                {
                    return maxvalue;
                }
                alpha=max1(alpha,maxvalue);
                
            }
            
            
            
            
            
            
            
            
        }
        else
        {
            pi=blanc;
            nb=0;
            int minvalue=999;
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
                remplissage(K,copie1,pi,&nb);
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
                
                value=alphabeta(depth-1,1,COPIE,pi,K,alpha,beta);
                printf("value1:%d\n",value);
                printf("depth:%d\n",depth);
                minvalue=min1(value,minvalue);
                
                if(alpha>=minvalue)
                {
                   return minvalue;
                }
                beta=min1(beta,minvalue);
            }
            
            
            

            
            
        }
    }
    return value;
}

void testvalue(int nb,int K[2][25],int value,int depth,color COPIE[8][8],color pi,int K2[2])
{
    int K1[2][25];
    int m;
    color T1[8][8];
    

    
    
    int i=0;
    while(i<nb)
    {
        int alpha=-999;
        int beta=999;
        for(int m=0;m<8;m++)
        {
            for(int j=0;j<8;j++)
            {
                T1[m][j]=COPIE[m][j];
            }
        }
        transformerpierre(T1,K[0][i],K[1][i],pi);
        remplissage(K1,T1,pi,&m);
        if(alphabeta(depth-1,0,T1,pi,K1,alpha,beta)==value)
        {
            K2[0]=K[0][i];
            K2[1]=K[1][i];
            break;

        }
        i++;
    }
    
    

}

int jeu(color T[][8],int K[2][25],int *nb,color pi,int x,int y)
{
    int a=0;
    if(testcase(K,nb,x,y)) transformerpierre(T,x,y,pi),a=1;
    return a;


}
int testcase(int K[][25],int nb,int x,int y){
       int n=0,int i,int j; 
for(j=0;j<25;j++)
{
    if(K[0][j]==x)
    {
        if(K[1][j]==y)
        {
            n=1;
            return 1;
        }
    }
}
return 0;
}

void jeuAI(color T[][8],int K[2][25],int *nb,color pi,int depth,int K2[2]){
    
    int K2[2];
    

    int K1[2][25];
    int value=0;
    color COPIE[8][8];
   
   
 
   
            for(int g=0;g<8;g++)
            {
                for(int j=0;j<8;j++)
                {
                    COPIE[g][j]=T[g][j];
                }
            }
            for(int g=0;g<*nb;g++)
            {
                K1[0][g]=K[0][g];
                K1[1][g]=K[1][g];
            }
           if(nb!=0)
           {
            value=alphabeta(depth,1,COPIE,pi,K1,-999,999);
            testvalue(nb,K,value,depth,COPIE,pi,K2);
            transformerpierre(T,K2[0],K2[1],pi);
           }

}
void jeualeatoire(color T[][8],int K[2][25],int *nb,color pi){
remplissage(K,T,pi,&nb);
srnad(time(NULL));
if(nb!=0)
{
int a=rand()%(*nb);
transformerpierre(T,K[0][a],K[1][a],pi);
}
return;
}

int main()
{
    int K2[2];
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
            for(int g=0;g<25;g++)
            {
                K1[0][g]=K[0][g];
                K1[1][g]=K[1][g];
            }


            if(pi==noire)
            {
                value=alphabeta(1,1,COPIE,pi,K1,-999,999);
                printf("value:%d\n",value);
                testvalue(nb,K,value,1,COPIE,pi,K2);
                printf("%d,%d\n",K2[0],K2[1]);
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
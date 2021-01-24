#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void main(){

    char T[100]={"zouheir senan"};
    char username[100]={"zouheir senan"};

    int n,j=4 ;
     
    while (j--)
    {
                            n=strlen(username);
                           for (size_t i = 0; i <n-1; i++)
                           {
                               T[i]=username[i];
                           }
                           T[n-1]='\0';
                        strcpy(username,T);
                            puts(T);
                            puts(username);
                            printf("%d\n",n);

    }




}
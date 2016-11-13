#include<stdio.h>
#include<conio.h>
#include<string.h>
void itoa(short n,char s[],short b);
void  reverse(char s[]);
main()
{
     short n,b;
    //printf("%d", sizeof(short));
     char s[20];
     scanf("%d",&n);
     scanf("%d",&b);
      itoa( n,s,b);
      printf("string equivalent is %s ",s);
      getch();
      return;
      }
      
      void itoa(short n,char s[],short b)
      {
           short i,sign;
           sign =1;
           if(n<0)
           {
                  n=-n;
                  sign=-1;
           }
           i=0;
           do{
               s[i++] =n%16 +'0';
               n =n/16;
             }while(n>0);
             if(sign<0)
             s[i++] ='-';
                          
             s[i]='\0';
             reverse(s);
      }
                          
         void  reverse(char s[])
         {
               short i,j,c;
               for(i=0,j=strlen(s)-1;i<j;i++,j--)
               c=s[i],s[i]=s[j],s[j]=c;
         }
                                       
                          
                  
                  

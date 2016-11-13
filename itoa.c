//Convert integer to string
#include<stdio.h>
#include<conio.h>
#include<string.h>
void itoa(int n,char s[],int b);
void  reverse(char s[]);
int len=0;
main()
{
     int n,i,b;
    //printf("%d", sizeof(int));
     char s[20];
     scanf("%d",&n);
     scanf("%d",&b);
      itoa( n,s,b);
     
     printf("%s",s);
      getch();
      return;
      }
      
      void itoa(int n,char s[],int b)
      {
           int i,sign;
           sign =1;
           if(n<0)
           {
                  n=-n;
                  sign=-1;
           }
           i=0;
           do{
               s[i++] =n%b +'0' ;
               n =n/b;
               len++;
             }while(n>0);
             if(sign<0)
             s[i++] ='-';
               s[i]='\0';           
            
             reverse(s);
      }
                          
         void  reverse(char s[])
         {
               int i,j,c;
               for(i=0,j=len-1;i<j;i++,j--)
               c=s[i],s[i]=s[j],s[j]=c;
               for(i=0;i<=len-1;i++)
               {
                                          switch(s[i])
                                          {
                                                      case ':': s[i]='A';
                                                      break;
                                                     case ';': s[i]='B';
                                                      break;
                                                      case '<': s[i]='C';
                                                      break;
                                                      case '=': s[i]='D';
                                                      break;
                                                      case '>': s[i]='E';
                                                      break;
                                                      case '?': s[i]='F';
                                                      break;
                                                      default : 
                                                      break;
                                          }
               }
         }
                                       
                          
                  
                  

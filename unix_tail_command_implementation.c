#include<stdio.h>
#include<conio.h>
#include<string.h>
# define MAXLINE 5000
# define MAXLEN 1000
int getline(char line[],int max);
char *lineptr[MAXLINE];
int read(char *lineptr[], int nlines);
void write(char *lineptr[], int ,int);
char *alloc(int );
char buf[2000];
char *allocp =buf;

main()
{
      int n;
    printf("how many lines u want to print from below \n");
      scanf("%d",&n);
     
      int nlines;
      if((nlines = read(lineptr,MAXLINE))>=0)
      {
                 if(n>nlines)
                 n=nlines;
                 if(n==0)
                 n=10;
                 write(lineptr,n,nlines);
             getch();     
                  return 0;}
      else
       {getch();
      return 1;
      }
      }
int read(char *lineptr[], int maxlines){
    int nlines=0;
    char *p,line[MAXLEN];
    int len;
    
    while((len=getline(line,MAXLEN))>0)
    {
                                       if((p=alloc(len)) == NULL)
                                       {printf("not enough memory");
                                       return -1;}
                                       else{
                                       line[len-1] ='\0';
                                       strcpy(p,line);
                                       lineptr[nlines++]=p;
                                       }
                                      
                                      
                                       }
                  return nlines;                       
             }
void write(char *lineptr[], int n,int nlines)
{
     int i,j;
     for(i=nlines,j=n;i>=0 && j>=0;i--,j--)
     {
                          printf("%s \n",lineptr[i]);
                          }
                          }
int getline(char s[],int lim)
{   
    int i,ch;    
    for(i=0; i<lim-1 && (ch=getchar())!= EOF && ch!='\n';++i)
    s[i]=ch;
    
                s[i]='\0';
                return i;
                }
                
  char *alloc(int len)
  {
       if((buf + 2000 -allocp)>=len)
       {
               allocp+=len;
               return allocp-len;
               }
               else
               {
                  
                   return 0;
                   }
                   }

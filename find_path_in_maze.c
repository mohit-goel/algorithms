#include<stdio.h>
#include<conio.h>
#define max 3
#define true 1
#define false 0

int  find_path(int x,int y);
int startx=0,starty=0;
int endx=2,endy=2;
char maze[max][max];
main()
{   
    int i,j=0;  
    
    printf("'#' for obstacles \n '+' for marking  \n 'x' for unmarking");
    for(i=0;i<max;i++)
    {
         for(j=0;j<max;j++) 
             scanf(" %c",&maze[i][j]);
    }
    for(i=0;i<3;i++)
    {  printf("\n");
         for(j=0;j<3;j++) 
             printf("%c",maze[i][j]);
             }
    //printf("enter starting and ending coordinates");
    //scanf("startx=%d starty=%d endx=%d endy=%d",&startx,&starty,&endx,&endy);
    find_path(startx,starty);
    for(i=0;i<3;i++)
    {
    printf("\n");
         for(j=0;j<3;j++) 
             printf("%c ",maze[i][j]);}
                  
  getch();
return;
}

int  find_path(int x,int y)
{    
     char c = '#';
     char ch = '+';
     if(x == endx && y==endy)
     { maze[x][y]='+';
     return true;
     }
     if(x>= max || y >=max || x<0 || y<0)
     return false;
     if(maze[x][y] != '.')
     return false; 
     maze[x][y]='+';
     if(find_path(x-1,y) == true) return true;
if(find_path(x,y+1) == true) return true;
if(find_path(x,y-1) == true) return true;
if(find_path(x+1,y) == true) return true ;
     maze[x][y]='x';
     return false;
     }




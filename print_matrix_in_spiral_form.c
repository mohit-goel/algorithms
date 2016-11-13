#include <stdio.h>
#include<conio.h>

void print_layer_top_right(int a[][4], int x1, int y1, int x2, int y2);
void print_layer_bottom_left(int a[][4], int x1, int y1, int x2, int y2);

int main(void)
{
       int a[5][4] = {
                       {1,2,3,4},
                       {5,6,7,8},
                       {9,10,11,12},
                       {13,14,15,16},
                       {17,18,19,20}
                   };

       print_layer_top_right(a,0,0,4,3);
       getch();
}
void print_layer_top_right(int a[][4], int x1, int y1, int x2, int y2)
{
    int i,j;
    for(i=y1;i<=y2;i++)
    printf("%d ",a[x1][i]);
   
    
    for(i=x1;i<x2 ;i++)
        printf("%d ",a[i+1][y2]);
        if(x2-x1){
        
     print_layer_bottom_left(a,x1+1,y1,x2,y2-1);}
     else return ;
     
    }   
void print_layer_bottom_left(int a[][4], int x1, int y1, int x2, int y2){
    int i,j;
    for(i=y2;i>=y1;i--)
    printf("%d ",a[x2][i]);
   
    
    for(i=x2;i>x1 ;i--)
        printf("%d ",a[i-1][y1]);
        if(x2-x1){
        
     print_layer_top_right(a,x1,y1+1,x2-1,y2);}
     else return;
    }

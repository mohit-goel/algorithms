#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void readinput(int *a[], int rows,int cols);
void transpose(int *a[],int *b[],int rows,int cols);
void writeoutput(int *b[],int rows,int cols);
  main()
{
  int rows,cols,i,j;

int *a[rows];
int *b[cols];
printf("enter elements of original matrix");
printf("enter number of ROWS AND COLUMNS OF RESPECTIVE MATRIX");
scanf("%d%d",&rows,&cols);


for(i= 0;i<rows;i++)
{
       a[i] = (int *)malloc(cols * sizeof(int));
}
for(j= 0;j<cols;j++)
{
       b[j] =(int *)malloc(rows * sizeof(int));
}
printf("enter the values of required matrix");       
readinput(a,rows,cols);
//writeoutput(a,rows,cols);

transpose(a,b, rows, cols);
printf("transpose of given matrix is");
writeoutput(b,rows,cols);
getch();

}
void readinput(int *a[], int rows,int cols)
{    int m,n;
     for(m=0;m<rows;m++)
     {
     for(n=0;n<cols;n++)
     scanf("%d",(a[m]+n));
     }
     
}
void transpose(int *a[],int *b[],int rows,int cols)
{
     int m,n;
     
    for(m=0;m<rows;m++)
    {
       for(n=0;n<cols;n++)
     
      *(b[n]+m) = *(a[m]+n);

      }

}                      
void writeoutput(int *b[],int rows,int cols)
{
     int m,n;
      for(m=0;m<cols;m++)
    {
       for(n=0;n<rows;n++)
        
                          printf("%d   " , *(b[m]+n));
                          printf("\n");
        
    }
    
}


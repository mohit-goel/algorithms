//Most significant order radix sort
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
char * k_msb(int n, int k);
void sort1(char *p[],int x,int y,int bits);
int main()
{
    int sum=0;
    int g;
    int arr[9] = {170,45,75,90,2,24,802,66};
    char * b[8];
    int k,i,j=0;
    for(i=0;i<8;i++)
     b[j++]= k_msb(arr[i],32);
     for(i=0;i<8;i++)
    cout<<b[i]<<"\n";

     sort1(b,0,7,0);

for(i=0;i<8;i++)
{sum = 0;
g=9;
    for(j=0;j<10;j++)
    {
        sum = sum+ ((b[i][j]-'0')*pow(2,g));
        g--;
    }
    cout<<sum<<"\n";
}
        
        

   for(i=0;i<8;i++)
    cout<<b[i]<<"\n";
getch();
    return 0;
}


void sort1(char *p[],int x,int y,int count)
{ 
int q=0;
 int i,j,u;char *t;
    if((count <10) && (y-x>0))
    {
   
    i=x-1;
    j=y+1;

   
    while(1)
    {
    do{
        j--;
    }while(p[j][count] == '1');
    do{
    i++;
    }while(p[i][count] == '0');
    if(i<j)
    {
        t = p[i];
        p[i]= p[j];
        p[j] = t;
    }
    else break;
    }
     printf("before exhange i=%d  j=%d \n",i,j);
    cout<<"\n"<<"for exchange"<<count<<"\n";
    printf("i=%d  j=%d \n",i,j);
    for(u=0;u<8;u++)
    cout<<p[u]<<"\n";
    q=count+1;
    sort1(p,x,j,q);
    sort1(p,i,y,q);
    }
}
















char * k_msb(int n, int k)
{

    char *t;
     int mask;
     int count=0;
     int r,i,b;
     b=0;
     t= (char *)malloc(sizeof(char)*11);

     for( i=9;i>=0;i--)
     {

         mask=1<<i;
         r=mask&n;
         if(r==0)
         t[b]='0';
         else t[b] ='1';
         count++;
         b++;

      }
      t[10] ='\0';
return t;
  }

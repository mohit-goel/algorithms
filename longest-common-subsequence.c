#include<stdio.h>

int lcs(int x,int y);
char X[]={'a','b','c','b','d','a','b'};
char Y[]={'b','d','c','a','b','a'};

int main()
{

    lcs(7,6);
    return 0;
}
int  lcs(int x,int y)
{
    int a,b,count;
    if(x==0 || y==0)
    return 0;

    else if(X[x] == Y[y])
    {
       count = lcs(x-1,y-1)+1;
       printf("%d%c ",count,X[x]);
    }
    else
    {
        a=lcs(x-1,y);
        b= lcs(x,y-1);
        if(a>b)count =a;
        else count =b;
    }
    return count;
}


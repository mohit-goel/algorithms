#include<stdio.h>
char arr[100];
int j;
int comb(int n);
void myprint(char arr[]);
int main()
{
    int n,i,p;
    scanf("%d",&n);
p=0;
    comb(n);

    return 0;
}
int comb(int n)
{int  i,x,v;
int t;
    if(n==0)
    return  0;
   else  if(n==1)
    {
    arr[j++] ='(';
    arr[j++] =')';
    if(j==6)
    {myprint(arr);

    return 1 ;}
    else return 0;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            t=j;
            arr[j++] ='(';

            v=comb(i);

            arr[j++] =')';
 if(j==6)
    myprint(arr);

            x=comb((n-i-1));
            if(x==1)
            j=t;
            else {
                return i;
            }
        }
        return 1;
    }
}

void myprint(char arr[])
{
    int i ;
    printf("\n");
    for(i=0;i<=j;i++)
    printf("%c ",arr[i]);

}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
  int k;
  int count =0;
main()
{     
    
      int n;
       printf("enter whoz different ways of sum has to be determined ");
         scanf("%d",&k);
         printf("enter nmber such operands r less than dis one ");
        scanf("%d",&n);
        sum(n);
        printf("total no of ways of sum of number %d is %d",k,count);
       
  getch();
return;
}


int sum(int n)
{
    int i;
    
    for(i=1;i<=n;i++)
    {
                     if((n+sum(n-i))==k)
                      count++;
                      }
                      return n;
                      }



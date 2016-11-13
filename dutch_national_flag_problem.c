#include<stdio.h>
#include<string.h>
#define SWAP(a,b,c) (c)=(a),(a)=(b),(b)=(c)
int main()
{
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
              //char str[100];
              //scanf("%s",str);
               int str[] = {0,1,2,0,1,2,0,0,2,0,1,1,1,2,2,2,0,2,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,1,1};
              int i=0,j=0,k=35;

              while(str[i]==0)
              i++;
              while(str[k]==2)
              k--;

              j=i;
              while(j<=k)
              {
                         if(str[j]==2)
                         {
                         SWAP(str[j],str[k],x);
                         k--;
                         }

                         if(str[j]==0)
                         {
                                        SWAP(str[i],str[j],x);
                                        i++;
                                        j++;
                                        }
                          if(str[j]==1)

                          j++;
                                        }

              for(i=0;i<=35;i++)
              printf("%d",str[i]);
              }
    return 0;
}

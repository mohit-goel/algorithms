#include<iostream>
#include<string.h>

using namespace std;
void buildsubsets(int i,int j,char subset[]);
char  arr[5]={'1','2','3','4','5'};
int k =3;
int n=5;
int main()
{
        buildsubsets(0,0,"");

}

void buildsubsets(int i,int j,char subset[])
{
     char temp [5];
     strcpy(temp,subset);

          if(j==k)
         {
           cout<<subset<< " ";
           return ;
       }

for(;i<n;++i)
{temp[j]=arr[i];
buildsubsets(i+1,j+1,temp);
}

}

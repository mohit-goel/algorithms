#include <stdio.h>

#define SIZE 3
int main(int argc,char *argv[])
{
char list[3]={'a','b','c'};
int i,j,k;

for(i=0;i < SIZE;i++)
for(j=0;j < SIZE;j++)
for(k=0;k < SIZE;k++)
if(i!=j && j!=k && i!=k)
printf("%c%c%c\n",list[i],list[j],list[k]);

return(0);

}

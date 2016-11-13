//http://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
#include<stdio.h>
int main()
{
  int arr[]={1, 3, 5 ,8 ,9 ,2 ,6, 7, 6, 8, 9};
  int size=sizeof(arr)/sizeof(int);

  int i=0,jump=0,step,max,j;

  while( i< size)
  {
     jump++;
     max=0;
    step=0;
   
   for(j=1;j<=arr[i];j++)
   {
      if(arr[i+j]+j>max)
      {
          max=arr[i+j]+j;
         step=j;
      }
   }
   i=i+step;
}

  printf("%d ",jump);

}

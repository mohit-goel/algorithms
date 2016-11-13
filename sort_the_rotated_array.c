#include<stdio.h>

#define n 10
#define SWAP(a, b) {a=a+b; b=a-b; a=a-b;}
 int findPivot( int low, int high);
int sort_sorted(int);

int arr[n] = {19,20,26,52,1,3,5,7,9,15,};

int main()
{

    int i,j,inc,dec,index;
    inc=dec=0;
    i=0;
   /*
    if(arr[i]<arr[i+1])
        inc=1;
        else dec=1;
    for(i=1;i<n-1;i++)
    {
        if(inc && arr[i]>arr[i+1])
      {
            index =i;
            break;
        }
         if (dec &&  arr[i]<arr[i+1])
        {
            index =i-1;
            break;
        }

    }*/
    index =findPivot(0,n-1);
    printf("%d",arr[index]);
    reverse(0,index);
    reverse(index+1,n-1);
    reverse(0,n-1);

    for(i=0;i<n;i++)
    printf("%d ",arr[i]);


    return 0;
}
int  reverse(int i,int j)
{
    while(i<j)
    {
        SWAP(arr[i],arr[j]);
        i++;
        j--;
    }
}
int findPivot( int low, int high)
{
   int mid = (low + high)/2;   /*low + (high - low)/2;*/
   if(arr[mid] > arr[mid + 1])
     return mid;
   if(arr[low] > arr[mid])
     return findPivot( low, mid-1);
   else
     return findPivot( mid + 1, high);
}


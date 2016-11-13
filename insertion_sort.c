#include<stdio.h>
#include<conio.h>
int binsearch( int v[],int x, int n);
void  insertion_sort(int n);
int arr[] ={8,89,3,1,76,6,9,7};
int res[6];
main()
{
      int n, i;
      
      n=7;
      insertion_sort(n);
      for(i=0;i<n+1;i++)
      printf("%d",arr[i]);
      
      getch();
      return 0;
      }
      
void  insertion_sort(int n)
{int pos;
int k;int tmp;
      if(n>1)
      insertion_sort(n-1);
     pos = binsearch(arr,arr[n],n);
     tmp =arr[n];
     for(k=n-1;k>=pos;k--)
     arr[k+1]=arr[k];
     arr[pos] =tmp;
     }
     
     
      
      
      
int binsearch( int v[],int x, int n)
   {
       int low, high, mid;

       low = 0;
       high = n - 1;
       while (low <= high) {
           mid = (low+high)/2;
           if (x < v[mid])
               high = mid -1;
           else if (x  > v[mid])
               low = mid + 1;
          
               
       }
       return low;
         }

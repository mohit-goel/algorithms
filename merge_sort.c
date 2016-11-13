#include<stdio.h>
#include<conio.h>
 void merge_sort(int arr[],int low,int high);
      void  merge(int arr[],int low,int mid,int high);
int arr[] ={8,89,3,1,76,6,9,7};
int aux[7];
int b;
main()
{
      int n, i;
      int arr[] ={8,89,3,1,7,6,9};
      n=6;
      merge_sort(arr,0,6);
      for(i=0;i<n+1;i++)
      printf("%d ",arr[i]);
      
      getch();
      return 0;
      }
      
      void merge_sort(int arr[],int low,int high)
      {int mid,k;
           if(low<high)
           {
                       mid =(low+high)/2;
                       merge_sort(arr,low,mid);
                       merge_sort(arr,mid+1,high);
                       merge(arr,low,mid,high);
                       
              
                       }
                       }
     void  merge(int arr[],int low,int mid,int high)
       {int i,j,k,small;
           if(low<=mid && mid<=high)
           {
            b=low;
            i=low;
            j=mid+1;
            /*if(i==mid && j==high)
            return;
            if(i==mid && j<high)
            {while(j<high)
            aux[b++] =arr[j++];
            return ;
                      }        
             if(j==high && i<mid)
            {while(i<mid)
            aux[b++] =arr[i++];
            return ;
                      }  
                      */
            if(arr[i]<arr[j])
            {small =arr[i];
            i++;
              aux[b++] =small;
            merge( arr, i, mid, high);
             if(low >mid)
               {
                      if(mid<=high)
                      {            j=mid;
                                   while(j<=high)
                                   aux[b++] =arr[j++];
                                   
                      } 
                       
                      
               }  
                if(mid >high)
               {
                      if(low<=mid)
                      {            i=low;
                                   while(i<=mid)
                                   aux[b++] =arr[i++];
                                   
                      } 
                       
                      
               }  
            }
            else{ small= arr[j];
                  j++;
                  
                   aux[b++] =small;
                  merge( arr, low, j, high);
                   if(low >mid)
               {
                      if(mid<=high)
                      {            j=mid;
                                   while(j<=high)
                                   aux[b++] =arr[j++];
                                   
                      } 
                       
                      
               }  
                if(mid >high)
               {
                      if(low<=mid)
                      {            i=low;
                                   while(i<=mid)
                                   aux[b++] =arr[i++];
                                   
                      } 
                       
                      
               }  
                 }    
              
               
                for(k=low;k<high;k++)
               arr[k] =aux[k];
              
           }
              
                
        }      
                           

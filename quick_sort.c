#include<stdio.h>
#include<conio.h>
typedef struct mu
{
        int sp,wj,wr;
}node;
    int partition(node **p,int m,int n); 
     void  quicksort(node **p,int i,int j);    
main()
{
     node **p;
      int i;
      p= (node**)malloc(6* sizeof(node *));

      for(i=0;i<2;i++)
      {
                      *(p+i) =(node *)malloc(sizeof(node));
                      scanf("%d %d %d",&(p[i]->sp),&(p[i]->wj),&(p[i]->wr));
                      
      }
      for(i=0;i<2;i++)
      {
                      printf("\n");
                      printf("%d %d %d",(p[i]->sp),(p[i]->wj),(p[i]->wr));
                      
      }
       quicksort(p,0,1);
       for(i=0;i<2;i++)
      {
                      printf("\n");
                      printf("%d %d %d",(p[i]->sp),(p[i]->wj),(p[i]->wr));
                      
      }
       
                       getch();
                       return 0;
                       }
       
      
     void  quicksort(node **p,int i,int j)
      {int  q;
                     if(i < j)
                     {
                    q= partition(p,i,j);
                     quicksort(p, i, q - 1);
                     quicksort(p, q + 1, j);
                     }
      }
      int partition(node **p,int m,int n)
      {     node *x,*t;
           // x=t=NULL;
            int i,j;        
                     x =p[n];
                    i= m - 1;
                    for (j =m; j< n;j++)
                    {
                        
                        if ((p[j]->wj) <= x->wj)
                        {
                                       
                                        i=i+1;
                                        t =p[i];
                                        p[i]=p[j];
                                        p[j]=t;
                                        }
                        }
                   t =p[i+1];
                   p[i+1]=p[n];
                   p[n]=t;                    
  return (i + 1);
}
      
        
        

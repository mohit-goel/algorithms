#include<stdio.h>
void partition(int A[],int p,int q,int med);
void insertion_sort(int A[],int p,int q);
 int divide(int A[],int B[],int *b,int n);
 void display(int v);
int main()
{
int i ,b=0,grp;

int B[100];
   // int A[]={5,7,3,2,8,9,6,11,12,10,14};
   int A[]={3,2,5,7,8,9,6};
    grp =divide(A,B,&b,2);
 printf("%d ",grp);
    //partition(A,0,6,5);
    //insertion_sort(A,5,6);
   // for(i=0;i<7;i++)
    //printf("%d ",A[i]);
   for(i=0;i<b;i++)
    printf("%d ",B[i]);
   //display(ceil(2.4));

    return 0;
}


void partition(int A[],int p,int q,int med)
{
    int small,large,temp,in;
    small =p;
    large= q;
    while(1)
    {
        while(A[small]<=med && small<=large)
        { if(A[small] == med)
        in=small;
            small++;
        }
        while(A[large]>med && small<=large)
        { if(A[large] == med)
        in=large;
        large--;
        }
        if(small<large )
        {
            if(A[small] == med)
            in =large;
            if(A[large] == med)
            in =small;

            temp=A[large];
            A[large] = A[small];
            A[small] =temp;
            small++;
            large--;
        }

    if(small>large)
    {
            temp=A[large];
            A[large] = A[in];
            A[in] = temp;

            break;
    }

    }
}
void insertion_sort(int A[],int p,int q)
{
    int i ,j,k,temp;
    if(q-p+1 == 1)
    return ;

    for(i=p+1;i<=q;i++)
    {
        temp=A[i];
        k=i;
        while(k!=p  && A[k-1]>temp)
        {
            A[k] =A[k-1];
            k--;
        }
        A[k] =temp;

    }
}
 int divide(int A[],int B[],int *b,int n)
    {
        int i,j,count =0,size=n,x;

        while((size-5) >=0 && size >0)
        {
        i =count *5;
        j =i+5-1;
        count++;
        size-=5;
        insertion_sort(A,i,j);
        x=(i+j)/2;
        B[(*b)++]=A[x];
        }
        if(size!=0 && count !=0)
        {
            i=j+1;
        j =i+size-1;
        insertion_sort(A,i,j);
        x=(i+j)/2;
        B[(*b)++]=A[x];
        count++;
        }
         if(size!=0 && count ==0)
         {
             i=0;j= i+size-1;
             insertion_sort(A,i,j);
        x=(i+j)/2;
        B[(*b)++]=A[x];
        count++;
         }
        return count;
    }


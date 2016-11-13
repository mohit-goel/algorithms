//Median of medians algorithm
#include<stdio.h>
#include<math.h>

int median(int A[],int k,int p,int q);
int divide(int A[],int B[],int *b,int,int,int);
void insertion_sort(int A[],int p,int q);
int  partition(int A[],int p,int q,int med);



int main()
{
     int i,j,m,n;
    //int A[100];
int A[]={5,7,3,2,8,9,6,11,12,10,14,23,65,78,34,13};
 // printf("enter number of elements ");
 // scanf("%d",&n);
    i=j=0;
    //  printf("enter elements ");
//for(i=0;i<100;i++)
   /* {A[i]=0;

        }
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);*/
n=16;
    m = median(A,12,0,n-1);

    printf("%d",m);

    return 0;
}
int median(int A[],int k,int p,int q)
{//printf("rank%d ",k);
    if((q-p+1)==1)
return A[0];
int B[100],i,mt,id,b,part,z,f;
int grp=0;
for(i=0;i<100;i++)
    B[i]=0;


b=0;
    grp =divide(A,B,&b,q-p+1,p,q);
    if(grp%2 !=0)//........................
f= grp/2 +1;
else
f= grp/2;
    mt = median(B,f,0,grp-1);

   part =  partition(A,p,q,mt);

z=part-p+1;
if(k==z)
return A[part];

else if(k<z)
return median(A,k,p,part-1);
else return median(A,k-z,part+1,q);
}







  int divide(int A[],int B[],int *b,int n,int p,int q)
    {
        int i,j,count =0,size=n,x;

        while((size-5) >=0 && size >0)
        {
        i =count*5 +p;
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
             i=p;j= i+size-1;
             insertion_sort(A,i,j);
        x=(i+j)/2;
        B[(*b)++]=A[x];
        count++;
         }
        return count;
    }


void insertion_sort(int A[],int p,int q)
{
    int i ,j,k,temp;

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

int  partition(int A[],int p,int q,int med)
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
    return large;
}




#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int pow10[]={1,10,100,1000,10000,100000,1000000};
typedef struct queue * queptr;
typedef struct node * nodeptr;
queptr sort1(queptr arr,int digits);
typedef struct queue
{
    int total;
    nodeptr front;
    nodeptr rear;
}queue;
typedef struct node
{

    int data;
    int flag;
    nodeptr next;
}node;


int main()
{
    int i,j,n;
    nodeptr p,tmp;
    queptr q;
    int digits,num;
    q = (queptr)malloc(sizeof(queue));
    q->front =NULL;
    q->rear=NULL;
    q->total=0;
    printf("enter how many  numbers");
    scanf("%d",&n);
      printf("enter  numbers");
      for(i=0;i<n;i++)
      {
                    scanf("%d",&num);
        p = (nodeptr)malloc(sizeof(node));
         p->next =NULL;
         p->data =num;
         p->flag=1;
          if(q->front ==NULL)
         q->front= p;
         else
         q->rear->next =p;
        q->rear = p;
         q->total++;
      }

      //digits= floor(log10(max)) +1;
    q =  sort1( q,1);

       while(q->front!=NULL)
      {
          j=q->front->data;
          tmp =q->front;
         q->front=q->front->next;
          printf("%d ",j);
          free(tmp);
      }

      return 0;
}

queptr sort1(queptr arr,int digits)
{
    if(arr->total ==0)
    return NULL;
     if(arr->total ==1 )
    return arr;
int flag =0;

    queptr b[10];
    queptr poo,q,tmp1;
    nodeptr p,tmp;
    int i,j,dig,index,t;
    tmp=arr->front;
     while(tmp!=NULL)
    {
        if(tmp->flag == 1)
        {
            flag = 1 ;
            break;
            }

        tmp =tmp->next;
        }
        if(flag == 0)
        return arr;
    for(i=0;i<10;i++)
    {
        b[i] = (queptr)malloc(sizeof(queue));
        b[i]->front=NULL;
        b[i]->rear=NULL;
        b[i]->total=0;
        }
         while(arr->front!=NULL)
      {
          t =arr->front->data;
         dig= floor(log10(t))+1 - digits;
         if(dig<0)

             dig =0;

         index = ((int)(t/pow10[dig]))%10;

         p = (nodeptr)malloc(sizeof(node));
         p->next =NULL;
         p->data = arr->front->data;
         if(dig==0)
           p->flag=0;


         if(b[index]->front ==NULL)
         b[index]->front= p;
         else
         b[index]->rear->next =p;
         b[index]->rear = p;
         b[index]->total++;


         arr->front=arr->front->next;

    }
    for(i=0;i<10;i++)
    {
      poo  =sort1(b[i],digits+1);
      if(poo !=NULL){


      b[i]->front=poo->front;
      b[i]->rear=poo->rear;
      b[i]->total=poo->total;
    }

    }

    j=0;
    q = (queptr)malloc(sizeof(queue));
     q->front =NULL;
    q->rear=NULL;
    q->total=0;
     for(i=0;i<10;i++)
     {
         while(b[i]->front !=NULL)
         {
            p = (nodeptr)malloc(sizeof(node));
         p->next =NULL;
         p->data = b[i]->front->data;
         p->flag= b[i]->front->flag;
         if(q->front ==NULL)
         q->front= p;
         else
         q->rear->next =p;
        q->rear = p;
         q->total++;
        tmp =b[i]->front;
         b[i]->front=b[i]->front->next;
         free(tmp);
         }
     }
     return q;
}



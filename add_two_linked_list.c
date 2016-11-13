#include<stdio.h>
#include<conio.h>
typedef struct node *  nodeptr;
typedef struct node
{
        int info;
        struct node * next ;
        }node;


main()
{
      nodeptr num1,num2,res,r,t;
      num1=num2=NULL;
      res =r=t=NULL;
      nodeptr p,q;
      p=q=NULL;
      int n,carry=0,value,x,y;
      printf("enter first no: enter 'a' when finish entering the number ");
      while(1)
      {

              p = (nodeptr)malloc(sizeof(node));
              scanf("%d",&n);
              if(n==97)
              break;
              p->info = n;
              p->next =NULL;
              
              if(num1==NULL)
              {num1=p;
              q=p;
              }
              else
              {
                  q->next =p;
                  q=p;
                  }
        }
              
              
      
      printf("enter second no:");
      while(1)
      {
              
              p = (nodeptr)malloc(sizeof(node));
              scanf("%d",&n);
              if(n==97)
              break;
              p->info = n;
              p->next =NULL;
              
              if(num2==NULL)
              {num2=p;
              q=p;
              }
              else
              {
                  q->next =p;
                  q=p;
              }
      }
      
    p=num1;
    q=num2;
    while(1)
    {if(p==NULL && q==NULL)
    break;
                  if(p!=NULL)
                  x= p->info;
                  else x=0;
                  
                  if(q!=NULL)
                  y =q->info;
                  else y=0;
                  
                  value = carry + x + y;
                  if(value >9)
                  carry =1;
                  else  carry =0;
                  value = value%10;
                  
                  r = (nodeptr)malloc(sizeof(node));
                  r->info =value;
                  r->next =NULL;
                  if(res ==NULL)
                  res =r;
                  else
                  {r->next =res;
                  res =r;
                      }
                      if(p!=NULL)
                      p=p->next ;
                      if(q!=NULL)
                      q=q->next;
                      }
    p=res;
    printf("%d",carry);
    while(p!=NULL)
    {
     printf("%d",p->info);
    p=p->next;
              }
              
              
              getch();
              return ;
              }       
                  
      

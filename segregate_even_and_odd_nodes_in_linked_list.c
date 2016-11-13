#include<stdio.h>
#include<stdlib.h>
# define null 0
typedef struct list * nodeptr;
typedef struct  list{
        int value;
        nodeptr next;
        }list;

main()
{
      nodeptr head,tail,p,oddp,evenp,q;
      head=tail=p=oddp=evenp=q=null;
      int num,t;
  int count =0;
      scanf("%d",&num);
      while(num!=null)
      {               count++;
                      p=(nodeptr)malloc(sizeof(list));
                      p->value=num;
                      p->next=null;
                      if(head==null)
                      {
                                    head=p;
                                    q=head;
                                    }
                      else
                      {
                          q->next =p;
                          q=p;
                      }
                       scanf("%d",&num);
      }
       tail =q;
      // printf("\n%d",q->value);
      p=head;
      while(p!=null)
      {
                    printf("%d",p->value);
                    p=p->next;
                    }
      p=head;
      while(count--)
      {

                    num =p->value;
                    if(num%2 ==0)
                    {
                             evenp=p;
                             p=p->next;
                    }
                    else{
                         if(p==head)
                         {
                                    q->next =p;
                                    q=q->next;
                                    p=p->next;
                                    head=p;
                                    q->next =null;
                         }
                         else
                         {
                             evenp->next=p->next;
                             q->next=p;
                             q=q->next;
                             q->next =null;
                             p=evenp->next;


                         }
                    }
                    }
                         printf("\n\n");
                     p=head;
                     while(p!=null)
                     {
                    printf("%d",p->value);
                    p=p->next;
                    }





                    return 0;
                    }




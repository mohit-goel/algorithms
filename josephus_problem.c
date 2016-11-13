#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct node *nodeptr;
void insert(nodeptr *,char []);
void josep(nodeptr *);
typedef struct node 
{
        char * ch;
        nodeptr next;
        } node;
nodeptr p =NULL;
int n;
main()
{     nodeptr q;
 char c[]="end";
 char name[20];
 printf("enter number n \n");
  scanf("%d",&n);
 printf("enter the name beginning with soldier frm whom count is to start \n");
 scanf("%s",name);
 while(strcmp(name,c))
  {
           insert(&p,name);
           scanf("%s",name);
  }
   josep(&p);
  getch();
return;
}
void insert(nodeptr *ptr,char name[])
{
     nodeptr q;
     q =(node *)malloc(sizeof(node));
      q->ch =(char *)malloc(sizeof(name));
     strcpy((q->ch),name);
     if((*ptr)==NULL)
     *ptr =q;
     else
     q->next =(*ptr)->next;
     (*ptr)->next =q;
     (*ptr)=q;
     return ;
}
void josep(nodeptr *ptr)
{
     nodeptr q,pt;
     char name[20];
     int j=0;
     if(*ptr == NULL)
     exit(1);
       q = (*ptr)->next;
     while(q != q->next)
     {
                     
          pt =q;
          for(j=0;j<n-1;j++)
          {
             q=pt;
             pt =q->next;
                } 
                    if(pt ==q)
                    q =*ptr; 
                                                
                  
      
          printf("%s ",(pt->ch)) ;
                         
         
         q->next =pt->next;
         q=pt->next;
         free(pt);
     }
     printf("\n escape on horse is %s",q->ch);
     free(q);
}
         
                           
     
     



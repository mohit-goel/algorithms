
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct tree * nodeptr;
typedef struct tree
{
        int data;
        struct tree *lchild,*rchild,*next;
}tree;
void insert(tree *);
nodeptr maxpath(nodeptr root,int * pt);

int main()
{

int level=0,i,j,sum=0;

      tree *root,*leave,*nwptr;
      char a;
      nwptr=(tree *)malloc(sizeof(tree));

      a=getche();
      nwptr->data=a-48;
      //printf("%d",nwptr->data);
      nwptr->lchild=NULL;
      nwptr->rchild=NULL;
      nwptr->next=NULL;
      root=nwptr;
     leave=nwptr;
      insert(leave);

nodeptr result = NULL;

result = maxpath(leave,&sum);
      nwptr = result;
      while(nwptr!=NULL)
      {
          printf("%d",nwptr->data);
          nwptr = nwptr->next;}

    getch();
      return 0;
}
void insert(tree *root)
{
     tree *nwptr;
     char a;
     char ch;
     printf("\ndoes the node containing %d have left child y/n ?",root->data);
     ch=getche();
      //printf("%c",ch);
     if(ch=='y')
     {
                printf("\nenter the value of left child");
                a=getche();
                //fputc(a,f1);
                nwptr=(tree *)malloc(sizeof(tree));
                nwptr->data=a-48;
                nwptr->lchild=NULL;
                nwptr->rchild=NULL;
                nwptr->next=NULL;
                root->lchild=nwptr;
                    insert(root->lchild );
     }
 printf("\ndoes the node containing %d have right child y/n ?",root->data);
     ch=getche();
    // fputc(ch,f1);
     if(ch=='y')
     {
                printf("\nenter the value of right child");
                a=getche();
              //  fputc(a,f1);
                nwptr=(tree *)malloc(sizeof(tree));
                nwptr->data=a-48;
                nwptr->lchild=NULL;
                nwptr->rchild=NULL;
                nwptr->next=NULL;
                root->rchild=nwptr;

    insert(root->rchild );
     }
}

nodeptr maxpath(nodeptr root,int * pt)
{
    if(root ==NULL)
    {
        *pt =0;
        return NULL;
    }

    nodeptr temp,left,right;
    int leftsum,rightsum;
    temp = (nodeptr)malloc(sizeof(tree));
    temp->data = root->data;

    left = maxpath(root->lchild,pt);
    leftsum =*pt;
    *pt=0;
    right = maxpath(root->rchild,pt);
    rightsum =*pt;
    *pt =0;



    if(leftsum >=rightsum)
    {
        temp ->next = left;
        *pt = root->data + leftsum;

        }
        else{
            temp ->next = right;
        *pt = root->data + rightsum;

            }

            return temp;
    }


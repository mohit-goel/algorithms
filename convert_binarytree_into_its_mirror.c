#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node *nodeptr;


nodeptr maketree(nodeptr p,int number);
void setleft(nodeptr p,int number);
void setright(nodeptr p,int number);
void inorder(nodeptr p);
nodeptr mirror_tree(nodeptr tree);
typedef struct node 
{
        int info;
        nodeptr left;
         nodeptr right;
                
        } node;
main()
{     

     nodeptr ptree,p,q,mirror;
     int number;
     scanf("%d",&number);
     p= NULL;
     ptree =maketree(p,number);
     while(scanf("%d",&number)!=EOF)
     {
                                    p=q=ptree;
                                    while(number != p->info && q!= NULL)
                                    {
                                                 p=q;
                                                 if(number < p->info)
                                                 q= p->left;
                                                 else 
                                                 q =p->right;
                                    }
                                    if(number == p->info)
                                    printf("duplicate %d",number);
                                    else if(number <  p->info)
                                    setleft(p,number);
                                    else 
                                    setright(p,number);
     }
     printf("traversal of the original tree \n");
    inorder(ptree); 
    mirror = mirror_tree(ptree);
    printf("traversal of the mirror tree \n");
    inorder(mirror); 
    
                 
  getch();
  return 0;
}
nodeptr maketree(nodeptr p,int number)
{
        nodeptr q;
        q =(nodeptr)malloc(sizeof(node));
        q->info =number;
        q->left =NULL;
        q->right =NULL;
        return q;
}
void setleft(nodeptr p,int number)
{
     if(p==NULL)
     printf("void insertion ");
     else
     p->left =maketree(p,number);
     }
void setright(nodeptr p,int number)
{
     if(p==NULL)
     printf("void insertion ");
     else
     p->right =maketree(p,number);
}

void inorder(nodeptr p)
{
     if(p!=NULL)
     {
                inorder(p->left);
                printf(" p is %d \n" ,p->info);
                
                 inorder(p->right);
     }
}    
 
nodeptr mirror_tree(nodeptr tree)
{
        if(tree ==NULL)
        return NULL;
        else
        {
            nodeptr p;
            p =(nodeptr)malloc(sizeof(node));
            
            p->left = mirror_tree(tree->right);
            p->right = mirror_tree(tree->left);
            p->info =tree->info;
            
            return p;
            }
            }
            
        
            
            


 #include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node *nodeptr;
nodeptr hanoi_tree(char from,char to,char aux,int level);
void inorder(nodeptr p);
int number;
typedef struct stack{
        int item[4];
        int top;
        }stack;
        stack A,B,C;


typedef struct node
{
        char from;
        char to;
        nodeptr left;
         nodeptr right;

        } node;

main()
{
      A.top =B.top =C.top =-1;
     nodeptr ptree;
     int level =-1;
     int i,j;



     scanf("%d",&number);
     j=number;
      for(i=0;i<number;i++)
          {
                            A.item[++(A.top)] =j;
                            j--;
                            }
     ptree =hanoi_tree('A','C','B',level);


     inorder(ptree);

  getch();

  return 0;
}


nodeptr hanoi_tree(char from,char to,char aux,int level)
{       level++;
        if(level > number-1)
        return NULL;
        else
        {
            nodeptr p;
            p =(nodeptr)malloc(sizeof(node));
             p->from =from;
            p->to =to;
            p->left = hanoi_tree( from,aux,to,level);
            p->right = hanoi_tree(aux,to,from, level);
            return p;
            }
}
void inorder(nodeptr p)
{
     int x,y;
     if(p!=NULL)
     {
                inorder(p->left);
                if(p->from =='A')
                x =A.item[(A.top)--];
                if(p->from =='B')
                x =B.item[(B.top)--];
                if(p->from =='C')
                x =C.item[(C.top)--];

                if(p->to == 'A')
                A.item[++(A.top)]=x;
                if(p->to == 'B')
                B.item[++(B.top)]=x;
                if(p->to == 'C')
                C.item[++(C.top)]=x;
                 printf("move %d from %c-to-%c \n",x,p->from,p->to);

                 inorder(p->right);
     }
}






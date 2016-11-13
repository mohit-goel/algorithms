#include<conio.h>
#include<stdio.h>
typedef struct node * nodeptr;
typdef nodeptr * list;
struct node
{
    int data;
    struct node* left;
    struct node* right;
    struct node* next;
    
};
 list p;
 nodeptr join(nodeptr p, nodeptr a){
        p->next =a;
        return p;
    }
/*Function protoypes*/
nodeptr printGivenLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);
 
/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root)
{
  int h = height(root);
  int i;
  for(i=1; i<=h; i++)
  {
    list[i]=printGivenLevel(root, i);
}
}    
 
/* Print nodes at a given level */
nodeptr printGivenLevel(struct node* root, int level)
{nodeptr p,a;
  if(root == NULL)
    return;
  if(level == 1)
  {  return root;
  
  
        
  //  printf("%d ", root->data);
}
  else if (level > 1)
  {
    p=printGivenLevel(root->left, level-1);
   a= printGivenLevel(root->right, level-1);
   p=join(p,a);
   return p;
  }
}
 
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
     /* compute the height of each subtree */
     int lheight = height(node->left);
     int rheight = height(node->right);
 
     /* use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
    node->next= NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
     
     int h;
     nodeptr a;
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  h=height(root);
 p=(list)malloc(sizeof(list)*h);
  printf("Level Order traversal of binary tree is \n");
  printLevelOrder(root);
  printf("\n\n");
  for(i=1;i<=h;i++)
  { a=list[i];
  while(a!=NULL)
  {
        printf("%d",a->data);
        a=a->next;
    }
}
        
 
  getchar();
  return 0;
}

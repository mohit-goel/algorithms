//Huffman Coding 
#include<stdio.h>
#include<math.h>
#define n 9
typedef  struct mn *nodeptr;
nodeptr maketree(int number);
void build_min_heap(nodeptr rootnodes[]);
nodeptr extract_min(nodeptr arr[]);
void min_heapify(nodeptr arr[],int i);

void heap_insert(nodeptr arr[],nodeptr key);
void inorder(nodeptr p);


typedef struct mn
{
    int info;
    nodeptr father;
    nodeptr left;
    nodeptr right;
    int isleft;

}node;
char code[n][10];
int size = n;//size of heap
int  main()
{
    int i,count,k,j;

    count=size;
int freq[n]={15,6,7,12,25,4,6,1,15};
nodeptr position[n],p1,p2;
nodeptr rootnodes[n];
nodeptr p;


for(i=0;i<n;i++)
{
    p =maketree(freq[i]);
    position[i] =p;
    rootnodes[i]=p;
    }


build_min_heap(rootnodes);

while(size>0)
{
    p1 = extract_min(rootnodes);
    p2 = extract_min(rootnodes);


    p = maketree((p1->info + p2->info));
    p->right =p2;
    p->left =p1;
    p1->isleft=1;
    p2->isleft=0;
    p2->father =p;
    p1->father =p;
    heap_insert(rootnodes,p);
    printf("\n");
    for(k=0;k<size;k++)
    {
        printf("%d  ",rootnodes[k]->info);
    }

}
//printf("\ninorder traversal ");
//inorder(rootnodes[0]);
for(i=0;i<n;i++)
{j=9;
    p= position[i];
    while(p!=rootnodes[0])
    {
                  if(p->isleft)
                  code[i][j]='0';
                  else
                  code[i][j] ='1';
                  p=p->father;
                  j--;
                  }
                  }
    for(i=0;i<n;i++)
    {j=9;
                    printf("\n");
                    for(j=0;j<10;j++)
                    printf("%c",code[i][j]);
                    }



return 0;


}

nodeptr extract_min(nodeptr arr[])
{int k;
    nodeptr min;
    if(size <0)
    printf("underflow");

    min = arr[0];

    arr[0]= arr[size-1];
    size =size-1;

    min_heapify(arr,0);

    return min;
}
void heap_insert(nodeptr arr[],nodeptr key)
{
  int k;
    size =size+1;
    arr[size-1]=key;

    build_min_heap(arr);


    /*while((i>1) && ((arr[i/2]->info) > (arr[i]->info)))
    {
         tmp = arr[i];
    arr[i]=arr[i/2];
    arr[i/2] =tmp;
    i =(i/2);
    }*/
}






nodeptr maketree(int number)
{
        nodeptr q;
        q =(nodeptr)malloc(sizeof(nodeptr));
        q->info =number;
        q->left =NULL;
        q->right =NULL;
        q->father = NULL;
        q->isleft=0;
        return q;
}

void build_min_heap(nodeptr arr[])
{int i,k ;

    for(i=floor(size/2)-1;i>=0;i--)

         min_heapify(arr,i);

}

void min_heapify(nodeptr arr[],int i)
{int l,r,large,k;
nodeptr tmp;

l=2*i+1;
r=2*i+2;

if(l >size || r>size)
return;
if(l<size && (arr[l]->info < arr[i]->info))
large =l;
else large =i;

if(r<size && (arr[r]->info < arr[large]->info))
large = r;

if(large != i)
{
    tmp =arr[i];
    arr[i]=arr[large];
    arr[large] =tmp;
    min_heapify(arr,large);
    }


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





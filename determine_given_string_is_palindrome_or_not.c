#include<stdio.h>

#include<string.h>
typedef struct node
{
        char  data;
      struct  node * p;
}node;
main()
{
      char b[] = "reviver";
      char a[56];
      int i;
      int n,j;
      char ch;
      node *top,*tmp;
      top = NULL;
      j=0;
      n= strlen(b);

      for(i =0;i<n;i++)
      {
                      node *x;

        x = (node*)malloc(n*sizeof( node));

        x->data = *(b+i);
        x->p  = top;
        top = x;
        }

        while(top)
        {
              ch = top->data;
              tmp = top;
              top = top->p;
              free(tmp);
              a[j]= ch;
              j++;

              }

               if((strcmp(b,a)) == 0)
               printf("palindrome");
               else
               printf("not a palindrome");

               }




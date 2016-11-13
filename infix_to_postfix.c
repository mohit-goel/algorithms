#include<stdio.h>
#include<conio.h>
#include<string.h>
char stack[50];
int top=-1;
void in2post(char infix[]);
void push (char);
char pop();
main()
{
     char infix[25];
     printf("enter the infix expression\n");
     gets(infix);
     in2post(infix);
     getch();
}

void push( char symb)
{
     if(top>49)
     {
               printf("stack overflow");
               getch();
     }
     else
     {
         top++;
         stack[top]=symb;
     }
}
char pop()
{
     char item;
     if(top==-1)
     printf("stck empty");
     else
     {
         item=stack[top];
         top--;
     }
     return(item);
}

int preced(char ch)
{
    if(ch==94)
    return(3);
    else if(ch==47)
    return(2);
    else if(ch==42)
    return(2);
    else if(ch==43)
    return(1);
    else if(ch==45)
    return(1);
    else
    return(0);
}

void in2post(char infix[])
{
     int length;
     int index=0,pos=0;
     char symbol,temp;
     char postfix[40];
     length=strlen(infix);
     push('#');
     while(index<length)
     {
                        symbol=infix[index];
                        switch(symbol)
                        {
                        case '(':
                        push(symbol);
                        break;
                        case ')':
                        temp=pop();
                        while(temp!='(')
                        {
                        postfix[pos]=temp;
                        pos++;
                        temp=pop();
                        }
                        break;
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '^':
                        while(preced(stack[top])>=preced(symbol))
                        {
                        temp=pop();
                        postfix[pos++]=temp;
                        
                        }
                        push(symbol);
                        break;
                        default:
                        postfix[pos++]=symbol;
                        break;
                        }
                        index++;
     }
     while(top>0)
     {
     temp=pop();
     postfix[pos++]=temp;
     }
     postfix[pos++]='\0';
     printf("postfix expression\n");
     puts(postfix);
}

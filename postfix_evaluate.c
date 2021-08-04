#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *createnode(int item)
{
    NODE *p;
    p=(NODE*)malloc(sizeof(NODE));
    p->data=item;
    p->next=NULL;
    return p;
}

void push(NODE **top,int symb)
{
    NODE *p;
    p=createnode(symb);
    if(*top==NULL)
        *top=p;
    else
    {
        p->next=*top;
        *top=p;
    } 
    return;   
}

int pop(NODE **top)
{
    NODE *p;
    if(*top!=NULL)
    {
        p=*top;
        *top=(*top)->next;
    }
    return p->data;
}

int operation(int opnd1,int opnd2,char symb)
{
    switch(symb)
    {
        case '^' :
            return (int)pow(opnd1,opnd2);
            break;
        case '*' :
            return opnd1*opnd2;
            break;
        case '/' :
            return opnd1/opnd2;
            break;
        case '+' :
            return opnd1+opnd2;
            break;
        case '-' :
            return opnd1-opnd2;
            break;    
    }
}

int post_evaluate(char str[])
{
    int i,opnd1,opnd2,value,result;
    char symb;
    NODE *top=NULL;
    for(i=0;str[i]!='\0';i++)
    {
        symb=str[i];
        if(symb=='^' || symb=='*' || symb=='/' || symb=='+' || symb=='-')
        {
            opnd2=pop(&top);
            opnd1=pop(&top);
            value=operation(opnd1,opnd2,symb);
            push(&top,value);
        }
        else if(symb>='0' && symb<='9')
        {
            push(&top,symb-'0');
        }
    }
    return pop(&top);
}

void main()
{
    char str[50];
    int result,s;
    printf("\nEnter your postfix expression:");
    gets(str);
    result=post_evaluate(str);
    printf("\nResult of the Postfix Expresssion:%d",result);
}
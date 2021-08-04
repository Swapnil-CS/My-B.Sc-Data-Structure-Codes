#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stk[MAX],top=-1;
void push(int item)
{
	if(top==MAX-1)
	{
		printf("Stack Overflow");
	}
	else
	{
		top=top+1;
		stk[top]=item;
	}
}
int pop()
{
	int t=0;
	if(top==-1)
	{
		printf("Stack Underflow");
	}
	else
	{
		t=stk[top];
		top=top-1;
	}
	return t;
}
void display()
{
	int i;
	for(i=0;i<=top;i++)
	printf("\t%d",stk[i]);
}
main()
{
	int ch,item;
	while(1)
	{
		printf("\n1.PUSH \n2.POP \n3.Display \n4.Exit");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element to push:");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				if(top==-1)
				printf("Stack underflow");
				else
				printf("Popped value is %d",pop());
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}
}

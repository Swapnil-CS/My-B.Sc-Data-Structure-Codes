#include<stdio.h>
#include<stdlib.h>
#define N 5
int q[N],front=-1,rear=-1;
void qinsert(int item)
{
	if(rear==N-1)
	printf("\nQueue is full");
	else if(front==-1&&rear==-1)
	{
		front=rear=0;
		q[rear]=item;
	}
	else
	{
		rear=rear+1;
		q[rear]=item;
	}
}
int qdelete()
{
 	int t=0;
 	if((front==-1&&rear==-1)||(front>rear))
 	printf("\nQueue is empty");
 	else
 	{
 		t=q[front];
 		front=front+1;
	}
	return t;
}
void qdisplay()
{
	int i;
	for(i=front;i<=rear;i++)
	printf("\t%d",q[i]);
}
main()
{
	int ch,item;
	while(1)
	{
		printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the value to be inserted:");
				scanf("%d",&item);
				qinsert(item);
				break;
			case 2:
				if((front==-1&&rear==-1)||(front>rear))
				printf("\nQueue is empty");
				else
				printf("\nValue deleted is %d",qdelete());
				break;
			case 3:
				qdisplay();
				break;
			case 4:
				exit(0);
				break;
		}
	}
}























#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *getnode(int item)
{
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=item;
	p->prev=NULL;
	p->next=NULL;
	return p;
}
void insert_sorted_orderDLL(struct node **start,int item)
{
	struct node *temp,*p,*q;
	temp=getnode(item);
	if(*start==NULL)
	{
		*start=temp;
	}
	else
	{
		q=NULL;
		p=*start;
		while(item>p->data)
		{
			q=p;
			p=p->next;
			if(p==NULL)
			break;
		}
		if(q==NULL)
		{
			temp->next=*start;
			(*start)->prev=temp;
			*start=temp;
		}
		else if(q!=NULL && p==NULL)
		{
			q->next=temp;
			temp->prev=q;
		}
		else
		{
			q->next=temp;
			temp->prev=q;
			temp->next=p;
			p->prev=temp;
		}
	}
}
void printDLL(struct node *start)
{
	struct node *p;
	p=start;
	printf("\nElements of doubly linked list:\n");
	while(p!=NULL)
	{
		printf("\t%d",p->data);
		p=p->next;
	}
}
void midDLL(struct node *start)
{
	struct node *p,*q;
	int c=1;
	p=start;
	q=start;
	while(p->next!=NULL)
	{
		if(c%2==0)
		{
			q=q->next;
		}
		p=p->next;
		c=c+1;
	}
	printf("\nThe mid node value of the sorted doubly linked list is %d at position %d",q->data,(c+1)/2);
}
void main()
{
	struct node *start=NULL;
	int ch,item;
	while(1)
	{
		printf("\n1.Insertion\n2.Display\n3.Mid value of the sorted linked list\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter a node value you want to insert:");
				scanf("%d",&item);
				insert_sorted_orderDLL(&start,item);
				break;
			case 2:
				printDLL(start);
				break;
			case 3:
				midDLL(start);
				break;
			case 4:
				exit(0);
				break;
			default :
				printf("\nWrong Choice!");
		}
	}
	free(start);
}

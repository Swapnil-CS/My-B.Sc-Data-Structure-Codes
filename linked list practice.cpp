#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node 
{
	int info;
	struct node *next;
}node;
node *start;
void insert_beginning()
{
	node *p;
	int temp;
	p=(node*)malloc(sizeof(node));
	printf("\nEnter the value:");
	scanf("%d",&temp);
	if (start==NULL)
	{
		start=p;
		p->next=NULL;
		p->info=temp;
	}
	else
	{
		p->next=start;
		p->info=temp;
		start=p;
	}	
};
void insert_end()
{
	node *p,*q;
	int temp;
	p=(node*)malloc(sizeof(node));
	printf("\nEnter value to insert:");
	scanf("%d",&temp);
	if(start==NULL)
	{
		start=p;
		p->next=NULL;
		p->info=temp;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;
		p->next=NULL;
		p->info=temp;
	}
};
void insert_before_a_value()
{
	node *p,*q,*r;
	int key,temp;
	p=(node*)malloc(sizeof(node));
	printf("\nEnter value to insert:");
	scanf("%d",&temp);
	if(start==NULL)
	{
		start=p;
		p->next=NULL;
		p->info=temp;
	}
	else
	{
	printf("\nEnter value to search:");
	scanf("%d",&key);
	q=start;
		while(q!=NULL&&q->info!=key)
		{
			r=q;
			q=q->next;
		}
		if(q==NULL)
		{
			printf("\nNo such node into the list!!");
		}
		else if(q==start)
		{
			p->info=temp;
			start=p;
			p->next=q;
		}
		else
		{
		p->info=temp;
		r->next=p;
		p->next=q;
		}
	}
};
void insert_after_a_value()
{
	node *p,*q;
	int key,temp;
	p=(node*)malloc(sizeof(node));
	printf("\nEnter value to insert:");
	scanf("%d",&temp);
	if(start==NULL)
	{
		start=p;
		p->next=NULL;
		p->info=temp;
	}
	else
	{
		printf("\nEnter value to search:");
		scanf("%d",&key);
		q=start;
		while(q!=NULL&&q->info!=key)
		{
			q=q->next;
		}
		if(q==NULL)
		{
			printf("\nNo such node into the list!!");
		}
		else
		{
			p->next=q->next;
			p->info=temp;
			q->next=p;
		}
	}
};
void delete_the_first_node()

{
	node *p;
	
	
	if(start==NULL)
	{
		printf("No such node to delete underflow");
	}
	else
	{
		p=start;
		start=p->next;
		free(p);
		
	}
	
	
};
void delete_the_last_node()
{
	node *p,*q;
	
	if(start==NULL)
	{
		printf("No such node to delete underflow");
	}
	else
	{
		p=start;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=NULL;
		free(p);
			
	}
};
void delete_particular_node_from_list()
{
	node *p,*q;
	int key;
		
	if(start==NULL)
	{
		printf("No such node to delete underflow");
	}
	else
	{
		printf("Enter the value to search:");
		scanf("%d",&key);
		p=start;
		while(p!=NULL&&p->info!=key)
		{
			q=p;
			p=p->next;
		}
		if(p!=NULL)
		{
			q->next=p->next;
			free(p);
		}
		else
		{
			printf("\n No such node to delete");
		}
		
	}
}
void display()
{
	node *p;
	if(start==NULL)
		printf("\nList is empty!!");
	else
	{
		p=start;
		printf("\nstart->");
		while(p!=NULL)
		{
			printf("%d->",p->info);
			p=p->next;
		}
		printf("NULL");
	}
getch();
};
void reverse_traversal()
{
	
	node *p,*q,*r;
	if(start==NULL)
	{
		printf("List is empty");
	}
	else
	{
		p=start;
	q=p->next;
	p->next=NULL;
	while(q!=NULL)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
		
	}
	start=p;
	printf("\n->start");
	while(p!=NULL)
	{
		printf("%d->",p->info);
		p=p->next;
	}
	printf("NULL");
	}
	getch();
	
};
int main()
{
	int ch;
	while(1)
	{
	system("cls");
	printf("1 for insert beginning");
	printf("\n 2 for insert end");
	printf("\n 3 for insert before a value");
	printf("\n 4 for after a value");
	printf("\n 5 for forward traversal");
	printf("\n 6 for exit");
	printf("\n 7 for delete the first node");
	printf("\n 8 for delete the last node");
	printf("\n 9 for delete a particular node from list");
	printf("\n 10 for reverse traversal");
	printf("\n Enter your choice:");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_beginning();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				insert_before_a_value();
				break;
			case 4:
				insert_after_a_value();
				break;
			case 5:
				display();
				break;
			case 6:
				exit (0);
			case 7:
				 delete_the_first_node();
				 break;
			case 8: 
			     delete_the_last_node();
			     break;
			case 9:
				delete_particular_node_from_list();
				break;
			case 10:
				reverse_traversal();
				break;
			default:
				printf("\n Wrong choice!!");
				exit (1);
		}
	}
getch();
}

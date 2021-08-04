#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next,*prev;
	
};typedef struct node node;
node *start=NULL;
int temp;
node *CREATENODE();
void insert_beginning();
void insert_at_end();
void insert_after_particular_node();
void insert_before_a_particular_node();
void traversal();
void reverse_traversal();
void delete_the_first_node();
void delete_the_last_node();
void delete_a_particular_node();
node *CREATENODE()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->next=NULL;
	printf("\n Enter the information:");
	scanf("%d",&temp);
	return (p);
}
void insert_beginning()
{
     node *p;
     p=CREATENODE();
	if(start==NULL)
	{
		printf("\n list is empty");
		start=p;
		p->next=NULL;
		p->prev=NULL;
		p->info=temp;
	}
	else
	{
		p->next=start;
		start->prev=p;
		start=p;
		p->info=temp;
	}
}
void insert_at_end()
{
	node *p,*q;
	p=CREATENODE();
	if(start==NULL)
	{
		printf("\n list is empty");
        start=p;
		p->next=NULL;
		p->prev=NULL;
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
		p->prev=q;
		p->next=NULL;
		
	}
}
void insert_after_particular_node()
{
	node *p,*q;
	p=CREATENODE();
	if(start==NULL)
	{
		printf("\n list is empty");
		start=p;
		p->next=NULL;
		p->prev=NULL;
		p->info=temp;
	}
	else
	{
		int key;
		printf("Enter the value after which the node is inserted:");
		scanf("%d",&key);
		q=start;
		while(q!=NULL&&q->info!=key)
		{
			q=q->next;
			
		}
		if(q==NULL)
		{
			printf("No such node found in the list");
		}
		else
		{
			p->next=q->next;
			(q->next)->prev=p;
			p->prev=q;
			q->next=p;
			p->info=temp;
			
		}
	}
}
void insert_before_a_particular_node()
{
	node *p,*q,*r;
	p=CREATENODE();
	if(start==NULL)
	{
		printf("\n list is empty");
		start=p;
		p->next=NULL;
		p->prev=NULL;
		p->info=temp;
	}
	else
	{
		int key;
		printf("Enter the value before which the node is inserted:");
		scanf("%d",&key);
		q=start;
		while(q!=NULL&&q->info!=key)
		{
			
			q=q->next;
		}
		if(q==NULL)
		{
			printf("No such node found in the list");
			
		}
		else
		{
			p->prev=r;
			r->next=p;
			q->prev=p;
			p->next=q;
			p->info=temp;
		}
		
	}
}
void traversal()
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
}
void reverse_traversal()
{
	node *q;
	if(start==NULL)
	printf("\n list is empty");
	else
	{
		q=start;
		while(q!=NULL)
		{
			q=q->next;
		}
		
		while(q!=start)
		{
			printf("%d->",q->info);
			q=q->prev;
		}
		
	}
}
void delete_the_first_node()
{
	node *q;
	if(start==NULL)
	printf("No such node to delete underflow");
	else
	{
		q=start;
	    (q->next)->prev=NULL;
		start=q->next;
		free(q);
    }
}
void delete_the_last_node()
{
	node *p,*q;
	if(start==NULL)
	printf("No such node to delete underflow");
	else
	{
		q=start;
		while(q->next!=NULL)
	    {
	    	
	    	q=q->next;
		}
		q->prev=p;
		p->next=NULL;
		free(q);
	}
}
void delete_a_particular_node()
{
	node *q;
	if(start==NULL)
	printf("No such node to delete underflow");
	else
	{
		int key;
		printf("Enter the node which you want  to delete:");
		scanf("%d",&key);
		q=start;
		while(q!=NULL&&q->info!=key)
		{
			q=q->next;
		}
		(q->prev)->next=q->next;
		(q->next)->prev=q->prev;
		free(q);
	}
}
int main()
{
	int ch,n;
	node *p,*q;
	
	printf(" Enter number of nodes you want to add:");
	scanf("%d",&n);
	while(n!=0)
	{
		p=(node*)malloc(sizeof(node));
		p->next=NULL;
		printf("enter node");
		scanf("%d",&p->info);
		if(start==NULL)
		{
			start=p;
		}
		else
		{
			q=start;
			while(q->next!=NULL)
			{
				q=q->next;
				
			}
			q->next=p;
		}
		n=n-1;
	}
	while(1)
	{
	printf("\n 1 for insert beginning");
	printf("\n 2 for insert end");
	printf("\n 3 for insert before a value");
	printf("\n 4 for after a value");
	printf("\n 5 for forward traversal");
	printf("\n 6 for reverse traversal");
	printf("\n 7 for delete the first node");
	printf("\n 8 for delete the last node");
	printf("\n 9 for delete a particular node");
	printf("\n 10 for exit");
	printf("\n Enter your choice:");
	scanf("%d",&ch);
	
	
		switch(ch)
		{
			case 1:
			insert_beginning();
				break;
			case 2:
				insert_at_end();
				break;
			case 3:
				insert_before_a_particular_node();
				break;
			case 4:
				insert_after_particular_node();
				break;
			case 5: traversal();
			    break;
			case 6: reverse_traversal();
			    break;
			case 7: delete_the_first_node();
			    break;
			case 8: delete_the_last_node();
			    break;
			case 9: delete_a_particular_node();
			    break;
			case 10: exit(0);
			default:
				printf("\n Wrong choice!!");
				
		}
	}
getch();
}

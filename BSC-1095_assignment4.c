#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}NODE;

NODE *getnode(int item)
{
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	p->data=item;
	p->prev=NULL;
	p->next=NULL;
	return p;
}
void insert_at_beg_circularDLL(NODE **start,int item)
{
	NODE *temp;
	temp=getnode(item);    
	if(*start==NULL)			
	{
		*start=temp;
		(*start)->next=*start;			
		printf("\nNew node value %d inserted at the beginning of the linked list",item);
	}
	else if((*start)->next==*start)	
	{
		temp->next=*start;
		(*start)->prev=temp;
		temp->prev=*start;
		(*start)->next=temp;
		*start=temp;
		printf("\nNew node value %d inserted at the beginning of the linked list",item);
	}
	else
	{
		temp->next=*start;
		temp->prev=(*start)->prev;
		((*start)->prev)->next=temp;
		(*start)->prev=temp;
		*start=temp;
		printf("\nNew node value %d inserted at the beginning of the linked list",item);
	}
}
void insert_at_end_circularDLL(NODE **start,int item)
{
	NODE *temp,*p;
	temp=getnode(item);    
	if(*start==NULL)	
	{
		*start=temp;
		(*start)->next=*start;
		printf("\nThe linked list is empty so new node value %d will be inserted at start",item);
	}
	else if((*start)->next==*start)
	{
		temp->prev=*start;
		(*start)->next=temp;
		temp->next=*start;
		(*start)->prev=temp;
		printf("\nNew node value %d inserted at the end of the linked list",item);
	}
	else
	{
		p=*start;
		while(p->next!=*start)
		{
			p=p->next;
		}
		temp->prev=p;
		temp->next=p->next;
		(p->next)->prev=temp;
		p->next=temp;
		printf("\nNew node value %d inserted at the end of the linked list",item);
	}
}
void delete_from_beg_circularDLL(NODE **start)
{
	NODE *p;
	if(*start==NULL)		
	{
		printf("\nThe linked list is empty so, Deletion is not possible...!");
	}
	else		
	{
		p=*start;
		if(p->next==*start)		
		{
			*start=NULL;
			printf("\nDeleted node value from the beginning is %d",p->data);
		}
		else
		{
			(p->prev)->next=p->next;
			(p->next)->prev=p->prev;
			*start=(*start)->next;		
			printf("\nDeleted node value from the beginning is %d",p->data);
		}
		free(p);
		p=NULL;		
	}	
}
void delete_from_end_circularDLL(NODE **start)
{
	NODE *p;
	if(*start==NULL)		
	{
		printf("\nThe linked list is empty so, Deletion is not possible...!");
	}
	else		
	{
		p=*start;
		while(p->next!=*start) 	
		{
			p=p->next;
		}
		if(p==*start)		
		{
			*start=NULL;
			printf("\nDeleted node value from the end is %d",p->data);
		}
		else			
		{
			(p->next)->prev=p->prev;
			(p->prev)->next=p->next;
			printf("\nDeleted node value from the end is %d",p->data);
		}
		free(p);
		p=NULL;	
	}
}
void print_circular_DLL(NODE *start)
{
	NODE *p;
	if(start==NULL)
	{
		printf("\nDoubly Linked List is empty so, cannot be printed...!");
	}
	else
	{
		printf("\nElements of the Circular Doubly Linked List in forward direction:\n");
		p=start;
		while(p->next!=start)
		{
			printf("\t%d",p->data);
			p=p->next;
		}
		printf("\t%d",p->data);
		printf("\nElements of the Circular Doubly Linked List in backward direction:\n");
		while(p!=start)
		{
			printf("\t%d",p->data);
			p=p->prev;
		}
		printf("\t%d",p->data);
	}	
}
void main()
{
	NODE *start=NULL;
	int ch,item;
	do
	{
		printf("\n1.Insert at beginning of Circular DLL\n2.Insert at end of Circular DLL\n3.Delete from beginning of Circular DLL\n4.Delete from end of Circular DLL\n5.Display Circular DLL\n6.Exit from the System");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the node value to be inserted:");
				scanf("%d",&item);
				insert_at_beg_circularDLL(&start,item);
				break;
			case 2:
				printf("\nEnter the node value to be inserted:");
				scanf("%d",&item);
				insert_at_end_circularDLL(&start,item);
				break;
			case 3:
				delete_from_beg_circularDLL(&start);
				break;
			case 4:
				delete_from_end_circularDLL(&start);
				break;
			case 5:
				print_circular_DLL(start);
				break;
			case 6:
				printf("\nExit from the System....");
				break;
			default :
				printf("\nInvalid Choice...!");	
		}
	}while(ch!=6);
	free(start);
}

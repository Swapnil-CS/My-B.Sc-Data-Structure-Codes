#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}NODE;

NODE *start=NULL;

NODE *getnode(int item)
{
	struct node *p;
	p=(NODE*)malloc(sizeof(NODE));
	p->data=item;
	p->prev=NULL;
	p->next=NULL;
	return p;
}
void insert_at_any_pos_DLL(int item,int pos)
{
	NODE *p,*temp;
	int i;
	temp=getnode(item);
	if(start==NULL)
	{
		printf("\nDoubly Linked list is empty so new node value %d will be inserted at beginning",item);
		start=temp;
	}
	else
	{
		if(pos==1)
		{
			temp->next=start;
			start->prev=temp;
			start=temp;
			printf("\nNew node value %d is inserted at position %d",item,pos);
		}
		else
		{
			p=start;
			for(i=1;i<pos-1;i++)
			{
				if(p!=NULL)
				p=p->next;
				
				else
				break;
			}
			if(p==NULL)
			{
				printf("\nInvalid position given...!");
			}
			else if(p->next==NULL)
			{
				p->next=temp;
				temp->prev=p;
				printf("\nNew node value %d is inserted at position %d",item,pos);
			}
			else
			{
				temp->next=p->next;
				temp->prev=p;
				(p->next)->prev=temp;
				p->next=temp;
				printf("\nNew node value %d is inserted at position %d",item,pos);
			}
		}
	}
}
void linear_search_DLL(int item)
{
	NODE *p;
	int c=1,f=0;
	if(start==NULL)
	{
		printf("\nThe linked list empty so value cannot be searched...!");
	}
	else
	{
		p=start;
		while(p!=NULL)
		{
			if(p->data==item)
			{
				f=1;
				printf("\nThe node value %d is found at the position %d",item,c);
			}
			c=c+1;
			p=p->next;
		}
		if(f==0)
		{
			printf("\nThe node value %d is not found...!",item);
		}
	}
}
void print_DLL()
{
	NODE *p;
	if(start==NULL)
	{
		printf("\nDoubly Linked List is empty so, cannot be printed...!");
	}
	else
	{
		printf("\nElements of the Doubly Linked List:\n");
		p=start;
		while(p!=NULL)
		{
			printf("\t%d",p->data);
			p=p->next;
		}
	}
}
void main()
{
	int ch,item,pos;
	do
	{
		printf("\n1.Insert at any position of Doubly Linked List\n2.Linear Search of an value in Doubly Linked List\n3.Display Doubly Linked List\n4.Exit from the System");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the node value to be inserted:");
				scanf("%d",&item);
				printf("\nEnter the position where you want to insert the value:");
				scanf("%d",&pos);
				insert_at_any_pos_DLL(item,pos);
				break;
			case 2:
				printf("\nEnter the the node value which you want to search:");
				scanf("%d",&item);
				linear_search_DLL(item);
				break;
			case 3:
				print_DLL();
				break;
			case 4:
				printf("\nExit from the System....");
				break;
			default :
				printf("\nInvalid Choice...!");
		}	
	}while(ch!=4);
}

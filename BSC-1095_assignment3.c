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
void insert_at_any_pos_DLL(NODE **start,int item)
{
	NODE *p,*temp;
	int i,pos;
	temp=getnode(item);
	if(*start==NULL)
	{
		printf("\nDoubly Linked list is empty so new node value %d will be inserted at beginning",item);
		*start=temp;
	}
	else
	{
		printf("\nEnter the position where you want to insert the value:");
		scanf("%d",&pos);
		if(pos>0)
		{
			if(pos==1)
			{
				temp->next=*start;
				(*start)->prev=temp;
				*start=temp;
				printf("\nNew node value %d is inserted at position %d",item,pos);
			}
			else
			{
				p=*start;
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
		else
		{
			printf("\nInvalid position given...!");
		}
	}
}
void linear_search_DLL(NODE *start,int item)
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
void delete_at_begDLL(NODE **start)
{
	NODE *p;
	if(*start==NULL)		
	{
		printf("\nThe linked list is empty so, Deletion is not possible...!");
	}
	else		
	{
		p=*start;
		if(p->next==NULL)		
		{
			*start=NULL;
			printf("\nDeleted node value from the beginning is %d",p->data);
		}
		else
		{
			*start=(*start)->next;
			(*start)->prev=NULL;		
			printf("\nDeleted node value from the beginning is %d",p->data);
		}
		free(p);
		p=NULL;		
	}	
}
void delete_at_endDLL(NODE **start)
{
	NODE *p;
	if(*start==NULL)		
	{
		printf("\nThe linked list is empty so, Deletion is not possible...!");
	}
	else		
	{
		p=*start;
		while(p->next!=NULL) 	
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
			(p->prev)->next=NULL;
			printf("\nDeleted node value from the end is %d",p->data);
		}
		free(p);
		p=NULL;	
	}
}
void delete_at_any_posDLL(NODE **start)
{
	NODE *p;
	int i,pos;
	if(*start==NULL)
	{
		printf("\nThe linked list is empty so, Deletion is not possible...!");
	}
	else
	{
		printf("\nEnter the position where you want to delete the value:");
		scanf("%d",&pos);
		if(pos>0)
		{
			if(pos==1)
			{
				p=*start;
				if(p->next==NULL)		
				{
					*start=NULL;
					printf("\nDeleted node value is %d from the position is %d",p->data,pos);
				}
				else
				{
					*start=(*start)->next;
					(*start)->prev=NULL;		
					printf("\nDeleted node value is %d from the position is %d",p->data,pos);
				}
			}
			else
			{
				p=*start;
				for(i=1;i<pos;i++)
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
					(p->prev)->next=NULL;
					printf("\nDeleted node value is %d from the position is %d",p->data,pos);
				}
				else
				{
					(p->prev)->next=p->next;
					(p->next)->prev=p->prev;
					printf("\nDeleted node value is %d from the position is %d",p->data,pos);
				}
			}
			free(p);
			p=NULL;
		}
		else
		{
			printf("\nInvalid position given...!");
		}
	}
}
void print_DLL(NODE *start)
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
	NODE *start=NULL;
	int ch,item;
	do
	{
		printf("\n1.Insert at any position of DLL\n2.Linear Search of an value in DLL\n3.Delete from beginning of DLL\n4.Delete from end of DLL\n5.Delete from any position of DLL\n6.Display DLL\n7.Exit from the System");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the node value to be inserted:");
				scanf("%d",&item);
				insert_at_any_pos_DLL(&start,item);
				break;
			case 2:
				printf("\nEnter the the node value which you want to search:");
				scanf("%d",&item);
				linear_search_DLL(start,item);
				break;
			case 3:
				delete_at_begDLL(&start);
				break;
			case 4:
				delete_at_endDLL(&start);
				break;
			case 5:
				delete_at_any_posDLL(&start);
				break;
			case 6:
				print_DLL(start);
				break;
			case 7:
				printf("\nExit from the System....");
				break;
			default :
				printf("\nInvalid Choice...!");
		}	
	}while(ch!=7);
	free(start);
}

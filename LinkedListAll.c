#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}NODE;
NODE *start=NULL;
void insert_at_beg()
{
	NODE *p;
	int t;
	printf("\nEnter a node value which you want to insert at the beginning of the linked list:");
	scanf("%d",&t);
	p=(NODE*)malloc(sizeof(NODE));
	p->data=t;
	if(start==NULL)
	{
		p->next=NULL;
		start=p;
	}
	else
	{
		p->next=start;
		start=p;
	}
}
void insert_at_end()
{
    int t;
    NODE *p,*s;
    printf("\nEnter a node value which you want to insert at the end of the linked list:");
    scanf("%d",&t);
    p=(NODE*)malloc(sizeof(NODE));
    p->data=t;
    p->next=NULL;
    if(start==NULL)
    {
    	start=p;
    }
   else
   {
        s=start;
        while(s->next!=NULL)
        {
        	s=s->next;
        }
        s->next=p;
   }
}
void insert_before_a_node()
{
	NODE *p,*s,*r;
	int t,key;
	printf("\nEnter the node value which you want to insert:");
	scanf("%d",&t);
	p=(NODE*)malloc(sizeof(NODE));
	p->data=t;
	if(start==NULL)
	{
		printf("\nThe linked list is empty so, new node will be inserted at start");
		start=p;
		p->next=NULL;
	}
	else
	{
		printf("\nEnter the node value before which you want to insert the new node:");
		scanf("%d",&key);
		s=start;
		while(s!=NULL && s->data!=key)
		{
			r=s;
			s=s->next;
		}
		if(s==NULL)
		{
			printf("\nNo such node value present in the linked list so, Insertion is not possible...!");
			free(p);
		}
		else if(s==start)
		{
			p->next=s;
			start=p;
		}
		else
		{
			r->next=p;
			p->next=s;
		}
	}
}
void insert_after_a_node()
{
	NODE *p,*s;
	int t,key;
	printf("\nEnter the node value which you want to insert:");
	scanf("%d",&t);
	p=(NODE*)malloc(sizeof(NODE));
	p->data=t;
	if(start==NULL)
	{
		printf("\nThe linked list is empty so, new node will be inserted at start");
		start=p;
		p->next=NULL;
	}
	else
	{
		printf("\nEnter the node value after which you want to insert the new node:");
		scanf("%d",&key);
		s=start;
		while(s!=NULL && s->data!=key)
		{
			s=s->next;
		}
		if(s==NULL)
		{
			printf("\nNo such node value present in the linked list so, Insertion is not possible...! ");
			free(p);
		}
		else
		{
			p->next=s->next;
			s->next=p;
		}
	}
}
void delete_from_beg()
{
	NODE *p;
	if(start==NULL)
	{
		printf("\nThe linked list is empty so, Deletion is not possible...!");
	}
	else
	{
		p=start;
		start=p->next;
		printf("\nDeleted node value is %d",p->data);
		free(p);
		
	}
}
void delete_from_end()
{
	NODE *p,*s;
	if(start==NULL)
	{
		printf("\nThe linked list is empty so, Deletion is not possible...!");
	}
	else
	{
		p=start;
		while(p->next!=NULL)
		{
			s=p;
			p=p->next;
		}
		if(p==start)
		{
			start=NULL;
			printf("\nDeleted node value is %d",p->data);
			free(p);
		}
		else
		{
			s->next=NULL;
			printf("\nDeleted node value is %d",p->data);
			free(p);
		}
	}
}
void delete_particular_node()
{
	NODE *p,*s;
	int key;
	if(start==NULL)
	{
		printf("\nThe linked list is empty so, Deletion is not possible...!");
	}
	else
	{
		printf("\nEnter the node value which you want to delete:");
		scanf("%d",&key);
		p=start;
		while(p!=NULL && p->data!=key)
		{
			s=p;
			p=p->next;
		}
		if(p==NULL)
		{
			printf("\nNo such node value present in the linked list so, Deletion is not possible...!");	
		}
		else if(p==start)
		{
			start=p->next;
			printf("\n Deleted node value is %d",p->data);
			free(p);
		}
		else
		{
			s->next=p->next;
			printf("\n Deleted node value is %d",p->data);
			free(p);
		}
	}
	
}
void forward_traverse()
{
	NODE *p;
	if(start==NULL)
	{
		printf("\nLinked list is empty so, Traversal is not possible...!");
	}
	else
	{
		p=start;
		printf("\nSTART-->");
		while(p!=NULL)
		{
			printf("%d-->",p->data);
			p=p->next;
		}
		printf("NULL");
	}
}
void reverse_traverse()
{
	NODE *p,*s,*r;
	if(start==NULL)
	{
		printf("\nLinked list is empty so, Traversal is not possible...!");
	}
	else
	{
		p=start;
		s=p->next;
		p->next=NULL;
		while(s!=NULL)
		{
			r=s->next;
			s->next=p;
			p=s;
			s=r;
		}
		start=p;
		printf("\nSTART-->");
		while(p!=NULL)
		{
			printf("%d-->",p->data);
			p=p->next;
		}
		printf("NULL");
    }
}
void main()
{
	int ch;
	char sch;
	while(1)
	{
		printf("\n\n1.INSERTION\n2.DELETION\n3.TRAVERSAL\n4.EXIT from the System");
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				do
				{
					printf("\n\nWhich Insertion method do you want to perform?");
					printf("\n\na.Insertion at beginning\nb.Insertion at end\nc.Insertion before particular node\nd.Insertion after a particular node\ne.Quit Insertion and back to Main Menu");
					printf("\n\nEnter your choice:");
					sch=getche();
					sch=tolower(sch);
					switch(sch)
					{
						case 'a':
							insert_at_beg();
							break;
						case 'b':
							insert_at_end();
							break;
						case 'c':
							insert_before_a_node();
							break;
						case 'd':
							insert_after_a_node();
							break;
						case 'e':
							break;
						default :
							printf("\nWrong Choice...!");	
					}
				}while(sch!='e');
				break;
			case 2:
				do
				{
					printf("\n\nWhich Deletion method do you want to perform?");
					printf("\n\na.Deletion from beginning\nb.Deletion from end\nc.Deletion of a particular node\nd.Quit Deletion and back to Main Menu");
					printf("\n\nEnter your choice:");
					sch=getche();
					sch=tolower(sch);
					switch(sch)
					{
						case 'a':
							delete_from_beg();
							break;
						case 'b':
							delete_from_end();
							break;
						case 'c':
							delete_particular_node();
							break;
						case 'd':
							break;
						default :
							printf("\nWrong Choice...!");	
					}
				}while(sch!='d');
				break;
			case 3:
				do
				{
					printf("\n\nWhich Traversal method do you want to perform?");
					printf("\n\na.Forward Traversal\nb.Reverse Traversal\nc.Quit Traversal and back to Main Menu");
					printf("\n\nEnter your choice:");
					sch=getche();
					sch=tolower(sch);
					switch(sch)
					{
						case 'a':
							forward_traverse();
							break;
						case 'b':
							reverse_traverse();
							break;
						case 'c':
							break;
						default :
							printf("\nWrong Choice...!");	
					}
				}while(sch!='c');
				break;
			case 4:
				printf("\nExit from the system....TATA BYE BYE:-)");
				exit(0);
				break;
			default :
				printf("\nWrong Choice...!");
		}
	}
}

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *prev;
	struct node *next;
	int data;
}NODE;

NODE *start=NULL; //initialising start

NODE *createnode(int item)    //creating a node
{
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE)); //allocating memory for the node
	p->data=item;                  //storing the value in the node
	p->prev=NULL;					//initialising prev part as NULL
	p->next=NULL;					//initialising next part as NULL
	return p;						//returning the node p
}
void insert_at_beg()			//fn for insert at beginning
{
	NODE *p;
	int item;
	printf("\nEnter a node value which you want to insert at the beginning of the linked list:");
	scanf("%d",&item);
	p=createnode(item);     //new node
	if(start==NULL)			//when linked list is empty
	{
		start=p;			
		printf("\nNew node value %d inserted at the beginning of the linked list",item);
	}
	else
	{
		p->next=start;
		start->prev=p;
		start=p;
		printf("\nNew node value %d inserted at the beginning of the linked list",item);
	}
}
void insert_at_end()		//fn for insert at end
{
	NODE *p,*q;
	int item;
	printf("\nEnter a node value which you want to insert at the end of the linked list:");
	scanf("%d",&item);
	p=createnode(item);
	if(start==NULL)			//when list is empty
	{
		start=p;
		printf("\nThe linked list is empty so new node value %d will be inserted at start",item);
	}
	else					//when list is not empty
	{
		q=start;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		q->next=p;
		p->prev=q;
		printf("\nNew node value %d inserted at the end of the linked list",item);
	}
}
void insert_before_a_node()			//fn for insert before particular node
{
	NODE *p,*q;
	int item,key;
	printf("\nEnter the node value which you want to insert:");
	scanf("%d",&item);
	p=createnode(item);
	if(start==NULL)			//when list is empty
	{
		printf("\nThe linked list is empty so, new node value %d will be inserted at start",item);
		start=p;
	}
	else					//when list is not empty
	{
		printf("\nEnter the node value before which you want to insert the new node:");
		scanf("%d",&key);
		q=start;
		while(q!=NULL && q->data!=key)		//checking the key value until q becomes NULL
		{
			q=q->next;
		}
		if(q==NULL)			//when key is not in list
		{
			printf("\nNo such node value present in the linked list so, Insertion is not possible...!");
		}
		else if(q==start)   //when the key value is at start or the list has only one node
		{
			p->next=start;
			start->prev=p;
			start=p;
			printf("\nNew node value %d inserted before the node value %d",item,key);
		}
		else			//when key value is at any node other than start
		{
			p->prev=q->prev;
			p->next=q;
			(q->prev)->next=p;
			q->prev=p;
			printf("\nNew node value %d inserted before the node value %d",item,key);
		}
	}
}
void insert_after_a_node()			//fn for insert after particular node
{
	NODE *p,*q;
	int item,key;
	printf("\nEnter the node value which you want to insert:");
	scanf("%d",&item);
	p=createnode(item);
	if(start==NULL)			//when list is empty
	{
		printf("\nThe linked list is empty so, new node value %d will be inserted at start",item);
		start=p;
	}
	else				//when list is not empty
	{
		printf("\nEnter the node value after which you want to insert the new node:");
		scanf("%d",&key);
		q=start;
		while(q!=NULL && q->data!=key)		//checking the key value until q becomes NULL
		{
			q=q->next;
		}
		if(q==NULL)			//when key is not in the list
		{
			printf("\nNo such node value present in the linked list so, Insertion is not possible...!");
		}
		else if(q->next==NULL)		//when key is at last node
		{
			p->prev=q;
			p->next=q->next;
			q->next=p;
			printf("\nNew node value %d inserted after the node value %d",item,key);
		}
		else			//when key is at any node other than last node
		{
			p->prev=q;
			p->next=q->next;
			(q->next)->prev=p;
			q->next=p;
			printf("\nNew node value %d inserted after the node value %d",item,key);
		}
	}
}
void delete_from_beg()			//fn for deleting from beginning
{
	NODE *p;
	if(start==NULL)		//when list is empty
	{
		printf("\nThe linked list is empty so, Deletion is not possible...!");
	}
	else		//when list is not empty
	{
		p=start;
		if(p->next==NULL)		//when list has only one node
		{
			start=NULL;
			printf("\nDeleted node value from the beginning is %d",p->data);
		}
		else			//when list has more than one node
		{
			(p->next)->prev=NULL;
			start=p->next;
			printf("\nDeleted node value from the beginning is %d",p->data);
		}
		free(p);		//deallocating the deleted node
	}
}
void delete_from_end()			//fn for deleting from end
{
	NODE *p;
	if(start==NULL)		//when list is empty
	{
		printf("\nThe linked list is empty so, Deletion is not possible...!");
	}
	else		//when list is not empty
	{
		p=start;
		while(p->next!=NULL) 		//checking p until it becomes NULL i.e to the last node
		{
			p=p->next;
		}
		if(p==start)		//when list has only one node
		{
			start=NULL;
			printf("\nDeleted node value from the end is %d",p->data);
		}
		else			//when list has more than one node
		{
			(p->prev)->next=NULL;
			printf("\nDeleted node value from the end is %d",p->data);
		}
		free(p);		//deallocating the deleted node
	}
}
void delete_particular_node()		//fn for deleting particular node
{
	NODE *p,*q;
	int key;
	if(start==NULL)			//when list is empty
	{
		printf("\nThe linked list is empty so, Deletion is not possible...!");
	}
	else			//when list is not empty
	{
		printf("\nEnter the node value which you want to delete:");
		scanf("%d",&key);
		p=start;
		while(p!=NULL && p->data!=key)		//checking the key value until p becomes NULL
		{
			p=p->next;
		}
		if(p==NULL)			//when key value is not in the list
		{
			printf("\nNo such node value present in the linked list so, Deletion is not possible...!");	
		}
		else if(p==start)	//when key value is at start
		{
			if(p->next==NULL)	//when key value is at start and list has only one node
			{
				start=NULL;
				printf("\n Deleted node value is %d",p->data);
			}
			else		//when key value is at start and list has more than one node
			{
				(p->next)->prev=NULL;
				start=p->next;
				printf("\n Deleted node value is %d",p->data);
			}
		}
		else if(p->next==NULL)		//when key is at last node
		{
			(p->prev)->next=NULL;
			printf("\n Deleted node value is %d",p->data);
		}
		else			//when key at any node other than start node and last node
		{
			(p->prev)->next=p->next;
			(p->next)->prev=p->prev;
			printf("\n Deleted node value is %d",p->data);
		}
		free(p);		//deallocating the deleted node
	}
}
void forward_traverse()			//fn for printing the list towards right
{
	NODE *p;
	if(start==NULL)		//when list is empty
	{
		printf("\nLinked list is empty so, Traversal is not possible...!");
	}
	else			//when list is not empty
	{
		p=start;
		printf("\nSTART-->");
		while(p!=NULL)		//checking p until it becomes NULL
		{
			printf("|%d|-->",p->data);	//printing values of nodes
			p=p->next;				//shifting p towards right
		}
		printf("NULL");
	}
}
void reverse_traverse()			//fn for printing the list towards left
{
	NODE *p;
	if(start==NULL)		//when list is empty
	{
		printf("\nLinked list is empty so, Traversal is not possible...!");
	}
	else			//when list is not empty
	{
		p=start;
		while(p->next!=NULL)	//checking p until it becomes NULL
		{
			p=p->next;			//Traversing towards right to know the address of last node
		}
		printf("\nSTART-->");
		while(p!=NULL)		//checking p until it becomes NULL
		{
			printf("|%d|-->",p->data);		//printing values of the nodes
			p=p->prev;			//shifting p towards left 
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
					sch=getche();			//taking character input
					sch=tolower(sch);		//making the input in lower case
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
	free(start);			//deallocating start node i.e the whole list also
}

#include <stdio.h>
#include <process.h>
#include<stdlib.h>

// define the structure of node 
// want to rname struct NODE to node
struct NODE
{
	int info;
	struct NODE *next;
};typedef struct NODE node;

// function declatation / prototype

node *CREATENODE(); // create node 
void INSERTAFTERA(int); //insert after a node 
int DELETENODE(int); // perticular elemenet  will be deleted 
void TRAVERSAL();  //  list will be traversed 

node *start; // be the global variable 
// ******function defibations*********

node *CREATENODE()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->next=NULL; // NULL pointer initialization
	printf ("\n Enter the information :");
	scanf("%d", &p->info);
	return(p);
}

void INSERTAFTERA(int key)
{
	node *p,*q,*r;
	p=CREATENODE(); // new node
	
	if (start== NULL)
	{
		printf ("list is empty :");
		start =p;
	}
	else
	{
		q=start;
		while (q!=NULL && q->info!=key)
		{
			r=q;
			q=q->next;
		}
		if (q!=NULL)
		{
			p->next=q->next;
			q->next=p;
		}
		else
		{
			printf("No such node is found :");
			printf ("Insert at the end :");
			r->next=p;
			p->next=NULL;
		}
	}
// delete the perticular node 

int DELETENODE(int key)
{
	node *p,*q;
	int temp;
	if (start==NULL)
	{
		printf("No such node to delete underflow:");
		exit(1);
		
	}
	else
	{
		p=start;
		while(p!=NULL && p->info!=key)
		{
			q=p;
			p=p->next;
		}
		if (p!=NULL) //  found the node 
		{
			q->next=p->next;
			temp=p->info;
		}
		else if (p==start)
		{
			start=p->next;
		}
		else
		{
			printf("\n Element not found ");

		}
		free(p);
	}
	return(temp);
}

void TRAVERSAL()
{
	node *p;
	p=start;
	printf ("\n The element into the list ....\n");
	while(p!=NULL)
	{
		printf("%d",p->info);
		p=p->next;
	}
}

int main()
{
	int n,k,d;
	node *p,*q;
	start=NULL;
	printf("\n Want to create a list :");
	printf("how many node :");
	scanf("%d", &n);
	while(n!=0)
	{
		p=CREATENODE();
		if (start==NULL)
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
		n--;
	}
	TRAVERSAL();
	printf ("\n Enter the node info after which element will be inserted :");
	scanf("%d",&k);
	INSERTAFTERA(k);
	TRAVERSAL();
	printf("\n Enter the information to delete :");
	scanf("%d",&d);
	printf ("%d is the deleted node ",DELETENODE(d));
	TRAVERSAL();	
	return(0);
}

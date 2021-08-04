//union of two sorted linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void create_list(struct node *head,int n)
{
	   int i;
	   struct node *ptr,*s;
        
	   for(i=1;i<n;i++)
	   {
	   	    s=head;
	       ptr=(struct node*)malloc(sizeof(struct node));
		   printf("Enter data:");
		   scanf("%d",&ptr->data);
		   ptr->next=NULL;
		   while(s->next!=NULL)
		     s=s->next;
		   s->next=ptr;	
	   }	
}
void display(struct node *head)
{
	while(head!=NULL)
	{
		printf("\t%d",head->data);
		head=head->next;
	}
}
void union1(struct node *head1,struct node *head2)
{
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data<head2->data)
		{
			printf("\t%d",head1->data);
			head1=head1->next;
		}
		else if(head2->data<head1->data)
		{
			printf("\t%d",head2->data);
			head2=head2->next;
		}
		else
		{
			printf("\t%d",head1->data);
			head1=head1->next;
			head2=head2->next;
		}
	}
	while(head1!=NULL)
	{
		printf("\t%d",head1->data);
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		printf("\t%d",head2->data);
		head2=head2->next;
	}
}
void intersection(struct node *head1,struct node *head2)
{
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data<head2->data)
		{
			head1=head1->next;
		}
		else if(head2->data<head1->data)
		{
			head2=head2->next;
		}
		else
		{
			printf("\t%d",head1->data);
			head1=head1->next;
			head2=head2->next;
		}
	}
	
}
main()
{
	struct node *head1=NULL,*head2=NULL;
	int n;
	printf("Enter no of node in first list");
	scanf("%d",&n);
	if(head1==NULL)
	{
		printf("Enter data");
		head1=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&head1->data);
		head1->next=NULL;
	}
	create_list(head1,n);
	printf("First list is");
	display(head1);
	printf("\nEnter no of node in second list");
	scanf("%d",&n);
	if(head2==NULL)
	{
		printf("Enter data:");
		head2=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&head2->data);
		head2->next=NULL;
	}
	create_list(head2,n);
	printf("Second list is");
	display(head2);
	printf("\nUnion is ");
	union1(head1,head2);
	printf("\nintersection is");
	intersection(head1,head2);
	
}

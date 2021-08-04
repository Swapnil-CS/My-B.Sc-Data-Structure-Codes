//circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert_first()
{
	  int k;
	  struct node *ptr,*s;
	  printf("Enter data:");
	  scanf("%d",&k);
	  ptr=(struct node*)malloc(sizeof(struct node));
	  ptr->data=k;
	  if(head==NULL)
	  {
	  	ptr->next=ptr;
	  	head=ptr;
	  }
	  else
	  {
	  	s=head;
	  	while(s->next!=head)
	  	   s=s->next;
	  	ptr->next=head;
	  	head=ptr;
	  	s->next=head;
	  }
}
void insert_last()
{
	int k;
	struct node *ptr,*s;
	printf("Enter data:");
	scanf("%d",&k);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=k;
	if(head==NULL)
	{
		ptr->next=ptr;
		head=ptr;
	}
	else
	{
		s=head;
		while(s->next!=head)
		  s=s->next;
		s->next=ptr;
		ptr->next=head;
	}
}
void display()
{
	struct node *s;
	s=head;
	while(s->next!=head)
	{
		printf("\t%d",s->data);
		s=s->next;
	}
	printf("\t%d",s->data);
}
main()
{
	int ch;
	while(1)
	{
		printf("\n1 insert first\n2 insert last");
		printf("\n3 insert position\n4 delete position");
		printf("\n5 display\n6 exit");
		printf("\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert_first();break;
			case 2:insert_last();break;
			case 3:break;
			case 4:break;
			case 5:display();break;
			case 6:exit(0);
		}
	}
}

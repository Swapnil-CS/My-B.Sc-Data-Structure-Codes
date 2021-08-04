//priority queue
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data,pri;
	struct node *next;
};
struct node *head=NULL;
void insert()
{
	struct node *ptr,*s,*w;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter data and priority");
	scanf("%d%d",&ptr->data,&ptr->pri);
	if(head==NULL)
	{
		ptr->next=NULL;
		head=ptr;
	}
	else if(head->pri<ptr->pri)
	{
		ptr->next=head;
		head=ptr;
	}
	else
	{
	   s=head->next;
	   w=head;	
	   while(s->pri>=ptr->pri &&s!=NULL)
	   {
	   	s=s->next;
	   	w=w->next;
	   }
	   ptr->next=s;
	   w->next=ptr;
	}
}
void del()
{
	struct node *s;
	printf("\ndeleted node %d and priority %d",head->data,head->pri);
	s=head;
	head=head->next;
	free(s);
}
void display()
{
	struct node *s;
	s=head;
	while(s!=NULL)
	{
		printf("[%d %d]",s->data,s->pri);
		s=s->next;
	}
}
main()
{
	int ch;
	while(1)
	{
		printf("\n1 for insert\n2 for delete\n 3 for display");
		printf("\n4 for exit\nenter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();break;
			case 2:del();break;
			case 3:display();break;
			case 4:exit(0);
		}
	}
}

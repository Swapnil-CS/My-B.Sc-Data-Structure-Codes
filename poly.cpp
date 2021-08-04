//union of two sorted linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef,power;
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
		   printf("Enter coef and power:");
		   scanf("%d%d",&ptr->coef,&ptr->power);
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
		printf("\t(%dx^%d)",head->coef,head->power);
		head=head->next;
	}
}
void polyadd(struct node *head1,struct node *head2)
{
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->power>head2->power)
		{
			printf("\t(%dx^%d)",head1->coef,head1->power);
			head1=head1->next;
		}
		else if(head2->power>head1->power)
		{
			printf("\t(%dx^%d)",head2->coef,head2->power);
			head2=head2->next;
		}
		else
		{
			printf("\t(%dx^%d)",head1->coef+head2->coef,head1->power);
			head1=head1->next;
			head2=head2->next;
		}
	}
	while(head1!=NULL)
	{
		printf("\t(%dx^%d)",head1->coef,head1->power);
		head1=head1->next;
	}
	while(head2!=NULL)
	{
	printf("\t(%dx^%d)",head2->coef,head2->power);
		head2=head2->next;
	}
}
void polysub(struct node *head1,struct node *head2)
{
	 struct node *s2;
	 s2=head2;
	 while(s2!=NULL)
	 {
	 	 s2->coef=-1*s2->coef;
	 	 s2=s2->next;
	 }
	 polyadd(head1,head2);
}
main()
{
	struct node *head1=NULL,*head2=NULL;
	int n;
	printf("Enter no of term in first polynomial");
	scanf("%d",&n);
	if(head1==NULL)
	{
		printf("Enter coef and power");
		head1=(struct node*)malloc(sizeof(struct node));
		scanf("%d%d",&head1->coef,&head1->power);
		head1->next=NULL;
	}
	create_list(head1,n);
	printf("First poly is");
	display(head1);
	printf("\nEnter no of term in second poly");
	scanf("%d",&n);
	if(head2==NULL)
	{
		printf("Enter coef and power");
		head2=(struct node*)malloc(sizeof(struct node));
		scanf("%d%d",&head2->coef,&head2->power);
		head2->next=NULL;
	}
	create_list(head2,n);
	printf("Second poly is");
	display(head2);
	printf("\npoly add is ");
	polyadd(head1,head2);
	printf("\nPoly sub is");
	polysub(head1,head2);

}

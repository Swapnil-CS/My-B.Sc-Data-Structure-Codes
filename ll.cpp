#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
void insert_last()
{
    int k;
    struct node *ptr,*s;
   printf("Enter a node value which we want to insert last:");
   scanf("%d",&k);
   ptr=(struct node*)malloc(sizeof(struct node));
   ptr->data=k;
   ptr->next=NULL;
   if(head==NULL)
   {
          head=ptr;
   }
   else
   {
       s=head;
       while(s->next!=NULL)
          s=s->next;
      s->next=ptr;
   }
}
void insert_first()
{
    struct node *ptr;
    int k;
      printf("Enter a number:");
     scanf("%d",&k);
     ptr=(struct node*)malloc(sizeof(struct node));
      ptr->data=k;
       if(head==NULL)
       {
          ptr->next=NULL;
            head=ptr;
        }
        else
        {
            ptr->next=head;
            head=ptr;
       }
}
void display()
{
    struct node *s;
    s=head;
    while(s!=NULL)
     {
        printf("\t%d",s->data);
       s=s->next;
     }
}
void insert_after_node_value()
{
	int k,a,f=0;
	struct node *ptr,*s;
   printf("Enter new node value:");
   scanf("%d",&k);
   ptr=(struct node*)malloc(sizeof(struct node));
   ptr->data=k;	
   printf("Enter a node value after which you want to insert:");
   scanf("%d",&a);
   s=head;
   while(s->data!=a)
   {
   	s=s->next;
   	 if(s==NULL)
   	 {
   	 	f=1;
   	 	break;
	}
   }	
   if(f==1)
   {
   	  free(ptr);
   	  printf("Node value not present in the list");
   }
   else
   {
   	 ptr->next=s->next;
   	 s->next=ptr;
   }
}
void insert_before_node_value()
{
	int k,a,f=0;
	struct node *ptr,*s,*w;
	printf("Enter new node value:");
	scanf("%d",&k);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=k;
	printf("Enter node valur before which we want to insert:");
	scanf("%d",&a);
	if(head->data==a)
	{
		ptr->next=head;
		head=ptr;
	}
	else
	{
		s=head->next;
		w=head;
		while(s->data!=a)
		{
			s=s->next;
			w=w->next;
			if(s==NULL)
			{
			f=1;break;
			}
		}
	    if(f==1)
	    {
	    	free(ptr);
	    	printf("Node does not exits");
		}
		else
		{
			w->next=ptr;
			ptr->next=s;
		}
		
	}
}
void insert_position()
{
	int k,p,i;
	struct node *ptr,*s;
	
	printf("\nEnter new node value:");
	scanf("%d",&k);
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=k;
	printf("Enter position to insert");
	scanf("%d",&p);
	if(p==1)
	{
		ptr->next=head;
		head=ptr;
	}
	else
	{
		s=head;
		for(i=1;i<=p-2;i++)
		   s=s->next;
		ptr->next=s->next;
		s->next=ptr;
	}
}
void delete_position()
{
	int p,i;
	struct node *s,*t;
	printf("Enter position to delete:");
	scanf("%d",&p);
	if(p==1)//if position is 1
	{
		s=head; //points to head
		head=head->next;//move to second node
		free(s);//free the first node
	}
	else
	{
	  s=head;//points to the head
	  for(i=1;i<=p-2;i++)//move deleted node previous position
	   s=s->next;
	 t=s->next;//points deleted node
	 s->next=t->next; //deallocates deleted node
	 free(t);	//free deleted node
	}
}
void count_node()
{
	struct node *s;
	int count=0;
	s=head;//point to first node
	while(s!=NULL)
	{
		s=s->next;
		count=count+1;//5
	}
	printf("\nTotal no of nodes %d",count);
}
void print_reverse(struct node *s)
{
	if(s!=NULL)
	{
		print_reverse(s->next);
		printf("\t%d",s->data);
	}
}
void physically_reverse()
{
	struct node *s,*t1,*t2;
	s=head;
	t1=s->next;
	t2=t1->next;
	s->next=NULL;
	while(t2!=NULL)
	{
	  t1->next=s;
	  s=t1;
	  t1=t2;
	  t2=t2->next;	
	}
	t1->next=s;
	head=t1;
}
void search_node()
{
	int item,f=0,c=0;
	struct node *s;
	printf("Enter node value for serch");
	scanf("%d",&item);
	s=head;
	while(s!=NULL)
	{
		if(s->data==item)
		{
			f=1;break;
		}
		s=s->next;
		c++;
	}
	if(f==1)
	printf("found in position %d",c+1);
	else 
	printf("not found");
	
}
void node_sort()
{   int t;
	struct node *s,*s1;
	s=head;
	while(s->next!=NULL)
	{
		s1=s->next;
		while(s1!=NULL)
		{
			if(s->data>s1->data)
			{
			t=s->data;
			s->data=s1->data;
			s1->data=t;
			}
			s1=s1->next;
	    }
	    s=s->next;
	}
}
main()
{
	int ch;
	while(1)
	{
		    printf("\n1 for insert last\n2 for insert first\n3 for display");
		    printf("\n4 for insert after node value");
		    printf("\n5 for insert before a node value");
		    printf("\n6 for insert at any position");
		    printf("\n7 for delete from any position");
		    printf("\n8 for count total no of nodes:");
		    printf("\n9 for reverse display:");
		    printf("\n10 for physically reverse:");
		    printf("\n11 searching a node");
		    printf("\n12 sorting a linked list");
			printf("\n0 for exit");
		    printf("\nEnter your choice:");
		    scanf("%d",&ch);
		    switch(ch)
		    {
		    	case 1:insert_last();break;
		    	case 2:insert_first();break;
		    	case 3:display();break;
		    	case 4:insert_after_node_value();break;
		    	case 5:insert_before_node_value();break;
		    	case 6:insert_position();break;
		    	case 7:delete_position();break;
		    	case 8:count_node();break;
		    	case 9:print_reverse(head);break;
		    	case 10:physically_reverse();break;
		    	case 11:search_node();break;
		    	case 12:node_sort();break;
		    	case 0:exit(0);
			}
		
	}
}

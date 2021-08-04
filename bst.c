//bst
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root=NULL;
void bst_creation(struct node *root,struct node *ptr)
{
	//ptr ->new node which you want to insert
	//root ->root node address
	if(ptr->data<root->data)
	{
		if(root->left==NULL)
		   root->left=ptr;
		else
		 bst_creation(root->left,ptr);  
	}
	else
	{
		if(root->right==NULL)
		  root->right=ptr;
		else
		   bst_creation(root->right,ptr);
	}	
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);//L
		printf("\t%d",root->data);//D
		inorder(root->right);//R
	}
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("\t%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("\t%d",root->data);
	}
}
main()
{
	int ch;
	int k;
	struct node *ptr;
	while(1)
	{
		printf("\n1 insert into bst");
		printf("\n2 inorder traversal");
		printf("\n3 preorder traversal");
		printf("\n4 postorder traversal");
		printf("\n0 for exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter data:");
				    //fflush(stdin);
			       scanf("%d",&k);
			       ptr=(struct node*)malloc(sizeof(struct node));
			       ptr->data=k;
			       ptr->left=NULL;
			       ptr->right=NULL;
			       if(root==NULL)
			         root=ptr;
			        else
			          bst_creation(root,ptr);
			          break;
			 case 2:inorder(root);break;
			 case 3:preorder(root);break;
			 case 4:postorder(root);break;
			 case 0:exit(0);
		}
	}
}

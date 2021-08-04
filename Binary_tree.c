#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node *create_node(int item)
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void bst_insertion(struct node *root,struct node *p)
{
    if(p->data<root->data)
    {
        if(root->left==NULL)
            root->left=p;

        else
            bst_insertion(root->left,p);
    }
    else
    {
        if(root->right==NULL)
            root->right=p;

        else
            bst_insertion(root->right,p);
    }
}
void bst_search(struct node *root,int item)
{
    struct node *p;
    bool flag=false;
    p=root;
    while(p!=NULL && flag!=true)
    {
        if(item<p->data)
        {
            p=p->left;
        }
        else if(item==p->data)
        {
            flag=true;
        }
        else
        {
            p=p->right;
        }
    }
    if(flag==true)
        printf("\n%d has been found at %d",item,p);
    else
        printf("\n%d doesn't exist: Search Unsuccessful...!",item);    
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
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("\t%d",root->data);
        inorder(root->right);
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
void main()
{
    int item,ch;
    struct node *p;
    while(1)
    {
        printf("\n1.BST Insertion\n2.BST Searching\n3.Pre-Order Traversal\n4.In-Order Traversal\n5.Post-Order Traversal\n6.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter value to be stored:");
                scanf("%d",&item);
                p=create_node(item);
                if(root==NULL)
                {
                    root=p;
                }
                else
                {
                    bst_insertion(root,p);
                }
                break;
            case 2:
                printf("\nEnter the value you want to search:");
                scanf("%d",&item);
                bst_search(root,item);
                break;    
            case 3:
                preorder(root);
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                exit(0);
                break;  
            default:
                printf("\nWrong Choice Given...!");  
        }
    }
}

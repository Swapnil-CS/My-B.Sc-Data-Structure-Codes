#include<stdio.h>
#include<stdlib.h>
void linear_iter(int *arr,int item,int n)
{
	int i,f=0;
	for(i=0;i<n;i++)
	{
		if(*(arr+i)==item)
		{
			f=1;
			printf("\nElement found at position %d",i+1);
		}
	}
	if(f==0)
	printf("\nElement not found in the array");
}
int linear_rec(int *arr,int item,int n)
{
	if(n<0)
	return -1;
	else if(*(arr+n)==item)
	return n;
	else
	return linear_rec(arr,item,n-1);
}
int binary_iter(int *arr,int lb,int ub,int item)
{
		int mid,f=-1;		
	while(ub>=lb)
	{
		mid=(lb+ub)/2;
		if(*(arr+mid)==item)
		{
			f=1;
			break;
		}
		else if(*(arr+mid)<item)
		  lb=mid+1;
		else
		  ub=mid-1;
	}
  if(f==1)
    return mid;
  else
    return f;	
}
int binary_rec(int *arr,int lb,int ub,int item)
{
	 int mid;

		mid=(lb+ub)/2;
		if(ub<lb)
		  return -1;
		else if(*(arr+mid)==item)
	     return mid;
		else if(*(arr+mid)<item)
	     return binary_rec(arr,mid+1,ub,item);                  
		else
		 return binary_rec(arr,lb,mid-1,item);
}
void main()
{
	int n,*arr,i,ch,item,t;
	printf("\nEnter number of elements to store in the array:");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("\nEnter %d elements(in ascending order):",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	while(1)	
	{
		printf("\n\n1.Iterative Linear Search\n2.Recursive Linear Search\n3.Iterative Binary Search\n4.Recursive Binary Search\n5.Exit");
		printf("\n\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to be searched using iterative linear search:");
				scanf("%d",&item);
				linear_iter(arr,item,n);
				break;
			case 2:
				printf("\nEnter the element to be searched using recursive linear search:");
				scanf("%d",&item);
				t=linear_rec(arr,item,n-1);
				if(t==-1)
				printf("\nElement not found in the array");
				else
				printf("\nElement found at position %d",t+1);
				break;
			case 3:
				printf("\nEnter the element to be searched using iterative binary search:");
				scanf("%d",&item);
				t=binary_iter(arr,0,n-1,item);
				if(t==-1)
				printf("\nElement not found in the array");
				else
				printf("\nElement found at position %d",t+1);
				break;	
			case 4:
				printf("\nEnter the element to be searched using recursive binary search:");
				scanf("%d",&item);
				t=binary_rec(arr,0,n-1,item);
				if(t==-1)
				printf("\nElement not found in the array");
				else
				printf("\nElement found at position %d",t+1);
				break;
			case 5:
				exit(0);		
		}
	}
	free(arr);
}

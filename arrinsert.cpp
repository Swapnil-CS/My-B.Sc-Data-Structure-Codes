#include<stdio.h>
int main()
{
	int arr[10],pos,i,n,value;
	printf("Enter number of elements in array:");
	scanf("%d",&n);
	printf("\n Enter elements of array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		
	}
	printf("Array before insertion");
	for(i=0;i<n;i++)
	{
		printf(" %d",arr[i]);
		
	}
	printf("\n Enter the position to insert the element:");
	scanf("%d",&pos);
	printf("\n Enter the value to  insert:");
	scanf("%d",&value);
	i=n-1;
	while(i>=pos-1)
	{
		arr[i+1]=arr[i];
		i=i-1;
	}
	arr[pos-1]=value;
	for(i=0;i<=n;i++)
	{
		printf(" %d",arr[i]);
		
	}
	return 0;
}

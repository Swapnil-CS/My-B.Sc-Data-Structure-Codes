#include<stdio.h>
int main()
{
	int arr[10],i,n,key,pos,flag=0;
	printf("Enter the number of elements in  array:");
	scanf("%d",&n);
	printf("\n Enter elements in array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		
	}
	printf("\n Array before deletion of element");
	for(i=0;i<n;i++)
	{
		printf(" %d",arr[i]);
		
	}
	printf("\n Enter the element to delete:");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			pos=i;
			flag=1;
		}
    }
	
	
	
		if(flag==1)
		{
		while(pos<n-1)
		{
			arr[pos]=arr[pos+1];
			pos=pos+1;
		}
			printf("\n New array is");
		for(i=0;i<n-1;i++)
		{
			printf(" %d",arr[i]);
			
		}
        }
        else
        {
        	printf("\nElement not found in array");
		}
}

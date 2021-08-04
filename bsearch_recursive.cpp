//binary search
#include<stdio.h>
int bsearch(int a[],int min,int max,int item)
{
	     int mid;

		mid=(min+max)/2;
		if(max<min)
		  return -1;
		else if(a[mid]==item)
	     return mid;
		else if(a[mid]<item)
	      bsearch(a,mid+1,max,item);                  //min=mid+1;
		else
		  bsearch(a,min,mid-1,item);               //   max=mid-1;
}
main()
{
	int a[30],n,i,item,f;
	printf("Enter no of elements ",n);
	scanf("%d",&n);
	printf("Enter %d elements(ascending order)",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter element to search:");
	scanf("%d",&item);
	f=bsearch(a,0,n-1,item);
	if(f==-1)
	   printf("item not found ");
	else
	   printf("item found position %d",f+1);
}


//binary search
#include<stdio.h>
int bsearch(int a[],int min,int max,int item)
{
	int mid,f=-1;
	while(max>=min)
	{
		mid=(min+max)/2;
		if(a[mid]==item)
		{
			f=1;break;
		}
		else if(a[mid]<item)
		  min=mid+1;
		else
		  max=mid-1;
	}
  if(f==1)
    return mid;
  else
    return f;	
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


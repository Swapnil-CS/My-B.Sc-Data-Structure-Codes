//Linear search
#include<stdio.h>
void lsearch(int a[],int n,int item)
{
	//a[]->list of elements 
	//n->size of the array
	//item ->elemet t to be searched
	int f=0,i;
	for(i=0;i<n;i++)
	{
		if(a[i]==item)
		{
			f=1;break;
		}
	}
	if(f==1)
	  printf("found in position %d",i+1);
	else
	  printf("\nElement not found");
}
main()
{
	int a[30],n,i,item;
	printf("Enter size of an array:");
	scanf("%d",&n);
	printf("Enter %d elements ",n);
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	printf("\nEnter element to search:");
	scanf("%d",&item);
	lsearch(a,n,item);
}

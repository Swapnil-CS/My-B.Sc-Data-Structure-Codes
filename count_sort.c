#include<stdio.h>
#include<stdlib.h>
//function for calculating the largest element of input array
int maxval(int *a,int n)
{
    int i,max;
    max=a[0];       //initialising max value as the 1st element of input array
    for(i=0;i<n;i++)
    {
        if(a[i]>max)        //finding max element
        {
            max=a[i];
        }
    }
    return max;     //returning max 
}

//function for count sort
void countSort(int *a,int n)    
{
    int *c,*b,i,j,max;
    max=maxval(a,n);
    b=(int*)malloc((n)*sizeof(int));        //dynamically allocating the output array of size n i.e input size
    c=(int*)malloc((max+1)*sizeof(int));    //dynamically allocating the count array having size = (largest element of input array)+1
    
    //initialising the count array elements to 0
    for(i=0;i<max+1;i++)        
    {
        c[i]=0;
    }
    
    //finding the occurrence of each element of input array and storing them into count array
    for(i=0;i<n;i++)
    {
        c[a[i]]=c[a[i]]+1;
    }

    //finding the index values for each element of the output array 
    for(i=1;i<max+1;i++)
    {
        c[i]=c[i]+c[i-1];
    }

    for(i=n-1;i>=0;i--)
    {
        b[c[a[i]]]=a[i];    //placing each element in the output array
        c[a[i]]=c[a[i]]-1;    //decrementing the index value by 1
    }
    
    //printing the sorted array as output
    printf("\nArray after sorting is:\n");
    for(i=1;i<=n;i++)
    {
        printf("\t%d",b[i]);
    }
}

void main()
{
    int n,*a,i;
    do
	{
		printf("\nEnter number of elements to store in the array(enter positive integer other than 0):");
		scanf("%d",&n);
	}while(n<=0);   //condition for giving onlu positive value as number of elements
    a=(int*)malloc(n*sizeof(int));  //dynamically allocating the space for input array
	printf("\nEnter %d elements(enter values which are >=0):",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

    //printing the input array
    printf("\nArray before sorting is:\n");
    for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}

    countSort(a,n);     //calling count sort function
}
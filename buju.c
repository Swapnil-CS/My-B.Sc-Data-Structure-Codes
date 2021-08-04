#include<stdio.h>
#include<conio.h>

void main()
{
    int a[500],b[500],n,m,i,j,p,o;
    printf("enter no of elements of 1st array:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter %d number:",i+1);
        scanf("%d",&a[i]);
    }
    printf("enter no of elements of 2nd array:");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("enter %d number:",i+1);
        scanf("%d",&b[i]);
    }
    printf( "which array you need to copy?");
    printf("\n1.1st array into 2nd array\n2.2nd array into 1st array");
    printf("\nenter your choice:");
    scanf("%d",&o);
    switch(o)
    {
    case 1:
        printf("where from you wanna paste? ");
        scanf("%d",&p);
        for(i=m-1;i>=p-1;i--)
        {
            b[i+n]=b[i];

        }
        i=p-1;
        j=0;
        while(i<p-1+n)
        {
            b[i]=a[j];
			i++;
			j++;
        }
         printf("new array is -->\n");
    for(i=0;i<m+n;i++)
    {
        printf("\t%d",b[i]);
    }
    break;
    case 2:
        printf("where from you wanna paste? ");
        scanf("%d",&p);
        for(i=n-1;i>=p-1;i--)
        {
            a[i+m]=a[i];

        }
        i=p-1;
        j=0;
        while(i<p-1+m)
        {
            a[i]=b[j];
            i++;
			j++;
        }
         printf("new array is -->\n");
    for(i=0;i<n+m;i++)
    {
        printf("\t%d",a[i]);
    }
    break;
    default :
    	printf("\nInvalid choice...!");

    }

    getch();

}

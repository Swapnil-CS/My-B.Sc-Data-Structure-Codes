#include<stdio.h>
#include<conio.h>

struct poly
{
	int coef;
	int deg;
};
int main()
{
	struct poly a[10],b[10],c[10];
	int i,j,n;
	printf("Enter the limit");
	scanf("%d",&n);
	printf("Enter the terms of first polynomial");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a[i].deg,&a[i].coef);
	}
	printf("Enter thr terms of second polynomial");
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&b[i].deg,&b[i].coef);
	}
	for(i=0;i<n;i++)
	{
		if(a[i].deg==b[i].deg)
		{
			c[j].deg=a[i].deg;
			c[j].coef=a[i].coef+b[i].coef;
			j++;
		}
		else if(a[i].deg>=b[i].deg)
		{
			c[j].deg=a[i].deg;
			c[j].coef=a[i].coef;
			j++;
		}
		else if(a[i].deg<=b[i].deg)
		{
			c[j].deg=b[i].deg;
			c[j].coef=b[i].coef;
			j++;
		}
	}
	printf("Your Result is ");
	for(i=0;i<j;i++)
	{
		printf("%dx^%d+",c[i].coef,c[i].deg);
		
	}
	return 0;
}

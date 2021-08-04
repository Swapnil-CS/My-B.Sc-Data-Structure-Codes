#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n,j,t1=0,t2=1,temp;
    printf("\nEnter number of terms:");
    scanf("%d",&n);
    while(n>=1)
    {
        j=t1+1;
        while(j<t2 && n>=1)
        {
            printf("\t%d",j);
            n--;  
            j++;
        }
        temp=t1+t2;
        t1=t2;
        t2=temp;
    }
}
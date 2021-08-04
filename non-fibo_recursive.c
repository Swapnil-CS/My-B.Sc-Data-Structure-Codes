#include<stdio.h>
#include<stdlib.h>
void non_fibo_rec(int n,int t1,int t2,int j)
{
    if(n>=1 && j<t2 && j!=t1)
    {
            printf("\t%d",j);
            return non_fibo_rec(n-1,t1,t2,j+1); 
    }
    else
        return non_fibo_rec(n,t2,t1+t2,j+1);
}
void main()
{
    int n;
    printf("\nEnter the number of elements:");
    scanf("%d",&n);
    non_fibo_rec(n,0,1,0);
}
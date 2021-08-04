#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
  int k,i,l;
  char str[80];
  printf("enter sentence");
  gets(str);
     for(k=97;k<=122;k++)
      {
      	l=0;
          for(i=0;str[i]!='\0';i++)
          {
            if(str[i]==k)
            l++;
          }
          printf("%c--->%d",str[i],l);
      }
      getch();
  }

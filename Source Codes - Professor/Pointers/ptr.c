#include<stdio.h>
int main()
{
 int x=10;
 int *y;
 int **z;
 y=&x;
 z=&y;
 printf("The value of x = %d\n",x);
 printf("The address of x=%p\n",&x);
 printf("The value of x=%d\n",*(&x));
 printf("the value of x=%d\n",*y);
printf("the value of x=%d\n",**z);
 }

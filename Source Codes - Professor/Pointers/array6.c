#include<stdio.h>
//pointers and arrays
int main()
{
 int a[]={0,1,2,3,4};
 int *p[]={a,a+1,a+2,a+3,a+4};
 int **ptr=p;
 printf("%p %d\n",a, *a); 
 printf("%p %p %d\n",p, *p, **p);  
 printf("%p %p %d\n",ptr, *ptr, **ptr);
 
}

 

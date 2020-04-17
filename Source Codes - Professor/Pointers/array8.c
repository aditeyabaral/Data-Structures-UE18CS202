#include<stdio.h>
int main()
{
  int a[]={1,2,3,4};
  int (*q)[4];//q is a pointer to an array of size 4
  printf("\na= %p\n",a);//address of a[0]
  printf("*a = %d\n",*a);//prints 1
  printf("a+1 = %p\n",a+1);
  int *p=a+1;
  printf("&a = %p\n",&a);//prints address of a[0];
  printf("&a+1 = %p\n",&a+1);
  q=&a;
  printf ("q=%p",q);
 } 
























/*int main()
{
 int a[3]={1,2,3};
 int (*q)[3];
 printf("\na = %p\n",a);
 printf("*a = %d\n",*a);
 printf("a+1=%p\n",a+1);
 printf("*(a+1)=%d\n",*(a+1));
 printf("&a=%p\n",&a);
 printf("&a+1%p\n",&a+1);
 q=&a;
 printf("q=%p\n",q);
}*/



//programs on pointers

#include<stdio.h>
void f(int , int* );

int main()
{  
 int a[5]={2,4,6,8,10};
 int i,b=5;
 for(i=0;i<5;i++)
 {
   f(a[i],&b);//array element passed by value, b by reference
   printf("%d %d\n",a[i],b);
 }
}

void f(int x, int *y)
 {
  x=*y+=2;
 }

 


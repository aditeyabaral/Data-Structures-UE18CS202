#include<stdio.h>
void disp(int *a, int n);
int main()
{
 int a[5]={1,2,3,4,5};
 disp(a,5);
}

 void disp(int *a, int n) // display address of elements of array
 {
  int i;
  for(i=0;i<n;i++)
  {
   printf("The address of the %d element=%p\n",i, a);
   a++;
 }
}

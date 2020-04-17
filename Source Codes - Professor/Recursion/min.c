#include<stdio.h>
int main()
{
  int minimum(int*, int);
  int k;
  int a[]={10,5,2,3};

  k=minimum(a,3);
  printf("The smallest = %d",k);
}
  

  int minimum(int *a, int n)
  {
    int k;
    if(n==0)
      return a[0];
    k= minimum(a,n-1);
    if(k < a[n])
      return k;
    else
      return a[n];
  }
  

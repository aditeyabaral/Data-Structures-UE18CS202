#include<stdio.h>
int main()
{
  int sum(int*, int);
  int k;
  int a[]={10,5,2,3};

  k=sum(a,3);
  printf("The sum = %d\n",k);
}
  
  int sum(int *a, int n)
  {
    int k;
    if(n==0)
      return a[0];
    return (sum(a,n-1) +a[n]);
   
  }
  

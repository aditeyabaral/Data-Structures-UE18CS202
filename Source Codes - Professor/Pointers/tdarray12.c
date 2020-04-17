#include<stdio.h>
int main()
{
 int a[3][3]={1,2,3,
              4,5,6,
              7,8,9
             };

 printf("a= %p\n",a);  //pointer to an array
 printf("a+1 =%p\n",a+1);

 printf("\na[0]= %p\n",a[0]);//integer pointer
 printf("a[0]+1 =%p\n",a[0]+1);

 printf("\n&a[0][0] = %p\n",&a[0][0]);//integer pointer
 printf("&a[0][0]+1 = %p\n",&a[0][0]+1);

 printf("\n&a[0] = %p\n",&a[0]);//array  pointer
 printf("&a[0]+1 = %p\n",&a[0]+1);

printf("\n&a= %p\n",&a);
 printf("&a+1 = %p\n",&a+1);

int (*q)[3][3]=&a;

 printf("\n q= %p\n",q);
 printf("\n q+1=%p\n",q+1);
}        









    

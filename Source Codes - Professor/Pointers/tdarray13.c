
#include<stdio.h>
main()
{
 int a[3][3]=
            {
             1,2,3,
             4,5,6,
             7,8,9
            };

 int *pa[3]={a[0],a[1],a[2]};
 int *p =a[0];
 int i;
  for(i=0;i<3;i++)
    printf("\n%d %d %d",a[i][2-i], *a[i], *(*(a+i)+i));

 printf("\n\n");  
for(i=0;i<3;i++)
   printf("\n%d %d ",*pa[i], p[i]);
 }


#include<stdio.h>
#include<stdlib.h>
int main()
{
  //int *p;
  int i;
  int p[10];
 // p=malloc(sizeof(int)*10);
 // for(i=0;i<10;i++)
   // p[i]=10;
 // for(i=0;i<10;i++)
  //  scanf("%d",&p[i]);

   for(i=0;i<10;i++)
     scanf("%d",(p+i));

  
for(i=0;i<10;i++)
    printf(" %d",p[i]);
 }
  




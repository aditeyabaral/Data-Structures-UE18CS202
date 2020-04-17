#include<stdio.h>
#include<stdlib.h>
int main()
{
  int **p;
  int i,j;
  int rows=3;
  int cols=3;
 
  p=malloc(sizeof(int*)*rows);
  
  for(i=0;i<rows;i++)
   p[i]=malloc(sizeof(int)*cols);

  for(i=0;i<rows;i++)
  {
    for(j=0;j<cols;j++)
      scanf("%d",(p[i]+j));
  }

  printf("Printing the array elements\n");

  for(i=0;i<rows;i++)
  {
    for(j=0;j<cols;j++)
      printf("%d ",p[i][j]);
    printf("\n");
  }
 
}

 


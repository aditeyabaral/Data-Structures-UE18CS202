#include<stdio.h>
 //implement heap by using top down up technique
 //delete the largest number and recreate the heap
 //after deletion
  void bot_heap(int*,int);
  void top_heap(int *, int);
  int max_delete(int*, int*);
  void heapify(int*, int);
  int main()
  {
    int h[100];//heap;
    int i,n,max;//no of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);
    printf("Enter the elements..\n");
    for(i=0;i<n;i++)
      scanf("%d",&h[i]);
   top_heap(h,n-1);//pass index of the last element 
   printf("After creating heap using top down approach..\n");
    for(i=0;i<n;i++)
      printf("%d ",h[i]);

   max=max_delete(h,&n);
   printf("\nThe largest element deleted = %d",max);
   printf("\nThe heap after deletion..\n");
   for(i=0;i<n;i++)
      printf("%d ",h[i]);

  }

  void top_heap(int *h, int n)//n is the index of the last element
  {
    int i,j,k,key;

    for(k=1;k<=n;k++)
    {
      i=k;
      key=h[i];

      j=(i-1)/2;
      
      //repeat until value of key is greater than the parent
      //or the root is reached(i=0)
      while((i>0)&&(key>h[j]))
      {
        h[i]=h[j];
        i=j;
        j=(i-1)/2;
      }
     h[i]=key;
   }
}     

 int max_delete(int *h, int *n)//n - pointer to number of elements in heap
  {
    int max;

    max=h[0];
    h[0]=h[*n-1];
    --*n;//reduce the number of elements by 1
    heapify(h,*n-1);//pass the index of the last element
    return max;
  }

  void heapify(int *h, int n)//n is the index of the last element
   {
    int i,j,key;
    j=0;
    key=h[j];
   
    i=2*j+1;//find the index of the left child
    
    while(i<=n)//if the left child exists
    {
      if((i+1)<=n)//check if the right child exists
      {
        if(h[i+1]>h[i])
           i++; //get the index of the largest child
      }
      if(key<h[i])
      {
        h[j]=h[i];//move child up
        j=i;
        i=2*j+1;//find the left child
       }
      else
        break;
    }
   h[j]=key;//insert the key in its proper place
  }




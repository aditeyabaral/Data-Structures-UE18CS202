 #include<stdio.h>
 //implement heap by using bottom up technique
  void bot_heap(int*,int);
  void top_heap(int *, int);
  
  int main()
  {
    int h[100];//heap;
    int i,n;//no of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);
    printf("Enter the elements..\n");
    for(i=0;i<n;i++)
      scanf("%d",&h[i]);
    bot_heap(h,n-1);//pass index of last element
   //top_heap(h,n-1);//pass index of the last element 
   printf("After creating heap..\n");
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


  void bot_heap(int *h, int n)//n ->index of the last element
  {
   int i,j,k,key;

   for(k=(n-1)/2;k>=0;k--)//start from the last parent
   {
    j=k;
    key=h[j];
    
    i=2*j+1;//find the index of left child
    
    while(i<=n)//left child exists
    {
      if((i+1)<=n)//right child exists
      {
        if(h[i+1]>h[i]) //(REPLACING > WITH < WILL CREATE MIN HEAP)
         i++;//get the index of the largest child
      }
      if(key<h[i])
        {//(REPLACING < WITH > WILL CREATE MIN HEAP)
        h[j]=h[i];//move the child up
        j=i;
        i=2*j+1;//get the index of the left child
      }
     else
      break;
    }
   h[j]=key;
  }
}





















 













































      























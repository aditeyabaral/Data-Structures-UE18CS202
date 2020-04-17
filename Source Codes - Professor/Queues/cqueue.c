#include<stdlib.h>
#include<stdio.h>

int qinsert(int*,int*,int*,int,int);
 int qdelete(int *,int *, int*,int);
 void display(int *,int,int,int);
int main()
{
  
  int *q;
  int ch,k,x;
   int f,r, size;
  f=r=-1;
  printf("Enter the size of the size..");
  scanf("%d",&size);

  q=malloc(sizeof(int)*size);
  while(1)
  {
    display(q,f,r,size);
    printf("\n1..Insert");
    printf("\n2..Delete");
    printf("\n3..Display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              k=qinsert(q,&f,&r,size,x);
              if(k>=0)
                 printf("Element inserted successfully\n");
               break;
       case 2:k=qdelete(q,&f,&r,size);
              if(k>=0)
                printf("element deleted=%d\n",k);
              break;
        case 4:exit(0); 
   }
  }
 }

  int qinsert(int *q,int *f,int *r,int size,int x)
  {
    //check for queue full

    if((*r+1)%size ==*f)
    {
     printf("Queue full\n");
     return -1;
    }
     *r=(*r+1)%size;
     q[*r]=x;
     if(*f==-1)
       *f=0;

   }

 int qdelete (int *q,int *f,int *r,int size )
 {
   int x;
   if(*f==-1)
   {
        printf("Queue empty..\n");
        return -1;
    }
    x=q[*f];
    if(*f==*r)//only one element
      *f=*r=-1;
    else
      *f=(*f+1)%size;
     return x;
  }


    void display(int *q,int f,int r,int size)
    {
      if(f==-1)
       printf("Queue empty..\n");
     else
     {
      while(f!=r)
      {
       // printf("f= %d r = %d\n",f,r);
        printf("%d ",q[f]);
        f=(f+1)%size;
      }
      printf("%d ",q[f]);//last element displayed
   }
}




 






















/*int qinsert(int *q, int *f,int *r,int size,int x)
 {
   //check for queue full

   if((*r+1)%size==*f)
    {
        printf("Queue full..\n");
        return -1;
    }
   *r=(*r+1)%size;
   q[*r]=x;
   if(*f==-1)//empty queue, first element entered
     *f=0;
    return 1;
  }

  int qdelete(int *q, int *f, int *r, int size)
   {
     int x;
     if(*f==-1)
     {
       printf("Queue empty..\n");
       return -1;
     }
     x=q[*f];
     if(*f==*r)//only one element
       *f=*r=-1;
     else
      *f=(*f+1)%size;
      return x;
   }

  void display(int *q, int f, int r,int size)
  {
    if(f==-1)
      printf("Queue empty..\n");
    else
    {
      while(f!=r)
      {
        printf("%d ",q[f]);
        f=(f+1)%size;
      }
     printf("%d ",q[f]);//print the last element
  }
 }*/
      
























  











  











//program to implement a simple queue using a structure
#include<stdlib.h>
#include<stdio.h>
struct queue
{
  int *q;
  int f,r,size;
};


int qinsert(struct queue*, int);
 int qdelete(struct queue*);
 void display(struct queue);
int main()
{
  
  struct queue q;
  int ch,k,x;
  int f,r, size;
  q.f=q.r=-1;
  printf("Enter the size of the queue..");
  scanf("%d",&q.size);

  q.q=malloc(sizeof(int)*q.size);
  while(1)
  {
    display(q);
    printf("\n1..Insert");
    printf("\n2..Delete");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              k=qinsert(&q,x);
              if(k>=0)
                 printf("Element inserted successfully\n");
               break;
       case 2:k=qdelete(&q);
              if(k>=0)
                printf("element deleted=%d\n",k);
              break;
        case 4:exit(0); 
   }
  }
 }

 int qinsert(struct queue *q, int x)
 {
   if(q->r==q->size-1)
   {
       printf("Queue full\n");
       return -1;
   }
    q->r++;
     q->q[q->r]=x;
     if(q->f==-1)//first element
        q->f=0;
  }

  int qdelete(struct queue* q)
  {
     int x;
    if(q->f==-1)
    {
          printf("Queue empty..\n");
          return -1;
    }
    x=q->q[q->f];
    if(q->f==q->r)//only one element
     q->f=q->r=-1;
    else
      q->f++;
    return x;
  }

  void display(struct queue q)
  {
    int i;
    if(q.f==-1)
      printf("Queue empty\n");
    else
      for(i=q.f;i<=q.r;i++)
        printf("%d ",q.q[i]);
  }  




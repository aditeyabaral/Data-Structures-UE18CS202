#include<stdio.h>
#include<stdlib.h>
struct pqueue
{
  int pty;
  int data;
  
};
void pqinsert(int,int,struct pqueue*,int*);
struct pqueue pqdelete(struct pqueue*,int*);
void qdisplay(struct pqueue*,int);
int main()
{
  int k,ch,pty,x;
  struct pqueue pq[100];
  
  struct pqueue temp;
  int count=0;
  while(1)
  {
    qdisplay(pq,count);
    printf("\n1..insert");
    printf("\n2..remove");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the priority..");
              
              scanf("%d",&pty);
              printf("Enter the value");
              scanf("%d",&x);
              pqinsert(x,pty,pq,&count);
              
               break;
      case 2:temp=pqdelete(pq,&count);
              if(temp.data>0)
              {
                printf("deleted element:- data=%d",temp.data);
                printf("   priority=%d\n",temp.pty);
               }
              break;
        case 4:exit(0); 
   }
  }
 }

  struct pqueue pqdelete(struct pqueue *pq,int *count)
  {
   int i;
   struct pqueue key;
   if(*count==0)
   {
      key.data=0;
      key.pty=-1;
    }
    else
    {
    key=pq[0];
    for(i=1;i<=*count-1;i++)
      pq[i-1]=pq[i];
    (*count)--;
    }
   return key;
  }


 void pqinsert(int x,int pty,struct pqueue *pq,int *count)
 {
   int j;
   struct pqueue key;
   key.data=x;
   key.pty=pty;

   //pq[*count]=key;
   j=*count-1;

   while((j>=0)&&(pq[j].pty<key.pty))
   {
      pq[j+1]=pq[j];
      j--;
   }
   pq[j+1]=key;
   (*count)++;
 }


void qdisplay(struct pqueue *q, int count)
  {
    int i;
    if(count==0)
     printf("Empty Queue");
   else
   {
    for(i=0;i<count;i++)
    {
      printf("\ndata = %d",q[i].data);
      printf("  pty=%d",q[i].pty);
      printf("\n");
    }  
  }
 }


   









   


   

   
  
    
    




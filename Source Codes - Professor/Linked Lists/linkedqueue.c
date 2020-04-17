//PROGRAM TO IMPLEMENT QUEUES USING A LINKED LIST
#include<stdlib.h>
#include<stdio.h>
struct node
{
  int data;
  struct node *next;
};
void qinsert(int, struct node **,struct node **);
int qdelete(struct node **,struct node **);
void qdisplay(struct node*,struct node*);
main()
{
  int k,x,ch;
  struct node *front,*rear;
  front=rear=NULL;

  
  while(1)
  {
    qdisplay(front,rear);
    printf("\n1..insert");
    printf("\n2..remove");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              qinsert(x,&front,&rear);
              
               break;
       case 2:k=qdelete(&front,&rear);
              break;
        case 4:exit(0); 
   }
  }
 }

    void qinsert(int x, struct node **f, struct node **r)
    {
      struct node *temp;
      
      temp=(struct node*)malloc(sizeof(struct node));
      temp->data=x;
      temp->next=NULL;
 
       //if this is the first node
      if(*f==NULL)
        *f=*r=temp;
      else //insert at the end
         {
           (*r)->next=temp;
            *r=temp;
          }
     }

    int qdelete(struct node **f, struct node **r)
    {
         struct node *q;
         int x;
         q=*f;
         if(q==NULL)
          {
           printf("Empty queue\n");
           return -1;
          }
          else
          {
            x=q->data;
            if(*f==*r) //only one node
              *f=*r=NULL;
            else
              *f=q->next;
            free(q);
            return x;
           }
       }
   

    void qdisplay(struct node *f, struct node *r)
     {
        if(f==NULL)
          printf("Queue Empty\n");
      else
       {
        while(f!=r)
        {
          printf("%d-> ",f->data);
          f=f->next;
        }
      printf("%d-> ",f->data);
      }
    } 
    

        
          







 
    


   
     









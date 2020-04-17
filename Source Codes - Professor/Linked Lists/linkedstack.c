#include<stdlib.h>
#include<stdio.h>
struct node
{
  int data;
  struct node *next;
 };
 void push(int,struct node **);
 int pop(struct node **);
 void display(struct node *);
 main()
{
  
  struct node *top;
  int ch,k,x;

  top=NULL;
  
  while(1)
  {
    display(top);
    printf("\n1..push");
    printf("\n2..pop");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              push(x,&top);
              break;
       case 2:k=pop(&top);
              if(k>=0)
                printf("element popped=%d\n",k);
              break;
        case 4:exit(0); 
   }
  }
 }

    void push(int x, struct node **p)
    {      
           struct node *temp;
           temp=(struct node*)malloc(sizeof(struct node));
           temp->data=x;
           temp->next=*p;
           *p=temp;
     }

     int pop(struct node **p)
     {
          int x;
         struct node *q;
         if(*p==NULL)
          {
            printf("Empty Stack\n");
             return -1;
           }
          else
           {
              q=*p;
               x=q->data;
              *p=q->next;
              free(q);
               return(x);
            }
      }


      

     void display(struct node *p)
     {
         if(p==NULL)
           printf("Empty Stack\n");
         else
          {
            while(p!=NULL)
            {
              printf("%d->",p->data);
              p=p->next;
             }
           }
      }
     

   


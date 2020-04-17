#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
 };
struct stack
{
  struct node *top;
};
 void push(int,struct stack *);
 int pop(struct stack *);
 void display(struct stack);
 main()
{
  
  struct stack s;
  int ch,k,x;

  s.top=NULL;
  
  while(1)
  {
    display(s);
    printf("\n1..push");
    printf("\n2..pop");
    printf("\n3..display");
    printf("\n4..EXIT");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:printf("Enter the value..");
              scanf("%d",&x);
              push(x,&s);
              break;
       case 2:k=pop(&s);
              if(k>=0)
                printf("element popped=%d\n",k);
              break;
        case 4:exit(0); 
   }
  }
 }

    void push(int x, struct stack *p)
    {      
           struct node *temp;
           temp=(struct node*)malloc(sizeof(struct node));
           temp->data=x;
           temp->next=p->top;
           p->top=temp;
     }

     int pop(struct stack *p)
     {
          int x;
         struct node *q;
         if(p->top==NULL)
          {
            printf("Empty Stack\n");
             return -1;
           }
          else
           {
              q=p->top;
              x=q->data;
              p->top=q->next;
              free(q);
               return(x);
            }
      }

     

     void display(struct stack p)
     {
          struct node *q;
         if(p.top==NULL)
           printf("Empty Stack\n");
         else
          {
            q=p.top;
            while(q!=NULL)
            {
              printf("%d->",q->data);
              q=q->next;
             }
           }
      }
     

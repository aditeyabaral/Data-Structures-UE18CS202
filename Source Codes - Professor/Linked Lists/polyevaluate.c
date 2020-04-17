//program to evaluate a polynomial implemented as a linked list
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 struct node
 {
  int coeff;
  int px;
  int py;
  struct node *next;
 };
  void insert_tail(int,int,int,struct node**); 
  void display(struct node *);
  int polyevaluate(struct node *);
 main()
 {
  struct node *first;
  
  first = NULL;
  int cf,px,py,result;
  while(1)
  {
      printf("\nEnter the coefficient..");
      scanf("%d",&cf);
      if(cf==0)
        break;
      printf("\nEnter the power of x..");
      scanf("%d",&px);
      printf("\nEnter the power of y...");
      scanf("%d",&py);
      insert_tail(cf,px,py,&first);      
   } 
   printf("\nThe polynomial created...\n");
    display(first);
   printf("\nEvaluating the polynomial..\n");
   result=polyevaluate(first);
   printf("Result=%d",result);
  }

   int polyevaluate(struct node *p)
   {
     int x,y,sum;
     printf("\nEnter the value of x and y..");
     scanf("%d %d",&x,&y);
     sum=0;
     while(p!=NULL)
     {
       sum=sum+(p->coeff*pow(x,p->px)*pow(y,p->py));
       p=p->next;
     }
    return sum;
 }
    
   void display(struct node *q)
    {
      while(q!=NULL)
      {
         if(q->coeff>0)
          printf("+%d",q->coeff);
         else
          printf("%d",q->coeff);
         if(q->px>0)
         {
           if(q->px==1)
             printf("X");
           else
             printf("X^%d",q->px);;
          }
          if(q->py>0)
          {
           if(q->py==1)
            printf("Y");
           else
            printf("Y^%d",q->py);
          }
         q=q->next;
       }
     }

    

    void insert_tail(int cf,int px,int py, struct node **p)
    {
      struct node *q,*temp;
      temp=(struct node*)malloc(sizeof(struct node));
      temp->coeff=cf;
      temp->px=px;
      temp->py=py;
      temp->next=NULL;

      q=*p;
      if(q==NULL)//if it is the first node
        *p=temp;
      else
       {
        while(q->next!=NULL)//go to the last node
          q=q->next;
        q->next=temp;
      } 
    }     
    
          
  

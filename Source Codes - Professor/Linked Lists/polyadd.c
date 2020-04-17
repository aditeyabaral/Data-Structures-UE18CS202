//program to add two polynomials implemented as
//a singly linked lists
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 struct node
 {
  int coeff;
  int px;
  int py;
  int flag;
  struct node *next;
 };
  void createpoly(struct node **);
  void insert_tail(int,int,int,struct node**); 
  void display(struct node*);
  void polyadd(struct node*,struct node*, struct node**);
 main()
 {
  struct node *first,*second,*third;
  
  first = NULL;
  second=NULL;
  third=NULL;
  int cf,px,py,result;

  printf("\nCreating first polynomial..\n");
  createpoly(&first);
  printf("\nCreating the second polynomial..\n");
  createpoly(&second);
  printf("\nAdding the two polynomials & displaying the result..\n"); 
  polyadd(first,second,&third);
  display(third);
 }

  void createpoly(struct node **p)
  {
    int cf,px,py;
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
      insert_tail(cf,px,py,p);      
   } 
  
    printf("\nThe polynomial created...\n");
    display(*p);
   }  
  
   void display(struct node *q)
    {
      while(q!=NULL)
      {
         if(q->coeff>0)
          printf(" +%d ",q->coeff);
         else
          printf(" %d ",q->coeff);
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
      temp->flag=1;
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
    
    void polyadd(struct node *p,struct node *q,struct node **t)
    {
      int x1,y1,cf,c1,x2,y2,c2;
      struct node *q1;
      while(p!=NULL)
      {
        c1=p->coeff;
        x1=p->px; 
        y1=p->py;
        q1=q;
        while(q1!=NULL)
        {
          c2=q1->coeff;
          x2=q1->px;
          y2=q1->py;
          if((x1==x2)&&(y1==y2))
             break;
          q1=q1->next;
         }
         if(q1!=NULL)//still in mid of second poly and found the powers equal
         {
          cf=c1+c2;//add the coefficient
          q1->flag=0;
           if(cf!=0)
             insert_tail(cf,x1,y1,t);//add the sum coeff to the poly
          }
          else
             insert_tail(c1,x1,y1,t);//add the first term to poly;
          p=p->next;
      }
    
      q1=q;
       while(q1!=NULL)
       {
           if(q1->flag==1)
              insert_tail(q1->coeff,q1->px,q1->py,t);
            q1=q1->next;
        }
    }

      
   

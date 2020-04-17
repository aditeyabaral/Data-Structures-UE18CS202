//implementation of Lists using Arrays
#include<stdio.h>
#include<stdlib.h>

struct LIST
{
  int *first;
  int count;
};

int main()
{
  struct LIST list;
  int ch,x,y;
  void insert_tail(struct LIST*, int);
  void insert_head(struct LIST*, int);
  void display(struct LIST);  
  void delete_element(struct LIST*,int);  
  /*void delete_pos(struct node **,int);  
  void reverse(struct node **);
  void insert_pos(struct node **, int,int);*/
  
 list.first=(int*)malloc(100*sizeof(int));

 list.count=0;

  while(1)
  {
    display(list);
    printf("\n1..Insert tail\n");
    printf("2..Insert head\n");
    printf("3..Display\n");
    printf("4..delete node\n");
    scanf("%d",&ch);

    switch(ch)
    {
       case 1:printf("Enter the number\n");
              scanf("%d",&x);
              insert_tail(&list,x);
              break;
       case 2:printf("Enter the number\n");
              scanf("%d",&x);
              insert_head(&list,x);
              break;
        case 3: display(list);
              break;
        case 4:printf("Enter the value of node to be deleted\n");
              scanf("%d",&x);
              delete_element(&list,x);
              break;

       
  }
 }
}

 void insert_tail(struct LIST *l, int x)
 {
   l->first[l->count]=x;
   l->count++;
 }



 void insert_head(struct LIST *l, int x)
 {
   int i;
   for(i=l->count-1;i>=0;i--)
       l->first[i+1]=l->first[i];
     l->first[0]=x;
     l->count++;
  }
  
void display(struct LIST l)
{
  int i;
  for (i=0;i<l.count;i++)
    printf("%d ",l.first[i]);
}

void delete_element(struct LIST *l, int x)
{
 int i,k;
 for(i=0;i<l->count;i++)
 {
   if(l->first[i]==x)
   {
    printf("Element found and deleted\n");
    for(k=i+1;k<l->count;k++)
      l->first[k-1]=l->first[k];
    l->count--;
    return;
   }
  }
  printf("Element not found\n");
  return;
 }
    


  

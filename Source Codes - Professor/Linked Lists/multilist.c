#include<stdio.h>
#include<stdlib.h>
struct col_node {
	int col;
	int data;
	struct col_node *next_col;
};

struct row_node {
	int row;
	struct col_node *next_col;
	struct row_node *next_row;
};
struct row_node *create_rows(int);
void insert_list(struct row_node*, int,int,int);
void display(struct row_node*);
int main()
{
  int a[10][10];
  int i,j,row,col;
  struct row_node *first;
  first=NULL;
  printf("Enter the row and cols..\n");
  scanf("%d %d",&row, &col);

  
  printf("Enter the data for the matrix..");
  for(i=0;i<row;i++)
  {
     for(j=0;j<col;j++)
      scanf("%d",&a[i][j]);
  }
  //storing the matrix as a multi list...;
  
  first=create_rows(row);
  
  for(i=0;i<row;i++)
  {  
     for(j=0;j<col;j++)
       if(a[i][j]!=0)
       
          insert_list(first,i,j,a[i][j]);
  }
  //displaying the matrix as a list

  display(first);
 }


  struct row_node* create_rows(int r)
  {
   struct row_node *p,*q;
   struct row_node *temp;

   int i;
   p=NULL;
   q=NULL;
   for(i=0;i<r;i++)
   {
    temp=malloc(sizeof(struct row_node));
    temp->row=i;
    temp->next_row=NULL;
    temp->next_col=NULL;

    if (p==NULL)//first node
    {
      p=temp;
      q=temp;
     }
     else
     {
      q->next_row=temp;
      q=temp;
     }
   }
   return p;
 }

  void insert_list(struct row_node *p,int row, int col, int x)
  {
    struct col_node *q,*prev,*temp;
    int i,j;
    i=0;
    j=0;
    while(i<row)
    {
      p=p->next_row;
      i++;
     }
    
    temp=malloc(sizeof(struct col_node));
    temp->col=col;
    temp->data=x;
    temp->next_col=NULL;

    q=p->next_col;
    if(q==NULL)
     p->next_col=temp;
   else
   {
    while(q->next_col!=NULL)
     q=q->next_col;
    q->next_col=temp;
   }
}
 

  void  display(struct row_node *p)
  {
    struct col_node *q;
    printf("\n");
    while(p!=NULL)
    {
      printf("%d ->",p->row);
      q=p->next_col;
      while(q!=NULL)
      {
       printf("%d,",q->col);
       printf("%d -> ",q->data);
       q=q->next_col;
      }
     p=p->next_row;
     printf("\n");
    }
  }




  

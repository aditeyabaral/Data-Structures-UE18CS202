//program for iterative inorder traversal
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};
void insert(struct tnode**, int);
void inorder(struct tnode*);
void push(struct tnode*);
struct tnode *pop();
int isempty();
struct tnode *stk[100];//stack
int top;

int main()
{
 int num,r,m,k;
 struct tnode *root;
 root=NULL;
 while(1)
 {

   printf("Enter the element");
   scanf("%d",&num);
   if(num==0)
     break;
   insert(&root,num);
   
 }
 printf("Inorder traversal of the tree..\n");
 inorder(root);
 }


 void inorder(struct tnode* t)
 {
   top=-1;
   while(t!=NULL)
   {
     push(t);
     t=t->left;
   }

  while(!isempty())
  {
    t=pop();
    printf("%d ",t->data);   
    if(t->right!=NULL)
    {
      t=t->right;
      while(t!=NULL)
      {
       push(t);
       t=t->left;
     }
   }
 }
}

void insert(struct tnode **t, int x)
 {
   struct tnode *temp,*prev,*curr;
   //create node

   temp=(struct tnode*)malloc(sizeof(struct tnode));
   temp->data=x;
   temp->left=temp->right=NULL;

   //if empty tree
   if(*t==NULL)
     *t=temp;//make root point to the first element
   else
   {
     prev=NULL;
     curr=*t;
     while(curr!=NULL)
     {
       prev=curr;
       if(x<curr->data)
         curr=curr->left;//move left
       else
          curr=curr->right;//move right
     }
     if(x<prev->data)
       prev->left=temp;
     else
       prev->right=temp;
    }
  }   

     
  int isempty()
  {
   if(top==-1)
      return 1;
   return 0;
  }


 void push(struct tnode* temp)
  {
    ++top;
    stk[top]=temp;
  }

  struct tnode *pop()
  {
    struct tnode *temp;
     temp=stk[top];
     --top;
    return temp;
  }


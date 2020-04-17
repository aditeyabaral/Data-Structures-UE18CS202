//program to check if two trees are identical
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
  int data;
  struct tnode *left;
  struct tnode *right;
};
struct tnode* create();
void preorder(struct tnode *);
void postorder(struct tnode*);
void inorder(struct tnode*);
int height(struct tnode *);
int leafcount(struct tnode*);
int count(struct tnode*);
int identical(struct tnode*, struct tnode*);
int  main()
{
  struct tnode *root1,*root2;
  int ch,num,k,n,result;
  root1=NULL;
  root2=NULL;
 
  printf("\nCreating first tree..\n");
  root1=create();
  printf("\nTraversal in preorder of first tree");
  preorder(root1);

  printf("\nCreating second  tree..\n");
  root2=create();
  printf("\nTraversal in preorder of second tree");
  preorder(root2);
    
  result=identical(root1,root2);
  if(result)
   printf("trees identical..\n");
 else
  printf("Not Identical\n");
}
 
struct tnode *create() 
  {
    int x;
    struct tnode* p;
    printf("\nEnter the element..");
    scanf("%d",&x);

    if(x==-1)
      return NULL;

    p=malloc(sizeof(struct tnode));
    p->data=x;

    printf("creating the left subtree of %d\n",x);
    p->left=create();  

    printf("creating the right subtree of %d\n",x);
    p->right=create();
   
    return p;
  }

 void preorder(struct tnode *t)
   {
     if(t!=NULL)
     {
        printf("%d ",t->data);
        preorder(t->left);
        preorder(t->right);
     }
  }

 int identical(struct tnode* t1, struct tnode* t2)
 {
    int l,r;
   if((t1==NULL)&&(t2==NULL))
     return 1;

   if((t1!=NULL)&&(t2!=NULL))
   {
      if(t1->data==t2->data)    
      {
        l=identical(t1->left,t2->left);
        r=identical(t1->right,t2->right);
        return(l&&r);
      }
     return 0;
   }
   return 0;
 }


























/*int identical(struct tnode *t1, struct tnode *t2)
 {
  int m,n;
  if((t1==NULL)&&(t2==NULL))
    return 1;
  if((t1!=NULL)&&(t2!=NULL))
  { 
    if(t1->data==t2->data)
    {
      m=identical(t1->left,t2->left);
      n=identical(t1->right,t2->right);
      return(m&&n);
    }
    return 0;
  }
  return 0;
 }
*/

 

 

  


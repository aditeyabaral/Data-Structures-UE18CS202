//PROGRAM TO IMPLEMENT A BINARY TREE using array
#include<stdio.h>
#include<stdlib.h>

void create(int*, int );
void preorder(int*,int);
void postorder(int*,int);
void inorder(int*,int);
int height(int*,int);
int leafcount(int *,int);
void main()
{
  int t[100],i;
  int ch,num,k,n;
  
 
  for(i=0;i<100;i++)
    t[i]=-1;
  create(t,1);//creates binary tree
  printf("\nTraversal in preorder\n");
  preorder(t,1);
  printf("\nInorder Traversal..\n");
  inorder(t,1);
  printf("\nPost order traversal..\n");
  postorder(t,1);

  printf("\nThe height of the tree..\n");
  printf("\nHeight= %d ",height(t,1));

  printf("\nThe no of leaf nodes..");
  printf("\nLeaf nodes = %d",leafcount(t,1)); 
}

  
 void preorder(int *t,int i)
 {
   if(t[i]!=-1)
   {
     printf("%d",t[i]);
     preorder(t,2*i);
     preorder(t,2*i+1);
   }
 }



 void create(int *t, int i)
 {

  int x;

  printf("\nEnter the element..\n");
  scanf("%d",&x);

  if(x==-1)
   return;

  t[i]=x;
  
  printf("\nCreating left subtree of %d\n",x);

  create(t,2*i);

  printf("\nCreating right subtree of %d\n",x);
  create(t,2*i+1);

 return;
}

void inorder(int *t, int i)
   {
     if(t[i]!=-1)
     {
        inorder(t, 2*i);
        printf("%d ",t[i]);
        inorder(t, 2*i+1);
     }
  }

void postorder(int *t, int i)
   {
     if(t[i]!=-1)
     {
        postorder(t, 2*i);
        postorder(t, 2*i+1);
        printf("%d ",t[i]);
     }
  }



  int height(int *t, int i)
  {
    int l,r;
    if(t[i]==-1)
     return -1;
    if((t[2*i]==-1) && (t[2*i+1]==-1))
      return 0;
    l=height(t,2*i);
    r=height(t,2*i+1);
    if(l>r)
     return(l+1);
   return(r+1);
 }

  int leafcount(int *t,int i)
  {
     int l,r;
    if(t[i]==-1)
      return 0;
    if((t[2*i]==-1)&&(t[2*i+1]==-1))
      return 1;
    l=leafcount(t,2*i);//find leaf nodes in left subtree
    r=leafcount(t,2*i+1);//find leaf nodes in right subtree
    return(l+r);
  }
 


























 /* void create(int *t ,int i) 
  {
    int x;
    printf("\nEnter the element..");
    scanf("%d",&x);

    if(x==-1)
      return ;

    t[i]=x;

    printf("creating the left subtree of %d\n",t[i]);
    create(t,2*i);  

    printf("creating the right subtree of %d\n",t[i]);
    create(t,2*i+1);
   
    return ;
  }

   void preorder(int *t, int i)
   {
     if(t[i]!=-1)
     {
        printf("%d ",t[i]);
        preorder(t, 2*i);
        preorder(t , 2*i+1);
     }
  }


 
  int height(int *t, int i)
  {
    int l,r;
    if(t[i]==-1)
      return -1;//height of empty tree is -1
    if((t[2*i]==-1)&&(t[2*i+1]==-1))//height of one node tree is 0
      return 0;
    l=height(t,2*i);//find the height of keft subtree
    r=height(t,2*i+1);//find the height of right subtree
    if(l>r)
     return (l+1);
    return (r+1);
  }

  
  int leafcount(int *t,int i)
  {
     int l,r;
    if(t[i]==-1)
      return 0;
    if((t[2*i]==-1)&&(t[2*i+1]==-1))
      return 1;
    l=leafcount(t,2*i);//find leaf nodes in left subtree
    r=leafcount(t,2*i+1);//find leaf nodes in right subtree
    return(l+r);
  }

 */

























  
















  







  




















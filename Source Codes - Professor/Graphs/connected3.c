//program to check if a digraph is strongly, weakly or not connected
 #include<stdio.h>
 int visit[100];
 void creategraph(int(*)[]);
 void dfs(int(*)[],int);
 int n;
 int strongconnect(int(*)[]);
 int weakconnect(int(*)[]);
 void remove_edge_direction(int(*)[],int(*)[]);
 int main()
 {
   int i,v,k;
   int a[100][100],b[100][100];
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph(a);
   int result=strongconnect(a);
   if(result)
    printf("Graph is strongly connected..");
   else
    {
      remove_edge_direction(a,b);
      result=weakconnect(b);
      if(result)
         printf("\nWeakly connected..");
      else
         printf("\nNot connected");
    }
 }

  void creategraph(int(*a)[100])
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d%d",&i,&j);
        if((i==0)&&(j==0))
           break;
        a[i][j]=1;
     }
  }

  int strongconnect(int (*a)[100])
  {
    int i,j;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
        visit[j]=0;
      dfs(a,i);
      for(j=1;j<=n;j++)
      {
       if(visit[j]==0)
         return 0;
      }
    }
   return 1;
 }

  void dfs(int(*a)[100], int v)
  { 
    int i;
    visit[v]=1;
     for(i=1;i<=n;i++)
     {
      if((a[v][i]==1) && (visit[i]==0))
        dfs(a,i);
     }

   }

  void remove_edge_direction(int (*a)[100],int (*b)[100])
  {
    int i,j;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
      {
       if(a[i][j]==1)
         b[i][j]=b[j][i]=1;
      }
    }
  }

  int weakconnect(int (*b)[100])
  {
    int i;
    for(i=1;i<=n;i++)
      visit[i]=0;
    dfs(b,1);
    for(i=1;i<=n;i++)
    {
      if(visit[i]==0)
         return 0;
    }
  return 1;
 }



















 
  /*void dfs(int (*a)[100],int v)
   {
     int w;
     visit[v]=1;
     for(w=1;w<=n;w++)
     {
       if((a[v][w]==1) && (visit[w]==0))
           dfs(a,w);
     }
   }

  
 int weakconnect(int (*b)[100])
 {
   int i;
   for(i=1;i<=n;i++)
     visit[i]=0;
   dfs(b,1);
   for(i=1;i<=n;i++)
   {
     if(visit[i]==0)
        return 0;
   }
   return 1;
 }

  int strongconnect(int (*a)[100])
  {
    int i,j;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
        visit[j]=0;
      dfs(a,i);
      for(j=1;j<=n;j++)
      {
        if(visit[j]==0)
         return 0;
      }
    }
   return 1;
 }
  
 void remove_edge_direction(int (*a)[100],int (*b)[100])
 {
   int i,j;
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
     {
       if(a[i][j]==1)
         b[i][j]=b[j][i]=1;
     }
  }
 }
*/

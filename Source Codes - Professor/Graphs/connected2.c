//program to check if a digraph is strongly, weakly or not connected
 #include<stdio.h>
 int visit[10];
 void creategraph();
 void dfs(int);
 int a[100][100],n;
 int b[100][100];
 int strongconnect();
 int weakconnect();
  void remove_edge_direction();
 int main()
 {
   int i,v,k;
   
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   int result=strongconnect();
   if(result)
    printf("Graph is strongly connected..");
   else
    {
      remove_edge_direction();
      result=weakconnect();
      if(result)
         printf("\nWeakly connected..");
      else
         printf("\nNot connected");
    }
 }

  void creategraph()
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

 
  void dfs1(int v)
   {
     int w;
     visit[v]=1;
     for(w=1;w<=n;w++)
     {
       if((a[v][w]==1) && (visit[w]==0))
           dfs1(w);
     }
   }

  void dfs2(int v)
   {
     int w;
     visit[v]=1;
     for(w=1;w<=n;w++)
     {
       if((b[v][w]==1) && (visit[w]==0))
           dfs2(w);
     }
   }

 int weakconnect()
 {
   int i;
   for(i=1;i<=n;i++)
     visit[i]=0;
   dfs2(1);
   for(i=1;i<=n;i++)
   {
     if(visit[i]==0)
        return 0;
   }
   return 1;
 }

  int strongconnect()
  {
    int i,j;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
        visit[j]=0;
      dfs1(i);
      for(j=1;j<=n;j++)
      {
        if(visit[j]==0)
         return 0;
      }
    }
   return 1;
 }
  
 void remove_edge_direction()
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


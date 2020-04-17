 //program to check if a graph(directed) is strongly conected using DFS
 #include<stdio.h>
 int visit[10];
 void creategraph();
 void dfs(int);
 int a[100][100],n;
 int connected();
 int main()
 {
   int i,v,k;
   
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   int result=connected();
   if(result)
    printf("Graph is connected..");
   else
    printf("Not connected..");
 
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


  void dfs(int v)
   {
     int w;
     visit[v]=1;
     for(w=1;w<=n;w++)
     {
       if((a[v][w]==1) && (visit[w]==0))
           dfs(w);
     }
   }

  int connected()
  {
   int i,j;

   for(i=1;i<=n;i++)
   {
     for(j=1;j<=n;j++)
       visit[j]=0;
     dfs(i);
     for(j=1;j<=n;j++)
     {
       if(visit[j]==0)
         return 0;
     }
  }
  return 1;
 }


  







  








  

      

     




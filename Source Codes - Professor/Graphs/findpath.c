 #include<stdio.h>
 int visit[10];
 int p[10];
 void creategraph();
 void path(int, int);
 int findpath(int,int); 
 int a[100][100],n;
 int length;
 main()
 {
   int i,v,s,d;
   printf("Enter the number of vertices..");
   scanf("%d",&n);

   creategraph();
   printf("\nTo Find Path\n");
   printf("Enter the source and destination vertices..");
   scanf("%d %d",&s,&d);
   path(s,d);
  }

  void creategraph()
  {
    int i,j;
    while(1)
    {
        printf("Enter the source and the destination vertex..");
        scanf("%d %d",&i,&j);
        if((i==-9)&&(j==-9))
           break;
        a[i][j]=1;
     }
  }

 int findpath(int s, int d)
 {
   int u;
   visit[s]=1;

   for(u=1;u<=n;u++)
   {
     if((a[s][u]==1)&&(visit[u]==0))
     {
        p[++length]=u;
        if((u==d)||findpath(u,d))
          return 1;
     }
  }
  --length;
 return 0;
}












  




 void path(int s, int d)
  {
   int i,j,t;
   length=0;

   for(i=1;i<=n;i++)
      visit[i]=0;

   p[length]=s;
  
   t=findpath(s,d);
   if(t)
   {
     printf("Path found..\n");
     printf("the length= %d",length);
     printf("the vertices in the path are..\n");
     for(j=0;j<=length;j++)
       printf("%d ",p[j]);
    }
    else
      printf("\nPath not found..\n");
 }
      
 






















  
























 






   

























/*
   

   int findpath(int s,int d)
   {
     int u;
     visit[s]=1;
     for(u=1;u<=n;u++)
     {
        if((a[s][u]==1)&&(visit[u]==0))
        {
          path[++length]=u;
          if((u==d)||findpath(u,d))
             return 1;
          length--;
        }
     }
     return 0;
   }
         
     */     





  













/* void Findpath(int s, int d)
  {
   int i ,t;
    for(i=1;i<=n;i++)
        visit[i]=0;
    t=findpath(s,d);
    if(t)
    {
      printf("Path found");
      printf("The vertices in the path are.");
      for(i=1;i<=length;i++)
       printf("%d ",path[i]);
    }
    else
      printf("path not found");
   }

   int findpath(int s , int d)
   {
     int u;
     visit[s]=1;
     for(u=1;u<=n;++u)
     {
        if((a[s][u]==1)&&(visit[u]==0))  
         {
            path[++length]=u;
            printf("%d \n",path[length]);
            if((u==d)||findpath(u,d))
              return 1;            
            length--;
          }
      }
     return 0;
   }*/

  

  /* void dfs(int v)
   {
     int w;
     visit[v]=1;
     printf("%d ",v);
     for(w=1;w<=n;w++)
     {
       if((a[v][w]==1) && (visit[w]==0))
           dfs(w);
     }
   }
        
   void bfs(int v)
   {
     int i,w,u;    
     f=r=-1;
     qinsert(v);
     while(!qempty())
     {
       w=qdelete();
       for(u=1;u<=n;u++)
       {
          if((a[w][u]==1) && (visit[u]==0))
           {
               visit[u]=1;
               printf("%d ",u);
               qinsert(u);
            }
        }
    }
 }
    qinsert(int x)
    {
       r++;
       q[r]=x;
       if(f==-1)
        f=0;
    }

    int qdelete()
    {
      int x;
      x=q[f];
      if(f==r)
        f=r=-1;
      else
        f++;
      return x;
    }   
               
    int qempty()
    {
      if(f==-1)
        return 1;
      return 0;
     }     
     
    */ 

     




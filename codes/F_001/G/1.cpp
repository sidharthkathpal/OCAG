/*
Roll No: 101410052
Name: Sidharth Kathpal
Group: CML-3
Question 17:    
Write a program to find shortest path from a given source to all the approachable nodes (Single source shortest path Dijkstra’s algorithm).
*/
#include<stdio.h>
void dijkstra(int n,int v,int cost[10][10],int dist[])				//the function for the application of dijsktra
{
 	int i,u,count,w,flag[10],min;
 	for(i=1;i<=n;i++)												
 	{
  		flag[i]=0;
		dist[i]=cost[v][i];
 	}
	count=2;
 	while(count<=n)
 	{
  		min=99;
  		for(w=1;w<=n;w++)
  		{
  			if(dist[w]<min && !flag[w])
  			{
    			min=dist[w];
				u=w;
			}
		}		
  		flag[u]=1;
  		count++;
  		for(w=1;w<=n;w++)
  		{
   			if((dist[u]+cost[u][w]<dist[w]) && !flag[w])
    			dist[w]=dist[u]+cost[u][w];
 		}
	}
}
 
int main()
{
	int n,v,i,j,cost[10][10],dist[10];
	printf("\nEnter the number of nodes:");									//enter the number of nodes
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");								//enter the edges and there costs
	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++) 
	{
	  	printf("a[%d][%d]",i,j);
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		    cost[i][j]=999;
	}
 	printf("\nEnter the source matrix:");
 	scanf("%d",&v);
 	dijkstra(n,v,cost,dist);
 	printf("\nShortest path:\n");
 	for(i=1;i<=n;i++)
  		if(i!=v)
   			printf("%d->%d,cost=%d\n",v,i,dist[i]);
	return 0;
}

/*11. Design, Develop and implement a program in c for the following
operation on Grapg(G) of cities

a. Create a Graph of N cities using Adjancy matrix
b. Print all the nodes reachable from a given statring node in a digraph uisng
DFS/ BFS method    */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void bfs(int n,int source,int a[][SIZE],int s[]);
void main()
{
	int n;
	int a[SIZE][SIZE];
	int source;
	int visited[SIZE];
	int i,j;

	printf("Enter the No of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("The adjacency matrix is \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",a[i][j]);
		}
	}
	printf(" Enter the source\n");
	scanf("%d",&source);

	for(i=0;i<n;i++)
		visited[i]=0;
	bfs(n,source,a,visited);
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
			printf("%d\t is not reachable",i);
		else
			printf("%d\t is reachable\n",i);
	}
}

void bfs(int n, int source, int a[][SIZE],int visited[])
{
	 int q[SIZE];
	 int f=0;
	 int r=0;
	 int u,v;
	 visited[source]=1;
	 q[r]=source;
	 while(f<=r)
	 {
		u=q[f++];
		for(v=0;v<n;v++)
		{
			if(a[u][v]==1 && visited[v]==0)
			{
				q[++r]=v;
				visited[v]=1;
			}
		}
	 }
}
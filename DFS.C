Depth First search:
	Depth First search us one of the graph related algorithm based on
decrese and conquer problem solving technique.
-> Main aim of this algorithm is "visiting vertices and traversing the edges
of a graph."
-> Working procedure:
	"Depth first means to serch deeper in the graph". Depth first serach
	statrs visiting the vertices of a graph at an arbitrary vertex by
	marking it has been visited.
-> The following graph clearly explians the working of DFS.

		A                       A->B
					A->C
	   B        C                   B->D
					C->E
					D->F
	   D        E                   E->F
					F->G
					G->D
	       F                        G->E


	       G

Step 1:   consider A as source vertex.

		A
Setp2:
	 A->B

step3:
	 A->B
	 B->D

step4:
	A->B
	B->D
	D->F
step5:

	A->B
	B->D
	D->F
	F->G

step6:
	A->B
	B->D
	D->F
	F->G
	G->E

step7:
	A->B
	B->D
	D->F
	F->G
	G->E
	A->C

Algotihm: DFS(n,a[][],u,t[][],s[])
//purpose: Traverse agraph from given source node
//input: A[][] adjacency matrix
	 //n  no of nodes in a graph
	 //u sourcce vertex
	 //s[]  to keep track of visisted vertces.

//ouput:
	t[][] // spanning tree

	s[u]=1;
	for(v=0;v<n-1;v++)
	{            a  b
		if(a[u][v]==1 && s[v]==0)
		{
			t[k][0]=u;
			t[k][1]=v;
			k++;
			dfs(n,a,v,t,s);
		}
	}


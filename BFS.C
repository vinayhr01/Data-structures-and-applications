BFS : Bredth First Search is one of the graph related algorithm based on
decrese and conquer problem solving technique.

-> Main aim of this algotihm is " visitng  vertives and traversing edges"
-> the ouput of the BFS will be spanning  tree.

Working procedure:
	" Breadth First search starts from the source node and visits all
	vertices of the source node ,we need to visit all the adjecnet
	vertices in each step."

-> Consider the below given graph:
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

    A  B  C  D  E  F  G
A   0  1  1  0  0  0  0

B   0  0  0  1  0  0  0

C   0  0  0  0  1  0  0

D   0  0  0  0  0  1  0

E   0  0  0  0  0  1  0

F   0  0  0  0  0  0  1

G   0  0  0  1  1  0  0

Array s keep track of visited vertices
   A   B   C  D  E  F  G
s.................................
   1   1   1  1  1  1  1              Nothing is visited.
 .................................

Queue:
	f
    0   1   2    3  4  5
  ..................................
Q       B   C
  .................................
	r


 while(f<=r)
	u=q[f]    // U=A
	f++
	for v=1 to n-1
		if(a[u][v]==1 & s[v]==0)
			s[v]=1;                 A->B
			q[++r]=v;               A->C
			t[k][0]=u;
			t[k][1]=v;
			k=k+1;


step1: visit the source
		A

step2:
		A

	     B      C          A->B
			       A->C

step3:
		A

	     B     C              A-> B
				  A-> C
	     D                    B->D

step4: Consider the source as C
		A

	     B     C              A-> B
				  A-> C
	     D     E              B-> D
				  C-> E
step5: CConsider source as D

		A

	     B     C              A-> B
				  A-> C
	     D     E              B-> D
				  C-> E
	       F                  D-> F
    Note: Next source is E but only F is reachable from E, F is already
    visited we need to make source as F

step 6:cosider source as F

		A

	     B     C              A-> B
				  A-> C
	     D     E              B-> D
				  C-> E
		F                 D-> F

		G                 F->G




Algorithm: BFS(a[][],n,source,t[][])
//purpose : Traverse the graph from source node
//input:
	//a[][] adjacency matrix
	//n no of nodes in a graph
	//s from where the traversal has to be started

//ouput:
	t[][] //holds the edges of the spanning tree.

   while(f<=r)
	u=q[f]    // U=A
	f++
	for v=1 to n-1
		if(a[u][v]==1 & s[v]==0)
			s[v]=1;                 A->B
			q[++r]=v;               A->C
			t[k][0]=u;
			t[k][1]=v;
			k=k+1;



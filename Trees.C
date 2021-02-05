Module-4
1. Definition of Binary Tree

2. properties of Binary Tree

3. Array and Linked List Represetation of Binary Tree.

Note: Tree is a non linear data structure.

(2 marks question )
Definition of Tree: A tree is a finite  set of one or more nodes that shows
parent child relation ship such that

1. There is a special node called root node.
2. The  remaining nodes are partitioned into disjoint subsets T1,T2,T3....Tn
n>=0 where T1,T2,T3...Tn which are all chidren of root node are also called
as subtrees.

Binary Tree Representation: A binary tree represetation is also called as
left child-right child trree representation or degree two representation.

Definition:
	A binary tree is a tree which has finite set of nodes that is either
empty or consist of  a root adn two sub trees called left sub tree and right
sub tree.
-> A binary tree can be partitioned into three subgroups namele

  1. root  ->The first node of the tree
  2. Left-sub tree -> The tree which is connected to left of root.
  3. Right-Sub tree -> The tree which is connected to rgiht of root.
		    ......................
	     < -   |      |   100  |      | ->
		    ......................
 address of left sub tree                   Address of right sub tree


 possible cases: (As shown in the paint)






 Types of Binary tree
 1. Strictly Binary tree
 2. skewed binary tree
 3. Complete Binary tree



 Definition of Strictly Binary tree: A  strictly binary tree with n levls
 always  contanis 2n-1 nodes. If every non -leaf node in binary tree has
 non empty left and right subtrees.

 -



 Linked List and  Array represenatation  of Binary Tree:(5marks)

 Linked List Representation: In linked list representation a node of a tree
 consists of 3 fields
 1. info
 2. llink
 3. rlink
		   root
	      ..............
	      |   | A |   |
	      .............

 .............           ..............
 |   | B  |   |          |   | C   |    |
 .............           ..............

 Binary Tree Traversals: Traversal means visiting the nodes of tree.
 There are 3 types of traversals

 Note: To traverse a tree we use recursion.
 1. inorder
 2. preorder
 3. postorder traversal

Preoder Traversal(RN L R : The preoder traversal of a binary tree can be recusively
defined as follows.
1. Process the root Node RN (visit)
2. Traverse the Left Subtree L
3. Traverse the Right Subtree R

			......
			|  A |
		       .......
		       .       .
		.......         .. .....
		|  B |              | C |
		......              .....
	       .	             .    .
	       .		    .      .
	   .......              .....        .....
	   | D  |              | E |        | F |
	   ......              .....        .....
	 .	.		  .
       .	 .		  .
 .....             .  .....        .....
 | G |               | H |           | I |
 .....               .....           .....



  PRE ORDER TRAVERSAL : A B  D  G H C E I F

	if(root==NULL)
		return;
	printf("%d",root->info);



 Note: B does not have right child
       E does not have left child
       F is leaf node .
Inorder Traversal ( L  RN  R) : The Inorder travesal of a binary tree
can be recursively defined as follows.
1.  Traverse left subtree
2.  Proccess the root Node(visit)
3.  Traverse the Right Subtree.

Postorder Traversal(L R RN : The postorder traversal of a binary tree
can be recursively defined as follows.
1.  Traverse left subtree
2.  Traverse right subtree
3.  process root NODE  (visit)



























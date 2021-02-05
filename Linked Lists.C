Module 3:
Linked List:  A linked list is an ordered collection of Zero or More
	      nodes, where each node consists of two fields.
  -> Linked list is linear data structure.
  -> Representation of node and collection of nodes is given below.

   case 0:Representaion of node :
		.......................
		|          |           |
		|    10	   |  Null     |
		.......................
		    info       link
	  info filed consists of data
	  link filed holds the address of next node, if next node is not
  aviailable link field is filled with null.

  case 1: Representaion of 4 nodes in a linked list.


	  root
	 ..........    ..........    ...........    ..........
	 | 5  | --|--->| 10 | --|--->|15  |  --|--->| 20 |Null|
	 ..........    ..........    ...........    ...........
	 info link      info link    info  link       info link

  Note: First is node is called as root node

Classifictiaon of linked lists:
	Classifincation of linked list si given below.
	1. singly Liked List
	2. Doubly Linked List
	3. Cicular single Linked List
	4. Circular Doubly Linked List.

Singly Linked List:
	Linked List is a collection of nodes connected in linear order.
-> Each node consists of two fields.
 -> Info field used to store data.
 -> Linked field is used to store the addres of next node.
 -> These two fields belongs to different data type. So there is nedd of structure to construct
 a node.
 -> We make use of self -referential structure.
		   .................

   struct  node
   {
	int info;
	struct node *link; // if the member having same data type of
			   //  structure  forms self-refertial struture
   };
   typedef struct node *NODE;

 -> Pictorial represenatiion of various stages of the linked list id
   given below.


 Note: root always holds the addres of first node.

      case 0: Linked list empty
		root==NULL  // Linked List is empty

      case 1: Only one node is there in the linked list

		      root
		     .............
		     | 10 |  Null|
		     .............
		    info       link


	     Note: when link field of the root node is null we can say
		   only one node is there in the linked list.

      case 2:More than one node is there in the linked list

	    root
	 ..........    ..........    ...........    ..........
	 | 5  | --|--->| 10 | --|--->|15  |  --|--->| 20 |Null|
	 ..........    ..........    ...........    ...........
	 info link      info link    info  link       info link

Operation on singly Linked List: Various operations on singly
				 linked list are listed  below.

 1. insert a node at the front end
 2. Delete the node from the front end
 3. Diplay singly linked list.
 4. Insert the node from rear end.
 5. Delete the Node from rear end.
 6. Implemeantion of stacks using sigly linked list
 7. Implemeantion of Queues using sigly linked list
 8. Creating an ordered linked list.
 9. Deletign a node whose key(info) is given.
 10. Delete a node when a position is given.
 11. Concatination of tow linked list.
 12. search for an item whose key is given(info is given)
 13. Insert a node at the specified position
 14. Assignment: Implementataion of priorit queues using sll.(single linked
 list).


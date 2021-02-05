/*Implementation of sll with following operrations.

Creation of structre:
	struct node
	{
		int info;
		struct node *link;
	};
	typedef struct node *NODE;

creation of node :   The node is created using the below given code.

	NODE getnode()
	{
		NODE p;

		p=(NODE)malloc(sizeof(struct node));
		if(p==NULL)
		{
			printf("insufficient memory\n");
			exit(0);
		}
		return p;

	}


Insert a node at front end: The function insert_front() is used to insert
a node in the front of linked list.

Note: New node has to be created.  The function getnode is used to create
a new node and name of the new node is temp.

	case 0: Linked list empty
				      info link
				     ............
		root==NULL     temp  | 5  | NULL|    /
				     ............
      case 1: Only one node is there in the linked list

	     temp	      root
	 ..........	  .............
	|  5 |  --|------>| 10 |  Null|
	  ..........      .............
       info   link	  info       link


	     Note: when link field of the root node is null we can say
		   only one node is there in the linked list.

      case 2:More than one node is there in the linked list

    temp	  root
 .........      ..........    ..........    ...........    ..........
 | 2 | --|----->| 5  | --|--->| 10 | --|--->|15  |  --|--->| 20 |Null|
 ..........     ..........    ..........    ...........    ...........
 info  link	 info link      info link    info  link       info link


	 Note: always we need to keep track of address of first node,
	 and every function in linked list should return address of first/
	 root node.
NODE  insert_front(NODE root,int item)
{
	NODE temp;
	temp=getnode();
	temp->info= item;
	temp->link= root;
	return temp; // return  address of first node.
}

Delete a node from front end: The function delete_front() is used to delete
the node from front end.

	case 0: Linked list empty
		root==NULL  // Linked List is empty

      case 1: Only one node is there in the linked list

		      root
		     .............
		     | 10 |  Null|
		     .............
		    info       link



	     Note: After deleting this node program should return NULL

      case 2:More than one node is there in the linked list

temp (deleted)            root
	 ..........    ..........    ...........    ..........
	 | 5  | --|    | 10 | --|--->|15  |  --|--->| 20 |Null|
	 ..........    ..........    ...........    ...........
	 info link      info link    info  link       info link

	 Note:The node which gets deleted i shoud make it as temp

NODE delete_front(NODE root)
{
	NODE temp;
	if(root==NULL)
	{
		printf("Linked is empty\n");
		return root;
	}
	temp=root;
	root=root->link;
	temp->link=NULL;
	free(temp);
	return root;

}

Display function: The function display() is used to display the conents of
linked list.

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

	  root           		                        tmp==NULL
	 ..........    ..........    ...........    ..........
	 | 5  | --|--->| 10 | --|--->|15  |  --|--->| 20 |Null|
	 ..........    ..........    ...........    ...........
	 info link      info link    info  link       info link

NODE display(NODE root)
{

	NODE temp;
	if(root==NULL)
	{
		printf("Linked List is empty\n");
		return root;
	}
	temp=root;
	while(temp!=NULL)
	{
		printf("%d",temp->info);   5  10  15  20
		temp=temp->link;
	}
	return root;


}
The function to insert the node from rear end: The function insert_rear() is
used to insert the node at rear end of the linked list.

->since it is insert operation careation of the new node is reqired.

->  The function must identify the last node, the new node should insert
     after teh last node.

-> The function must return address of the root node.

     case 0:    Linked list empty
		root==NULL  // Linked List is empty

		temp
		................
		|  5  | NUll    |
		................
		 info     link

      case 1: Only one node is there in the linked list

		      root
		     .............
		     | 10 |  Null|
		     .............
		    info       link


	     Note: when link field of the root node is null we can say
		   only one node is there in the linked list.

      case 2:More than one node is there in the linked list

	  root                                         last        temp
	 ..........    ..........    ...........    ..........    .........
	 | 5  | --|--->| 10 | --|--->|15  |  --|--->| 20 |--|---> |25 |NUll|
	 ..........    ..........    ...........    ...........    ........
	 info link      info link    info  link       info link



// The functon to delete the node from rear end.

NODE insert_rear(NODE root,int item)
{
	NODE temp;
	NODE last;

	temp=getnode();
	temp->info=item;
	temp->link= NULL;

	if(root==NULL)
	{
	      return temp;
	}
	last=root;
	while(last->link!=NULL)
	{
	       last=last->link;
	}
	//Note: When pointer last is really pointing to last node of llist
	last->link=temp;
	return root;

}
The Function delete_rear(): The function delete_rear() is used to delete a
node from the rear end.
 -> Each deletion operation deletes one node.
 -> The funcction has to indetify last node of the linked list.
 -> Before the deletion we need to display info filed of the node which
 gets deleted.
 -> The node to be deleted, first it  should get detached from the linked list.
 ->The function free() is used to delete the node.
 -> The vaious cases are given below.

    Note: root always holds the addres of first node.

      case 0: Linked list empty
		root==NULL  // Linked List is empty

		Note: deletion is not possible

      case 1: Only one node is there in the linked list

		      root
		     .............
		     | 10 |  Null|
		     .............
		    info       link


	     Note: when link field of the root node is null we can say
		   only one node is there in the linked list.

      case 2:More than one node is there in the linked list
					prev
	 root                                         last
	 ..........    ..........    ...........    ..........
	 | 5  | --|--->| 10 | --|--->|15  | NULL|    | 20 |Null|
	 ..........    ..........    ...........    ...........
	 info link      info link    info  link       info link

 Note: In the delete_rear, we need to idetify last node as well as previous
 of last node.


NODE delete_rear(NODE root)
{

	NODE last;

	//linked list is empty

	if(root==NULL)
	{
		printf("Linked list is empty\n");
		return root;
	}

	// Only one node in the linked list
	if(root->link==NULL)
	{
	    printf("The Node deleted =%d",root->info);
	    free(root);
	    return NULL;
	}
	prev=NULL;
	last=root
	while(last->link!=NULL)
	{
		prev=last;
		last=last->link;
	}
	prev->link=NULL;
	printf("The Node deleted=%d",last->info);
	free(last);
	return root;
}
*/


#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node *NODE;



NODE getnode()
{
	NODE p;

	p=(NODE)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("insufficient memory\n");
		exit(0);
	}
	return p;

}
NODE insert_front(NODE root,int item);
NODE insert_rear(NODE root,int item);
NODE delete_front(NODE root);
NODE delete_rear(NODE root);
NODE display(NODE root);

void main()
{
	NODE root=NULL;
	int item;
	int choice;

	for(;;)
	{
		printf("1:insert_front 2:delete_front\n");
		printf("3:insert_rear  4:delete_rear\n");
		printf("5:dsiplay  6:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the item to be  inserted\n");
				scanf("%d",&item);
				root=insert_front(root,item);
				break;

			case 2: root=delete_front(root);
				break;

			case 3: printf("Enter the item to be  inserted\n");
				scanf("%d",&item);
				root=insert_rear(root,item);
				break;

			case 4: root=delete_rear(root);
				break;

			case 5: display(root);
				break;

			case 6:exit(0);
		}
	}

}

NODE insert_front(NODE root,int item)
{
	NODE temp;
	temp=getnode();
	temp->info= item;
	temp->link= root;
	return temp; // return  address of first node.
}

NODE delete_front(NODE root)
{
	NODE temp;
	if(root==NULL)
	{
		printf("Linked is empty\n");
		return root;
	}
	temp=root;
	printf("item deleted=%d",temp->info);
	root=root->link;
	temp->link=NULL;
	free(temp);
	return root;

}

NODE insert_rear(NODE root,int item)
{
	NODE temp;
	NODE last;

	temp=getnode();
	temp->info=item;
	temp->link= NULL;

	if(root==NULL)
	{
	      return temp;
	}
	last=root;
	while(last->link!=NULL)
	{
	       last=last->link;
	}
	//Note: When pointer last is really pointing to last node of llist
	last->link=temp;
	return root;

}
NODE delete_rear(NODE root)
{

	NODE last,prev;

	//linked list is empty

	if(root==NULL)
	{
		printf("Linked list is empty\n");
		return root;
	}

	// Only one node in the linked list
	if(root->link==NULL)
	{
	    printf("The Node deleted =%d",root->info);
	    free(root);
	    return NULL;
	}
	prev=NULL;
	last=root;
	while(last->link!=NULL)
	{
		prev=last;
		last=last->link;
	}
	prev->link=NULL;
	printf("The Node deleted=%d",last->info);
	free(last);
	return root;
}




NODE display(NODE root)
{

	NODE temp;
	if(root==NULL)
	{
		printf("Linked List is empty\n");
		return root;
	}
	temp=root;
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->link;
	}
	return root;


}


implementation of stacks using single linked list
Creation of structre:
	struct node
	{
		int info;
		struct node *link;
	};
	typedef struct node *NODE;

creation of node:
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

inserting a node to the stack(push operation)
->adding a node to the stack is reffered as push operation
->new node has to be created. the function getnode is used to create a new node
and name of the new node is temp.
->if there are some nodes in the list already, then we have to add the new node in the beginning
of the linked list to not violate the properties of the stack

case 0: Linked list empty
				      info link
				     ............
		root==NULL     temp  | 5  | NULL|    
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
and every function in linked list should return address of first/ root node.
NODE push(NODE root,int item)
{
	NODE temp;
	temp = getnode();
	temp->info=item;
	temp->link=root;
	printf("item pushed");
	return temp;
}

deleting a node from the stack
->deleting a node from the stack is reffered ad pop operation
->check for the underflow condition
after deleting the node, function should return null

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

NODE pop(NODE root)
{
	NODE temp;
	if(root==NULL)
	{
		printf("underflow\n");
		return root;
	}
	temp=root;
	root=root->link;
	temp->link=NULL;
	free(temp);
	printf("item poped");
	return root;

}

Display function: The function display() is used to display the contents of
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
		printf("stack is empty\n");
		return root;
	}
	temp=root;
	while(temp!=NULL)
	{
		printf("%d",temp->info);   
		temp=temp->link;
	}
	return root;
}

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

NODE push(NODE root,int item);
NODE pop(NODE root);
NODE display(NODE root);

void main()
{
	NODE root=NULL;
	int item;
	int choice;

	for(;;)
	{
		printf("1:push 2:pop 3:dsiplay 4:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the item to be  inserted\n");
				scanf("%d",&item);
				root=push(root,item);
				break;
			case 2: root=pop(root);
				break;

			case 3: display(root);
				break;

			case 4:exit(0);
		}
	}
}

NODE push(NODE root,int item)
{
	NODE temp;
	temp=getnode();
	temp->info= item;
	temp->link= root;
	printf("item pushed\n");
	return temp; 
}

NODE pop(NODE root)
{
	NODE temp;
	if(root==NULL)
	{
		printf("underflow\n");
		return root;
	}
	temp=root;
	root=root->link;
	temp->link=NULL;
	free(temp);
	printf("item poped\n");
	return root;
}

NODE display(NODE root)
{

	NODE temp;
	if(root==NULL)
	{
		printf("stack is empty\n");
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


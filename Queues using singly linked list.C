/*implementation of queue using single linked list:

Ordinary Queue:
	 f
	 0    1    2      3    4
	....................... ..
       | 5  | 10 | 15  |    |    |
	..........................
		    r
NOTE: To implement Queue using single linked list  we use
  1. insert_rear()
  2. delete_front()

In queue insertion and deletion are performed at rear end and front
end respectively.
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


insert operation
->the function insert is used to insert a node at rear end of the queue
->The function must identify the last node, the new node should insert
     after teh last node.
->The function must return address of the root node.

     case 0:    Linked list empty
		root==NULL  // Linked List is empty

		temp
		................
		|  5  | NUll    |
		................
		 info     link

      case 1: Only one node is there in the linked list

		      root           temp
		     .............     .............
		     | 10 |  --  |---->| 15  | NULL|
		     .............     ............
		    info       link      info   link


	     Note: when link field of the root node is null we can say
		   only one node is there in the linked list.

      case 2:More than one node is there in the linked list

	  root                                         last        temp
	 ..........    ..........    ...........    ..........    .........
	 | 5  | --|--->| 10 | --|--->|15  |  --|--->| 20 |--|---> |25 |NUll|
	 ..........    ..........    ...........    ...........    ........
	 info link      info link    info  link       info link


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

deletion
->deletion operation removes the element that is first inserted among
all the queue elements.
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

NODE delet(NODE root)
{
	NODE temp;
	if(root==NULL)
	{
		printf("Q underflow\n");
		return NULL;
	}
	temp=root;
	root=root->link;
	temp->link=NULL;
	free(temp);
	printf("item deleted");
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

NODE display(NODE root);
NODE insert(NODE root,int item);
NODE delet(NODE root);

void main()
{
	NODE root=NULL;
	int item;
	int choice;

	for(;;)
	{
		printf("1:insert  2:delete\n");
		printf("3:dsiplay  4:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{

			case 1: printf("Enter the item to be  inserted\n");
				scanf("%d",&item);
				root=insert(root,item);
				break;

			case 2: root=delet(root);
				break;

			case 3: display(root);
				break;

			case 4:exit(0);
		}
	}
}

NODE insert(NODE root,int item)
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
NODE delet(NODE root)
{
	NODE temp;
	if(root==NULL)
	{
		printf("Q underflow\n");
		return root;
	}
	temp=root;
	root=root->link;
	temp->link=NULL;
	free(temp);
	printf("item deleted");
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



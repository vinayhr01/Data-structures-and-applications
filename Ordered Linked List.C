/*Odered Linked List:
	Ordered linked list is one where the elements are stored in
ascending or descending order.

Ordered Linked List: Exmaple 1: (Ascending order)
.........      .........       .............      ............
 5  |          10 |              15   |            20  |
.........      .........       .............      ............

Ordered Linked List: Exmaple 2: (desecnding order)
.........      .........       .............      ............
 20  |          10 |              5   |            2  |
.........      .........       .............      ............

Not an Ordered Linked List: Exmaple 1:
.........      .........       .............      ............
 5  |          28 |              15   |            20  |
.........      .........       .............      ............


Consider example1: In this exmple user would like to insert the element
 info 18                                   ...........
					      18 |
					    ............
.........      .........       .............      ............
 5  |            10 |              15|             20  |
.........      .........       .............      ............

-> The info field of the new node to be inserted is used  as key  to identify
the order position of new node.

->The info of the new node is compared with info other nodes present in the
linked list to find the position of new node.
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
NODE insert_order(NODE root,int item);
NODE display(NODE root);

void main()
{
	NODE root=NULL;
	int item;
	int choice;

	for(;;)
	{

		printf("1:insert_order  2:dsiplay 3:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the item to be  inserted\n");
				scanf("%d",&item);
				root=insert_order(root,item);
				break;


			case 2: display(root);
				break;

			case 3:exit(0);
		}
	}

}
/*
      case 0: Linked list empty         temp
				      info link
				     ............
		root==NULL           | 5  | NULL|    /
				     ............
      case 1: Only one node is there in the linked list

	    temp	       root
	 .........	 .............
	 |  5 |	-|-----> | 10 |  Null|
	 .........	 .............
			  info       link


	     Note: when link field of the root node is null we can say
		   only one node is there in the linked list.

      case 2:More than one node is there in the linked list
			   temp
prv=NU                  .......                              25
		      | 12  | NU|
			.......
      root
		  prev		cur              p        C==NULL
  ..........    ..........    ...........    ..........
 | 5  | --|--->| 10 | --|--->|15  |  --|--->| 20 |Null|
 ..........     ..........    ..........    ...........
 info  link	 info link      info link    info  link

 while(cur!=NULL && item> cur->info)
	{
		prev=curr;
		cur=cur->link;
	}


 */

NODE  insert_order(NODE root,int item)
{
	NODE temp,prev,cur;
	temp=getnode();
	temp->info=item;
	temp->link=NULL;


	if(root==NULL)
		return temp;

	if(item<root->info)
	{
	     temp->link=root;
	     return temp;
	}

	prev=NULL;
	cur=root;

	while(cur!=NULL && item> cur->info)
	{
		prev=cur;
		cur=cur->link;
	}
	prev->link=temp;
	temp->link=cur;
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
		printf("%d",temp->info);
		temp=temp->link;
	}
	return root;


}


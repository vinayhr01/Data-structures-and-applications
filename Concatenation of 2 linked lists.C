Concatenation of two Linked Lists
----------------------------------
The process of joining a second linked list at the end of the first linked list is called concatenation of linked lists.
-> If the first linked list is empty,the address of the first node of the second linked list must be returned.
-> If the second linked list is empty,the address of the first node of the first linked list must be returned.
-> If both the linked lists are not empty, attach the second linked list to the first linked list and return the address
   of the first node of the first linked list.

case 0:
	   root1==NULL  && root2==NULL
       concatenation is not possible


case 1: When root1==NULL (root2 is not equal to null)

			            root2
	    root1==NULL     ...........     .............
			            | 5	 |  --|---->| 10  | Null|
			            ...........     .............

	    return root2


case 2: when root2==NULL (root1 is not equal to null)


			            root1
	    root2==NULL     ...........     .............
			            | 5	 |  --|---->| 10  | Null|
			            ...........     .............

	    return root1


case 3: root1!=NULL and root2!=NULL

   root1               last             root2
   ...........     .............      ..........     ............
   | 5 |   --|---->| 10  | Null|      |  2 | --|---->| 4  | Null|
   ...........     .............      ..........     ............



WORKING
-------
The last node of the first linked list must be identified.

	last->link=root2

-----------------------------------------------------------------------------------------------------------------------------------------------

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
		printf("Insufficient memory\n");
		exit(0);
	}
	return p;

}

NODE insert_front(NODE root,int item);
NODE concatenate(NODE root1,NODE root2);
NODE display(NODE root);

void main()
{
	NODE root1=NULL;
	NODE root2=NULL;
	int item;
	int choice;

	for(;;)
	{
		printf("1:Insert the first linked list\t 2:Insert the second linked list\n");
		printf("3:Concatenate\t 4:display the first linked list\n ");
        printf("5:Display the second linked list\t 6:exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the item to be inserted in First Linked List\n");
				    scanf("%d",&item);
				    root1=insert_front(root1,item);
                    break;

			case 2: printf("Enter the item to be inserted in Second Linked List\n");
				    scanf("%d",&item);
				    root2=insert_front(root2,item);
                    break;

			case 3: root1=concatenate(root1,root2);

			case 4: display(root1);
				    break;

			case 5: display(root2);
				    break;

			case 6: exit(0);
		}
	}
}

NODE insert_front(NODE root,int item)
{
	NODE temp;
	temp=getnode();
	temp->info= item;
	temp->link= root;
	return temp; // returns the address of the first node
}

NODE concatenate(NODE root1, NODE root2)
{
	NODE last;
	if(root1==NULL && root2== NULL)
		return NULL;
	else if(root2==NULL)
		return root1;
	else if(root1==NULL)
		return root2;

	last=root1;
	while(last->link!=NULL)
	{
		last=last->link;
	}
	last->link=root2;
	return root1;
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


---------------------------------------------------------------------------------------------------------------------------------------------

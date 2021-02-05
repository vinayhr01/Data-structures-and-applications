/*Seach for an key in the linked list:  This operation searchs fo node in the
linked list based on the key specified by the user.
`->The function serach_key() is used to to do the above activity.
->If the linked list is empty it prints the message "Linked list is empty
search is immposible"

	case 0: root==NULL
Note:prints the message "Linked list is empty"search is immposible

-> If the specified key is not present in the linked list prints the message
unsucessful search.

	case 1:   key is 30
	 .........   ...........     ...........
	 | 5  |   | ->| 10 |   | ->  | 15 | NUL|
	 .........   ...........     ............
	Note: prints the message  "key element not found"

-> if the specified key is present in the linked list prints the message
sucessful search.

	case 1:   key is 10
		 .........   ...........     ...........
		| 5  |   | ->| 10 |   | ->  | 15 | NUL|
		.........   ...........     ............
		Note: prints the message  "key  found"


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
NODE search_key(NODE root,int key);
NODE display(NODE root);

void main()
{
	NODE root=NULL;
	int item;
        int key;
	int choice;

	for(;;)
	{
		printf("1:insert_front 2:search_key\n");
		printf("3:dsiplay\t  4:exit ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Item to insert First Linked List\n");
				scanf("%d",&item);
				root=insert_front(root,item);
				break;

			case 2: printf("Read key\n");
				scanf("%d",&key);
				root=search_key(root,key);
				break;

			case 3: display(root);
				break;

			case 4: exit(0);
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

NODE search_key(NODE root, int key)
{
	NODE prev,cur,temp;
	if(root==NULL)
	{
		printf("Linked list is empty search is not possible\n");
		return root;
	}
	cur=root;
	while(cur!=NULL)
	{
		if(key==cur->info) break;
		cur=cur->link;
	}
	if(cur==NULL)
	{
		printf("key not found\n");
		return root;
	}
	printf("Key found\n");

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






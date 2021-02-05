/*Doubly Linked List:
	In single linked list each node having 2 fields (info & link),
Each node will be having 1 link field.
-> In doubly linked list each node should be having
		3  fiels(llink,info,rlink)
		->llink ->left link
		-> rlink-> right link		.......................
		|      |      |	      |
		.......................
		 llink   info   rlink
Pointer to remember:
	llink- > llink holds address of the left node
	info-> info holds 	the value
	rlink-> hodls the address of the right node.


Cases to be  considered to understand doubly linked list.


	case 0: Linked list is empty

			root==NULL
			linked list is empty

	case 1: Only one node in the linked list
		       root
		   ..................
		   | N  | 5   |  N  |
		   ..................
		   llink   info  rlink

case 2: More than one node in the linked list
	root
    ..............         ...........     ...........   .............
    | N | 5  |   | - ->    |  | 10|  | --> |  |15|   |-->|   | 20 | N |
    ..............  < - -  ........... <-- ...........<--.............


Insert_front:Insert_front is used to insert a node at the beginign of the
linked list

case 0: Linked list is empty
	temp
     ..................
    |  N |  5  |  N   |		root==NULL
    ...................	        linked list is empty
     llink info  rlink

	case 1: Only one node in the linked list
      temp		       root
..................     ..................
|  N  |	2  |  	 | ->  |   | 5   |  N  |
.................  <-   ..................
  l	i     r	   llink   info  rlink

case 2: More than one node in the linked list
	root
    ..............         ...........     ...........   .............
    | N | 5  |   | - ->    |  | 10|  | --> |  |15|   |-->|   | 20 | N |
    ..............  < - -  ........... <-- ...........<--.............


isert_rear(): Insert_rear()function is used to insert the node at the
end of doubly linked list.

case 0: Linked list is empty                          temp
						..................
			root==NULL             |   |   5    |     |
			linked list is empty    ...................

	case 1: Only one node in the linked list
		       root                         temp
		   ..................       ....................
		   | N  | 5   |     |  ->   | N   |  10   | N   |
		   ..................  <-     ....................
		   llink   info  rlink

case 2: More than one node in the linked list
	root                                 last              temp
    ..............         ...........     ...........    ................
    | N | 5  |   | - ->    |  | 10|  | --> |  |15|  N|    | N  |  20| N  |
    ..............  < - -  ........... <-- ...........    ................

NODE insert_rear(NODE root,int item)
{
	NODE temp;
	temp=getnode();
	temp->link=NULL;
	temp->rlink=NULL;

	if(root==NULL)
		return temp;

	if(root->rlink==NULL) //only one node in the doubly linked list
	{
		root->rlink=temp;
		temp->llink=root;
		return root;
	}
	last=root;
	while(last->rlink!=NULL)// this cond is false only when last is realy
	//pointing to last node of the linked list
	{
		last=last->rlink;
	}
	last->rlink=temp;
	temp->llink=last;
	return root;
}

Delete_front: The function delete_front is used to delete the node from the
front end of doubly linked list.
->condier the cases given below.
	case 0: Linked list is empty

			root==NULL
			linked list is empty

	case 1: Only one node in the linked list
		       root
		   ..................
		   | N  | 5   |  N  |
		   ..................
		   llink   info  rlink

case 2: More than one node in the linked list
	 temp                root
    ..............         ...........     ...........   .............
    | N | 5  | N  |       |N | 10|  | --> |  |15|   |-->|   | 20 | N |
    ..............        ........... <-- ...........<--.............

NODE delete_front(NODE root)
{
	NODE temp;
	if(root==NULL)
	{
		printf("Linked list is empty\n");
		return root;
	}
	if(root->rlink==NULL)
	{
		printf("The node deleted =%d",root->info);
		free(root);
		return root;
	}
	temp=root;
	root=root->rlink;
	temp->rlink=NULL;
	root->llink=NULL;
	printf("The NODe deleted is %d", temp->info);
	free(temp);
	return root;


}
Delete_rear: The function delete_rear() is used to delete the node from
 end of  the doubly linked list.
->condier the cases given below.
	case 0: Linked list is empty

			root==NULL
			linked list is empty

	case 1: Only one node in the linked list
		       root
		   ..................
		   | N  | 5   |  N  |
		   ..................
		   llink   info  rlink

case 2: More than one node in the linked list
plast	 root                               plast       last
    ..............      ...........     ...........   .............
    | N | 5  |  | ->    | | 10|  | --> |  |15| N  |    | N | 20 | N |
    ..............  <- ........... <-- ............    ............

NODE delete_rear(NODE root)
{
	NODE last;
	NODE plast;
	plast=NULL;
	last=root

	if(root==NULL)
	{
		printf("Deletetion is not possible\n");
		return root;
	}
	if(root->rlink==NULL)
	{
		printf("The NODE deleteed=%d",root->info);
		free(root);
		return NULL;
	}
	while(last->rlink!=NULL)
	{
		plast=last;
		last=last->rlink;
	}
	last->llink=NULL;
	plast->rllink=NULL;
	printf("The node deleted is %d",last->info);
	free(last);
	return root;


}
Insert left_ to the given key: the function insert_left_key() is used to this
activity.
->consider the cases given below .
       case 0: Linked list is empty

			root==NULL
			linked list is empty

	case 1: Only one node in the linked list
		       root
       Assume key=5
       temp                     root
  .............		..................
 | N  |	2  | 	|  ->	|   | 5   |  N  |
 ..............	   <-	..................
			   llink   info  rlink

 case 2: More than one node in the linked list
	root

 Assume key =15                    temp
 item=12			..............
			       |   | 12 |    |
				..............
				 ^
pk=NUll pk,root             pk   .           k
    ..............       ...........     ...........   .............
    | N | 5  |   | - ->  |  | 10|  |      |  |15|   |-->|   | 20 | N |
    ..............  < - -...........      ...........<--.............





NODE insert_key_left(NODE root,int item, int key)
{
	NODE temp;
	NODE knode; //knode=keynode
	NODE pknode; //previous keynode
	temp=getnode();
	temp->info=item;
	temp->llink=NULL;
	tem=->rllink=NULL

	if(root==NULL)
	{
		printf("\nInsert left to the specified key oepration NP\n");
		return NULL;

	}
	if(root->rlink==NULL)
	{
		if(root->info==key)
		{
			root->llink=temp;
			temp->rlink=root;
			return temp

		}
		printf("insert_lest_key is not possible\n");
		return root;
	}
    while(knode!=NULL && knode->info!=key)//second cod. fails (key found)
    {
	pknode=knode;
	knode=knode->rllink;
    }
    if(knode==NULL)
    {
	printf("Insert_left_key is not possible\n");
	return root;
    }
    pknode->rllink=temp
    temp->llink=pknode
    temp->rlink=knode;
    knode->llink=temp;
    return root;


}
*/

#include <stdio.h>

struct node
{
	struct node *llink;
	int info;
	struct node *rlink;
};
typedef struct node *NODE;

NODE getnode()
{
	NODE p;
	p=(NODE) malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("Mem shortage\n");
		exit(0);
	}
	return p;
}



NODE insert_front(NODE root,int item);
NODE insert_rear(NODE root,int item);
NODE insert_left_key(NODE root,int item ,int key);
NODE delete_front(NODE root);
NODE delete_rear(NODE root);
NODE display(NODE root);




void main()
{
	NODE root=NULL;
	int item;
	int choice;
	int key;

	for(;;)
	{
		printf("1:insert_front\t 2:insert_rear\n");
		printf("3:delete_front\t 4:delete_rear\n");
		printf("5:insert_left_key\t  6:dsiplay\n");
		printf("7:exit");
		scanf("%d",&choice);
		switch(choice)
		{

			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				root=insert_front(root,item);
				break;

			case 2: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				root=insert_rear(root,item);
				break;

			case 3: root=delete_front(root);
				break;

			case 4: root=delete_rear(root);
				break;


			case 5: insert_left_ley(root,item,key);
				break;

			case 6: display(root);
				break;

			case 7:exit(0);
		}
	}

}
NODE insert_front(NODE root,int item)
{
	NODE temp;
	temp=getnode();
	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;

	if(root==NULL)
	{
		return temp;
	}
	temp->rlink=root;
	root->llink=temp;
	return temp;
}


NODE insert_rear(NODE root,int item)
{
	NODE temp;
	NODE last;
	temp=getnode();
	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;


	if(root==NULL)
		return temp;

	if(root->rlink==NULL) //only one node in the doubly linked list
	{
		root->rlink=temp;
		temp->llink=root;
		return root;
	}
	last=root;
	while(last->rlink!=NULL)// this cond is false only when last is realy
	//pointing to last node of the linked list
	{
		last=last->rlink;
	}
	last->rlink=temp;
	temp->llink=last;
	return root;
}

NODE delete_front(NODE root)
{
	NODE temp;
	if(root==NULL)
	{
		printf("Linked list is empty\n");
		return root;
	}
	if(root->rlink==NULL)
	{
		printf("The node deleted =%d",root->info);
		free(root);
		return root;
	}
	temp=root;
	root=root->rlink;
	temp->rlink=NULL;
	root->llink=NULL;
	free(temp);
	return root;


}
NODE delete_rear(NODE root)
{
	NODE last;
	NODE plast;
	plast=NULL;
	last=root;

	if(root==NULL)
	{
		printf("Deletetion is not possible\n");
		return root;
	}
	if(root->rlink==NULL)
	{
		printf("The NODE deleteed=%d",root->info);
		free(root);
		return NULL;
	}
	while(last->rlink!=NULL)
	{
		plast=last;
		last=last->rlink;
	}
	last->llink=NULL;
	plast->rlink=NULL;
	printf("The node deleted is %d",last->info);
	free(last);
	return root;


}
NODE display(NODE root)
{
	NODE temp;
	if(root==NULL)
	{
		printf("LInked list emopty\n");
		return NULL;
	}
	temp=root;
	while(temp->rlink!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->rlink;
	}
	printf("%d",temp->info);
	return root;

}

NODE insert_key_left(NODE root,int item, int key)
{
	NODE temp;
	NODE knode; //knode=keynode
	NODE pknode; //previous keynode
	temp=getnode();
	temp->info=item;
	temp->llink=NULL;
	tem=->rllink=NULL

	if(root==NULL)
	{
		printf("\nInsert left to the specified key oepration NP\n");
		return NULL;

	}
	if(root->rlink==NULL)
	{
		if(root->info==key)
		{
			root->llink=temp;
			temp->rlink=root;
			return temp

		}
		printf("insert_lest_key is not possible\n");
		return root;
	}
    while(knode!=NULL && knode->info!=key)//second cod. fails (key found)
    {
	pknode=knode;
	knode=knode->rllink;
    }
    if(knode==NULL)
    {
	printf("Insert_left_key is not possible\n");
	return root;
    }
    pknode->rllink=temp
    temp->llink=pknode
    temp->rlink=knode;
    knode->llink=temp;
    return root;


}


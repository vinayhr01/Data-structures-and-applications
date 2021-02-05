/*Cicular Linked List:
A cirulcar Linked  list is one , where link field of the last node is having
the address of first node.

-> In circular Linked list program need to keep track of address of last
node.

-> The pictorial represenation of the circular linked list is given below.

	case  0:
		       last==NULL
	Note: Cirular linked list is empty.


	case 1:        last
		    ............
		   |  5   |  --|---.
		    .............  .
			.	   .
			.   .   .  .

	case 2:                                          last
		   ...........     .............     ...............
		  |  5  |    | ->  | 10 |      | ->  | 15  |  .    |
		   ...........	   .............      .............
		    .					      .
		    ...........................................

Operations on circular single linked List:
1.insert_front()
2.delete_front()
3. insert_rear()
4. delete_rear()
5. display()

Insert_front(): Consider the below given cases.
...................................................

case  0:
		       last==NULL
	Note: Cirular linked list is empty.


	case 1: Only one node in the linked list
	temp->link=last->link

	temp	    last
      info link         info   link
     ..........	       ............
    | 10 |     | ->    | 5   |  --|---.
     ..........	       .............  .
	.			      .
	. . .  .  . .  . .	. .   .
		temp->link=last;
		last->link=temp

	case 2:
     temp	   first                                   last
  ....... .	  ...........     .............     ...............
 | 2  |	  | ->	  |  5  |    | ->  | 10 |      | ->  | 15  |  .    |
  . . .	. .	   ...........	   .............      .............
      .							      .
      .	. . . .	.  . . ........................................


 Insert_rear()

case  0:
		       last==NULL
	Note: Cirular linked list is empty. return temp
			    temp
			...........
			|  5  |  ..|...
			...........   .
				.   . .


	case 1:        last               temp
		    ............      ...........
		   |  5   |  --| ---> |  10  | . |
		    .............     .......... .
			      .   .   .  .  .  .

		    last->link=temp
		    temp->link=last;
		    return temp;


	case 2:                                    last           temp
	 ...........     .............     ...............    ...........
	 |  5  |    | ->  | 10 |      | ->  | 15  |      |-> | 20 |     |
	 ...........	   .............      .............   ...........
	      .				                             .
	      ................................................ ..... .
	      temp->link=last->link
	      last->link=temp
	      return temp;


Delete_front: The function delete_front() is used to delete the node from
front end.
-> Consider the cases given below.

	case  0:
		       last==NULL
	Note: Cirular linked list is empty.


	case 1:        last
		    ............
		   |  5   |  --|---.
		    .............  .
			.	   .
			.   .   .  .

	case 2:      first                                    last
		   ...........     .............     ...............
		  |  5  |    |    | 10 |      | ->  | 15  |  .    |
		   ...........	   .............      .............
				      .			       .		      .
				      ..........................

Delete from rear end: The function delte_rear() is used to delete the node
from rear end.
-> Consider cases given below.
case  0:
		       last==NULL
	Note: Cirular linked list is empty.


	case 1:        last
		    ............
		   |  5   |  --|---.
		    .............  .
			.	   .
			.   .   .  .

	case 2:                                          last
		   ...........     .............     ...............
		  |  5  |    | ->  | 10 |  .    |   | 15  |  .    |
		   ...........	   .............      .............
		    .			   .
		    ........................



	case 3:           plast        last
			..........     ...........
		       |  5 | .   | -> | 10  |  .  |
			.........       ..........
			     ....................

NODE delete_rear(NODE last)
{
	NODE plast; // previous to the last
	if(last==NULL)
	{
		printf("Deletion is not possible\n");
		return NULL;
	}
	if(last->link==last)
	{
		printf("The item deleted =%d", last->info);
		free(last);
		return NULL;
	}
	plast=last->link;
	while(plast->link!=last)
	{
		past=past->link;
	}
	plast->link=last->link;
	last->link=NULL;
	printf("The NODe deleted=%d", last->info);
	free(last);
	return plast;
}


NODE display(NODE last);
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

NODE insert_front(NODE last,int item);
NODE insert_rear(NODE last,int item);
NODE delete_front(NODE last);
NODE delete_rear(NODE last);
NODE display(NODE last);

void main()
{
	NODE last=NULL;
	int item;
	int choice;

	for(;;)
	{
		printf("1:insert_front\t 2:insert_rear\n");
		printf("3:delete_front\t 4:delete_rear\n");
		printf("5:display\t  6:exit");
		scanf("%d",&choice);
		switch(choice)
		{

			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				last=insert_front(last,item);
				break;

			case 2: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				last=insert_rear(last,item);
				break;

			case 3: last=delete_front(last);
				break;

			case 4: last=delete_rear(last);
				break;

			case 5: display(last);
				break;

			case 6: exit(0);
		}
	}

}

NODE insert_front(NODE last,int item)
{
	NODE temp;
	temp=getnode();
	temp->info=item;
	temp->link=temp;

	if(last==NULL)
	{
		return temp;
	}
	temp->link=last->link;
	last->link=temp;
	return last;
}

NODE insert_rear(NODE last,int item)
{
	NODE temp;
	temp=getnode();
	temp->info=item;
	temp->link=temp;


	if(last==NULL)
	{
	    return temp;
	}
	if(last->link==last)
	{
		last->link=temp;
		temp->link=last;
		return temp;
	}
	temp->link=last->link;
	last->link=temp;
	return temp;
}

NODE delete_front(NODE last)
{
	NODE first;
	if(last==NULL)
	{
		printf("Linked list empty deletion is not possible\n");
		return NULL;
	}
	if(last->link==last)
	{
		printf("The NODE delete=%d",last->info);
		free(last);
		return NULL;
	}
	first= last->link;
	last->link= first->link;
	first->link=NULL;
	printf("The NODE deleted=%d",first->info);
	free(first);
	return last;
}

NODE delete_rear(NODE last)
{
	NODE plast; // previous to the last
	if(last==NULL)
	{
		printf("Deletion is not possible\n");
		return NULL;
	}
	if(last->link==last)
	{
		printf("The item deleted =%d", last->info);
		free(last);
		return NULL;
	}
	plast=last->link;
	while(plast->link!=last)
	{
		plast=plast->link;
	}
	plast->link=last->link;
	last->link=NULL;
	printf("The NODe deleted=%d", last->info);
	free(last);
	return plast;
}

NODE display(NODE last)
{
	NODE temp;
	if(last==NULL)
	{
		printf("Linked List is empty\n");
		return last;
	}
	temp=last->link;
	while(temp!=last)
	{
		printf("%d",temp->info);
		temp=temp->link;
	}
	printf ("%d\n",last->info);
	return last;
}

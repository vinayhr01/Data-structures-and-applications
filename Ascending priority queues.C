/*Priority Queue:  There are two types of priority Queues.
1. Ascending Priority Queue
2. Descending Priority Queue

Ascending Priority Queue:Ascending Priority Queue is one where elements can
be inserted in any order, but while deleting an from the element from the
queue, only the smallest element is removed first.

Note: From the above statement it is clear that sorted.

-> we are using insertion sort to place the elemnents on the queue(At the
time of inserting only insertion sort places the element at proper postion.)

->Various operations over Ascending Priority Queue

1. insert()
2. delet()
3. display()

-> The following diagram shows pictorial represeatation of Ascending Priority
Queue
	f ->front
	........................
       | 2  | 5 | 10 | 15 | 20 |
	........................
			     r->rear end


APQ_full Conditon: In Q_full condition improtance is given for rear end

	if(*r==Q_size-1)
	{
		printf("Q full\n");
		return;
	}


APQ_empty Condtion:initally f=0, r=-1 q is empty, once f escedes r than  also
Q is empty
-> in Q_empty condtion imporatance is given from front as well as rear end.

	if(*f>*r)      //Q_empty checking
	{
		return -1;
	}

ApQ_ Insert operation: The insert operation is shown below
	void insert(int q[],int item,int *r)
	{
		if(*r==Q_size-1)
		{
			printf("Q full\n");
			return;
		}
		// i should insertion sort to crearte APQ
				item 7      j=2
		j=*r;                              f
		while(j>=0 && item< Q[j])       Q: 2  4  5  7
		{                                           r
			q[j+1]=q[j]
			j--;
		}
		q[j+1]=item;
		*r=*r+1;
	}


ApQ_ delet operation: In the delete operation Q_empty condition is cheacked
int delet(int q[],int *f,int *r)
{
	if(*f>*r)      //Q_empty checking
	{
		return -1;
	}
	return q[(*f)++];
}




ApQ_ display operation:In the delete operation Q_empty condition is cheacked
void display(int q[],int f,int r)
{
	int i;
	if(f>r)  //Q_empty checking
	{
		printf("Q empty\n");
		return;
	}
	for(i=f;i<=r;i++)
	{
		printf("%d\t",q[i]);
	}
} */

#include <stdio.h>
#include <stdlib.h>
#define Q_size 5

void insert(int q[],int item,int *r)
{
	int j;
	if(*r==Q_size-1)
	{
		printf("Q full\n");
		return;
	}
	j=*r;
	while(j>=0 && item< q[j])
	{
		q[j+1]=q[j];
		j--;
	}
	q[j+1]=item;
	*r=*r+1;
}
int delet(int q[],int *f,int *r)
{
	int item_deleted;
	if(*f>*r)
	{
		return -1;
	}
	item_deleted=q[*f];
	(*f)++;
	if(*f>*r)
	{
		*f=0;
		*r=-1;
	}
	return item_deleted;
}



void display(int q[],int f,int r)
{
	int i;
	if(f>r)  //Q_empty checking
	{
		printf("Q empty\n");
		return;
	}
	for(i=f;i<=r;i++)
	{
		printf("%d\t",q[i]);
	}
}


void main()
{
	int f=0;   // front end
	int r=-1;   // rear end
	int choice; // switch purpose
	int q[10];  // array represetation of Q
	int item;// item to be inserted

	for(;;)
	{
		printf("1:insert 2:delete 3: dipslay 4:exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the element to be inser\n");
				scanf("%d",&item);
				insert(q,item,&r);
				break;
			case 2: item=delet(q,&f,&r);
				if(item==-1)
					printf("q empty\n");
				else
					printf("item_deleted=%d",item);
				break;
			case 3: display(q,f,r);
				break;
			case 4:exit(0);

		}
	}

}




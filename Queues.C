/*Queue Defintion , Array Implementation, Queue operations:
.......................................................
Definition: A Queue is First in First out data structure.(FIFO) or(LILO)
-> Queue is linear data structure
->A queue is data structure where the elemenets are inserted from one end
called rear end,elements are deleted from front end.
-> Queue is having 2 ends
  1. front
  2. rear
Queue operations : The queue operatons are
	1. insert() -> happens from rear end
	2. delet()  -> happens from front end.

	  F-> front end
	  0    1    2     3    4
	...........................
	| 5  | 10 | 15  | 20 | 25 |    Q_FULL
	...........................
				R -> rear end
	case1:
	  F
	  0   1  2   3  4
	 ..................
	 |   |  |   |  |  |      Q_Empty : when f=0 and R=-1 or (f>r)
	 ..................
    R=-1

	case2:
	 F
	  0   1  2   3  4
	 ..................
	 | 5  |  |   |  |  |      INSERT 5
	 ..................            R=R+1
	R=0

	case2:
	 F
	  0    1  2   3  4
	 ..... .............
	 | 5  |10  |   |  |  |      INSERT 10
	 ..................            R=R+1
		R
	 case3:
	 F
	  0    1     2     3     4
	 ..... ....................
	 | 5  |10  | 15  | 20 |25  |      INSERT 15,20,25
	 ..........................            R=R+1
				R            if(R==Q-size-1) q_full
					 we cannot insert
	 case3:
	 F
	  0    1     2     3     4
	 ..... ....................
	 | 5  |10  | 15  | 20 |25  |      INSERT 15,20,25
	 ..........................            R=R+1
				R            if(R==Q-size-1) q_full
					 we cannot insert


	case4:
		     F
	  0    1     2     3     4
	 ..... ....................
	 |   |  | 15  | 20 |25  |      Delete 5 & 10
	 ..........................      5 & 10 logically deleted
				R        f++


	 case5:

	 case3:
		     F
	  0    1   2   3   4
	 ..... ....................
	 |   |  |   | 20 |  |           when f==r only one element in the Q
	 ..........................
		      R
	 case3:
			     F=5
	  0    1   2  3  4
	 ..... ....................
	 |   |  |   |  | 20d |           when f==r only one element in the Q
	 ..........................
			  R

  Note: once F excedes R Queue is empty

  Disadvantage of Queue:

	case3:
			     F
	  0    1   2   3     4
	 ..... ....................    Insert operation not possible
	 |   |   |    |    | 25 |      eventhough Q is not full
	 ..........................
			     R
	Note: To overcome this we use circular queues.


*/

#include <stdio.h>
#include <stdlib.h>
#define Q_size 5

void insert(int q[],int item,int *r)
{
	if(*r==Q_size-1)
	{
		printf("Q full\n");
		return;
	}
	*r=*r+1;
	q[*r]=item;
}

int delet(int q[],int *f,int *r)
{
	if(*f>*r)
	{
		return -1;
	}
	return q[(*f)++];
}

void display(int q[],int f,int r)
{
	int i;
	if(f>r)
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

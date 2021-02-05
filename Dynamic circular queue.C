/*Disadvantage of ordinary queue:
	  0  1   2   3    4 f
	.......................
 Q      |   |   |    |   | 5   |
	.......................

	   4	5  -1	 r
	if(r==Q_size-1)
	{
			printf("Q full insertion is not possibel\n");
	}
	r=r+1;
	q[r]=item;

 Circular queue using Dynamic Arrays:
	Cicular queue is used to overcome the disadvantage of ordinary Queues.
Dynamic circular queue is used to to extend the capcity of CR to infinite.

-> Dynamic circular queue is used wrok with infinite elements.


** Consider the Cicular queue with the capcity of 8 locations


		      0  1   2   3   4   5     6    7
		     ..................................
		    | 1  | 2  | 3  | 4 | 5  | A  | B  |
		     ...................................

Assume: after deleting 1,2,3,4,5              f
		     0   1   2    3    4   5     6    7
		     ..................................
		    | C | D | E |  F |  G |   | A  | B  |
		     ...................................
count=2                                 r
insert c,d,e,f,g




       C |  D                                           f
	 |                     0   1   2   3   4    5   6   7
    B	 |     E             ................................
......................       | C | D | E | F  |G  |   | A |B |                               |
fr=6  A	 |     G   rear =4   .................................
	 |                                      r
	 |
     After  inserting C D E E F G , would like to insert H
while inserting H

*** We nedd to double the CQ using realloc function:
	  0   1   2   3   4   5    6 f  7   8    9   10   11 12  13  14  15
		...................................................................
	| C | D | E | F | G |    | A  | B |   |   |    |   |   |   |   |   |
	...................................................................
			  r

***** After doubleing right shift is required.

			       f
      0   1   2   3   4   5    6   7   8    9   10   11 12  13  14  15
     ...................................................................
     | C | D | E | F | G |   | A  | B |   |   |    |   |   |   |   |   |
     ...................................................................
		       r
**** Right sgement shifting
								 f
	0   1   2   3   4   5   6   7   8    9  10   11 12  13  14  15
     ...................................................................
     | C | D | E | F | G  |   |    |   |   |   |    |   |   |   | A  | B  |
     ...................................................................
		       r
case 2: Insert 1,2,3,4,....9
								  f
	0   1   2   3   4   5   6   7   8    9   10   11  12  13   14  15
     ...................................................................
     | C | D | E | F | G  | 1  |2 | 3  | 4  | 5 | 6  | 7 | 8  | 9 | A  | B  |
     ...................................................................
							       r

     insert 1,2,3,4,5,6,7,8,9,10,11, when user is attemting to insert 10

*** Q should get doubled                                            f
 0                                       13                         29  30
 ...........................................................................
|c|--------------------------------------| 9|                     | A  | B |
 ...........................................................................
  */

#include <stdio.h>

int MAXQS=3; // size of the dciruclar queue is 3

struct x   //x is the name of the strcture
{
	int info;           //2 bytes
};
typedef struct x ele;     // ele acts as datatypee
/*Function returning pointer
	  f
0    1    2
...............
 6  | 0 |  3  |
...............
r
nq
	   r              f
0     1    2   3     4     5
.................................
 10 |   | 5   |     |     |   |
................................
r	     0         2
*/
void copy(ele *start,ele *end, ele *dest)
{
	int i;
	printf("While coping elements\n");
	for(i=0;(start+i)<end; )
	{
		dest[i]=start[i];
		printf("%d%d",i,dest[i].info);
		i=i+1;

	}
}


ele*  Qfull(ele *q,int* front,int* rear)
{
	ele *nq;//new queue
	int start;         // 3           2
	nq=(ele*)malloc(2*MAXQS*sizeof(ele)); // 12 bytes
	// cpacity of doubled
	if(nq==NULL)
	{
		printf("Memory for nq is insufficient");
	}
	start=(*front+1)%MAXQS;//START=0
	if(start<2)          // 0   0   3-1
		copy(q+start, q+start+MAXQS-1,nq);
	else
	{
		copy(q+start,q+MAXQS,nq);
		copy(q,q+*rear+1,nq+MAXQS-start);
	}
	*front=2*MAXQS-1;
	*rear=MAXQS-1;
	MAXQS=MAXQS*2;
	free(q);
	return (nq);

}
ele*  addq(ele q[],ele item,int* rear, int* front,int* count)
{
	*rear=(*rear+1)%MAXQS;
	if(*front==*rear)
	{
		printf("Queue is Full\n");
		 q= Qfull(q,front,rear);// this function  to double
		 //the capcity and also does right segment shifting

	}
	q[*rear]=item;
	return q;



}
void deleq(ele q[],int* front,int* rear,int* count)
{
	int i;
	if(*front == *rear)
	{
		printf("Q is empty\n");
		return;
	}
	*front= (*front+1)%MAXQS;
	printf("The item deleted %d",q[*front]);
	q[*front].info=0;
}

void disp(ele q[],int front,int rear,int count)
{
	int i;
	if(front==rear)
	{
		printf("cirular Q is empty\n");
		return;
	}
	printf(" Queue contents are\n");
	for(i=0;i<MAXQS;i++)
	{
		printf("%d\t",q[i].info);
	}

}



void main()
{
      ele *q,item; // *q pointer to structure
      int rear, front;
      int ch; // switch
      int count=0;// count keep track of no of elements in the q
      int i;
      clrscr();
      /*initallly assumation is content is 0 to indicate no element
	    f
	    0   1   2
	  ............
	 | 5  | 10 | 15|  // 6bytes
	  ............
	  r  */
      front=0;
      rear=0;
      //dynamic memory allocation
		       //	2 *    3
      q=	 (ele*)malloc(sizeof(ele)*MAXQS);
       // at any point pointer can be replaced by array, array also can
       //replaccd pointer
      for(i=0;i<MAXQS;i++)
	q[i].info=0;

      for(;;)
      {
	printf("\n1:Insert Element \t 2: Delete Element\n");
	printf("3:Display Element \t 4: Exit\n");
	printf("Enter the choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("Enter the item to be inserted\n");
			scanf("%d",&(item.info));
			// the function addq adds the item to the q
			// passsing item is passsing structure varible as
			//parameter
			// passing q is call by reference
			q=addq(q,item, &rear, &front,&count);
			break;

		case 2: deleq(q,&front, &rear,&count);
			break;

		case 3:disp(q,front,rear,count);
			break;

		case 4: free(q);
			exit(0);

	}
      }

}








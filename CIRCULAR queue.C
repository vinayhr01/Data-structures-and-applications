/*Cicrular Queue:

	Disadvantage Ordinary of Queue:

	case:
			     F
	  0    1   2   3     4
	 ..... ....................    Insert operation not possible
	 |   |   |    |    | 25 |      eventhough Q is not full
	 ..........................
			     R
	Note: To overcome this we use circular queues.
Circular Queue: To ovecome the disadvantage of ordinary queue we use
circular queue
->The pictorial representation is shown in the below fig.
-> Even the circular queue is having 2 ends
    1. front end 2.rear end.
-> some of the cases of circular queue is shown below.

case 0:
	  f
	  0    1   2    3                     |
	 ..... ............                1  |  2
	 |   |   |    |    |             ...........
	 ...................               0  |  3
     r=-1                                  F  |
					   r=-1
case 1: insert 5 ,10,15
	  f
	  0    1   2    3                     |     r
	 ..... ............            L1 10  | L2 15
	 | 5 | 10 |15 |   |             .............
	 ...................            L0 5  | L3       L0->loccation
					   F  |
Note: circular Q should maintain a count no of element in the Q
count=3
case 2:	insert 5 ,10,15
   wrt ordinary q
	 *r=*r+1
	 q[*r]=item;

   wrt Circular q:
	*r=(*r+1)%q_size
	  =(2+1)%4
	  =3
	q[*r]=item;

	-> Insert 20

	  f
	  0    1   2    3                     |
	 ..... ............            L1 10  | L2 15
	 | 5 | 10 |15 |20 |             .............
	 ...................            L0 5  | L3 20      L0->loccation
		       r		   F  |     r
       count=4;
case 3:  trying to insert 25



	*r=(*r+1)%q_size
	*r=0
	q[*r]=item


	  f
	  0    1   2    3                     |
	 ..... ............            L1 10  | L2 15
	 | 5 | 10 |15 |20  |             .............
	 ...................            L0 5  | L3  20     L0->loccation
		    r			   F  |      r
Checking CQ full condition

	if(count==Q_size)
	{
		printf("Q full\n");
	}
Note: we cannot insert   25 because CQ is full.

case 4:   Deleting 5,10,15(3 delete operations)


		       f
	  0    1  2    3                     |
	 ..... ............            L1    | L2
	 |  |   |   | 20  |             .............
	 ...................            L0   | L3  20 F    L0->loccation
		      r			     |      r
count=1;
Note: For every delete operation count should be decremented
       For every insert operation count shoudl be incremented.

case 5: inserting 25 30 and 35
	count=1 and q_size 4 so insertion is possibel
	*r=(*r+1)%q_zise;
	q[*r]=item;
	count=4

			   f
	  0    1     2     3                      |
	 ..... ................           L1  30  | L2 35 r
	 | 25 | 30  | 35  | 20  |             .............
	 ......................           L0  25  | L3  20 F    L0->loccation
		     r	      			  |
case 6: Deleting 20 25 30 from CQ
	 if(count==0)
		print CQ is empty
	 *f=(*f+1)%q_size
	 count=1;

		      f
	  0     1     2     3                     |
	 ..... ................           L1      | L2 35 r  f
	 |    |    | 35  |  |             .............
	 ......................           L0      | L3       L0->loccation
		      r				  |

	 Deleting the last element:
	 count=0

			    f
	  0     1     2     3                     |
	 ..... ................           L1      | L2  r
	 |    |    |     |  |             .............
	 ......................           L0      | L3  f     L0->loccation
		      r				  |

	 Note: once f excedes r CQ is empty.

	 if(f>r)
	 {
	     f=0
	     r=-1;
	 }
*/

#include <stdio.h>
#include <stdlib.h>
#define q_size 4

void cinsert_rear(int cq[],int item,int *r,int *count)
{
	if(*count==q_size)
	{
		printf("CQ is Full\n");
		return;
	}
	*r=(*r+1)%q_size;
	cq[*r]=item;
	(*count)++;
}

void cdelete_front(int cq[],int *f,int *r,int *count)
{
	if(*count==0)
	{
		printf("CQ is empty\n");
		return;
	}
	printf("item deleted =%d",cq[*f]);
	*f=(*f+1)%q_size;
	if(*f>*r)
	{
		*f=0;
		*r=-1;
	}
	(*count)--;
}

void display(int cq[],int f,int count)
{
	int i,t;

	if(count==0)
	{
		printf("Cq is empty\n");
		return;
	}
	t=f;
	for(i=1;i<=count;i++)
	{
		printf("%d",cq[t]);
		t=(t+1)%q_size;
	}
}

void main()
{
	int choice; //switch
	int item;//element to be inserrted
	int f=0; //front end
	int r=-1; //rear end
	int count=0;//indicates CQ is ,empty
	int cq[10];

	for(;;)
	{
		printf("\n1:insert 2:delete 3:display 4:exit\n");
		printf("Enter choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				cinsert_rear(cq,item,&r,&count);
				break;

			case 2: cdelete_front(cq,&f,&r,&count);
				break;

			case 3: display(cq,f,count);
				break;

			case 4:exit(0);
		}
	}
}

/*Multiple Queues:Multiple Queues concept is implemented using single
dimensional araay.
->The following diagrams,illustrations gives complete infromation about
multiple queues.
-> consider the ordinary queue
-> Queue consits of two ends ,front ene and rear end

 Q_empty:
	f
	0   1    2   3   4
	......................
 q	|   |   |   |    |   |
	......................
   r=-1
 Q_full:
	 f
	 0     1    2     3    4
	...........................																																															................
 q	|  5 | 10  | 15  | 20 |25  |
	...........................
			       r
 -> From the above diagram it is clear that there is need of two ends front
 and rear,
 ->for Multiple queue there is need of array of front  and rear.

 -> Consider the array with size 20

	    Queue1           Queue2        Queue3          Queue4
	       |                |            |                |
	       |                |            |                |
boud[0]=-1  bound[1]=4      bound[2]=9     bound[3]=14       bound[4]=19
	0  1  2   3  4| 5   6  7    8   9  |10 11 12 13 14| 15  16 17 18  19
       ................................................................
ms     |  |  |  |  |  | 2 | 3 | 4 | 5  |6  |  |  |  |  |  |  |   |  |  |   |                       |
       ................................................................
       |	      |               |              |
    f[0]=0	     f[1]=5           f[2]=10        f[3]=15
    r[0]=-1          r[1]=9           r[2]=9         r[3]=14

Creation of f[] and r[] and boundar[]
n->no of queues

	for(j=0;j<n;j++)
	{
		boundary[j]=f[j]=r[j]=(Max_size/n)*j-1;
	}

	boundary[]  | -1 | 4 | 9 |14 | 19 |

	       f[]  | -1 | 4 | 9 |14 | 19 |

	       r[]  | -1 | 4 | 9 |14 | 19 |
careation f[] araay

	for(j=0;j<n;j++)
	{
		f[j]=f[j]+1;
	}
After this loop array f[],r[],boundray will apper as shown below.

	boundary[]  | -1 | 4 | 9 |14 | 19 |

	       f[]  | 0 | 5 | 10 |15 | 20 |

	       r[]  | -1 | 4 | 9 |14 | 19 |


Assume we are working with 2nd queue:
-> varible i keeps track particular Q.
->i=1 //indicatea 2nd queue

Q_full Condition:  Q_full condition is given below
		if(r[i]==boundary[i+1])
		{
			printf("i=%d",i);
			printf("Q full");
			return;
		}
		r[i]++;
		mq[r[i]]=item;



Q_empty Condition:  Q_empty conditon is given below
	if(r[i]==boundary[i])
	{
		printf(" the i the Q is empty%d",i);
		return;
	}
	item_deleted=q[f[i]];
	f[i]--;
	if(f[i]>r[i])   // if f excedes r        if(f>r) {f=0 r=-1
	{
		r[i]=boundary[i];
		f[i]=boundary[i]+1
	}
	printf("The deleted_item%d",item_deleted);


Display_funciton:
	if(r[i]==boundary[i])
	{
		printf(" the i the Q is empty%d",i);
		return;
	}
	for(j=f[i];j<=r[i];j++)
	{
		printf("%d",mq[j]);
	}
*/

#include <stdio.h>
#include <stdlib.h>
#define Max_size 20

int mq[Max_size];//size of ms array is 20
int f[Max_size];
int r[Max_size];
int boundary[Max_size];
int n;//No of stacks required
int item;// item to be inserted
int i;//Indicates particular stack

void insert()
{
	printf("Enter the item\n");
	scanf("%d",&item);

	if(r[i]==boundary[i+1])
	{
		printf("i=%d",i);
		printf("Q full");
		return;
	}

	r[i]++;
	mq[r[i]]=item;
}

void delet()
{
	int item_deleted;

	if(r[i]==boundary[i])
	{
		printf(" the i the Q is empty%d",i);
		return;
	}

	item_deleted=mq[f[i]];
	
        printf("The deleted_item%d",item_deleted);

	f[i]++;

	if(f[i]>r[i])   // if f excedes r        if(f>r) {f=0 r=-1
	{
		r[i]=boundary[i];
		f[i]=boundary[i]+1;
	}
}

void display()
{
	int j;
	if(r[i]==boundary[i])
	{
		printf(" the i the Q is empty%d",i);
		return;
	}
	printf("Elements\t");
	for(j=f[i];j<=r[i];j++)
	{
		printf(" %d\t",mq[j]);
	}
}

void main()
{
	int choice;//switch
	int j;//creation of multiple stacks

	printf("Enter No of queues required\n");
	scanf("%d",&n);

	for(j=0;j<n;j++)
	{
		boundary[j]=f[j]=r[j]=(Max_size/n)*j-1;
	}

	for(j=0;j<n;j++)
	{
		f[j]=f[j]+1;
	}

	for(;;)
	{
		printf("Queues available\n");

		for(j=0;j<n;j++)
		{
			printf("%d\t",j);
		}

		printf("enter the Queue no\n");
		scanf("%d",&i);

		printf("1:insert\n 2:delete\n 3:display\n 4:exitn");
		printf("Enter the choice\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: insert();
				break;

			case 2: delet();
				break;

			case 3: display();
				break;

			case 4: exit(0);

		}
	}
}
//Note: At a time user can work with once  Queue

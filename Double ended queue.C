/*Double Ended Queue: Double ended Queue is queue allows the user to insert
and delete from both the ends.
-> Ordinary Queue consists of two ends,
    . front end-> Deleton from front end.
    . rear end -> insertion from rear end

->In double eneded Queue user insert either from frontend or from rear end.
->In double ended queue user can delete either from front end ot rear end.


case 0:
	   f
	 ................
	 | 5 |10|15|20|25|     -> insertion is not possible from rear end
	 ................ r    -> insertion is not possible from front end

	-> Deletion is possible from both the ends.
case 1:
	   f
	 ................
	 |  |  |   |    |     -> deletion is not possible from rear end
	 ................     -> deletion  is not possible from front end
      r=-1
	-> Insertion is possible from both the ends.



case 2: insertionf from front end
		 f
	   0  1	 2  3  4
	 ................
	 |  |  | 5 |20|25|     -> insertion is not possible from rear end
	 ................ r    -> insertion is  possible from front end?

	-> yes, insertion is possible front end
	when insertion is not possible from end
		if(f==0)
		{
		    printf("Inesertion is not possible from front end\n");
		}
		f--;
		q[f]=item;

case 3: deletion from rear end.
		 f
	    0  1 2  3  4
	 ................
	 |  |  | 5 |20|25|     -> deletion is  possible from rear end?
	 ................ r    ->

		  item_dele=Q[r];
		  r--;

		 f
	    0  1 2  3  4
	 ...............
	 |  |  | 5 |20| |
	 ...............
		    r
		  item_dele=Q[r];
		  r--;
  */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define Q_size 5
void insert_front(int q[],int item,int *f)
{
	if(*f==0)
	{
		printf("Front insertion is not possible\n");
		return;
	}
	(*f)--;
	q[*f]=item;
}
void delete_rear(int q[],int *f,int *r)
{
	int item_del;
	if( *f>*r)
	{
		printf("Q is empty\n");
		return;
	}
	item_del=q[*r];
	(*r)--;
	printf("Item_deleted=%d",item_del);
}
void insert_rear(int q[],int item,int *r)
{
	if(*r==Q_size-1)
	{
		printf("Q full rear insertion is not possible\n");
		return;
	}
	*r=*r+1;
	q[*r]=item;
}
void delet_front(int q[],int *f,int *r)
{
	int item_del;
	if(*f>*r)
	{
		printf("Q empry\n");
		return;
	}
	item_del= q[*f];
	(*f)++;
	printf("item_del=%d",item_del);
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
	clrscr();

	for(;;)
	{
		printf("1:insert_rear\t 2:delete_front\n");
		printf(" 3: insert_front\t 4:delete_rear\n");
		printf("5:diplay\t 6:exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the element to be inser\n");
				scanf("%d",&item);
				insert_rear(q,item,&r);
				break;

			case 2: delet_front(q,&f,&r);
				break;

			case 3: printf("Read item\n");
				scanf("%d",&item);
				insert_front(q,item,&f);
				break;

			case 4: delete_rear(q,&f,&r);
				break;

			case 5: display(q,f,r);
				break;
			case 6:exit(0);

		}
	}

}


/*
Definition of stack: A stack is a data structure where elements are inserted
and deleted fom the same end.

Stack is  FiLO or LIFO  data strcture
LIFO-> Last in first out data struture
FILO-> First in Last out data struture

A stack is an ordered collecction of items, which allows the insertion and
deletion from one end called top of the stack.

Example:1.  books kept one over another
	2.  Biscuits paked and ane side open


Operations on stacks
1. Push -> Insert operation
2. pop  -> Delete operation
3. Display -> Function display only display the elements of the stack.
*/
// array implementation of stack

#include <stdio.h>
#include <stdlib.h>
#define ssize 5   // stack size

void push(int a[],int *top,int ele)
{
     // check for overflow conditon
     if(*top==ssize-1)
     {
		printf("stack overflow\n");
		return;
     }

     (*top)++;	 // *top is 0
     a[*top]=ele;
}
void pop(int a[],int *top)
{
	int ele;
	// check for underflow condition
	if(*top==-1)
	{
		printf("stack Under flow");
		return;
	}
	ele= a[*top];
	(*top)--;
	printf("The element deleted%d\t",ele);

}
void display(int a[],int top)
{
	int i;
	if(top==-1)
	{
		printf("stack Under flow");
		return;
	}
	printf("Stack contents are\n");
	for(i=0;i<=top;i++)
	{
		printf("%d",a[i]);
	}

}

void main()
{
	int a[ssize];  // array a is acting as a stack
	int top=-1;    // top acts as index to stack, always points to
			// stack top
	int ele;      // elemenet to be inserted in push funciton
	int choice;   // For switch operation
	int dele;

	for(;;)
	{
		printf("press1:Push\n2:pop\n3:display4:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the ele to be inserted\n");
				scanf("%d",&ele);
				push(a,&top,ele);// psuh operation changes top CR
				break;

			case 2: pop(a,&top);
				break;
			case 3: display(a,top);
				break;
			case 4: exit(0);

		}

	}


}















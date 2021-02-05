/*3.Design Develop and Implement a menu driven program in C for the following
operations on stack.
1.push the element
2.pop the element
3. Display the elements of stack
4.Demonstrate how the stack can be used to check pailndrome.
5. Demonstrate overflow and underflow cond
6. exit   */

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

/*
stack conssits of

top->       a[4] | 5 |       0  1  2  3  4          	0  1  2   3  4
	    a[3] | 4 |   a[] 2  8  6  4  5   	temp[]  5  4  6   8  2
	    a[2] | 6 |
	    a[1] | 8 |
	    a[0] | 2 |


  */
int cpalindrome(int a[],int top)
{
	int i;
	int temp[ssize];
	int count=0;

	for(i=0;top>=0;i++)
	{
	      temp[i]= a[top];
	      top--;
	      count++;
	}
	// count=5


	for(i=0;i<count;i++)
	{
		if(a[i]!=temp[i])
			return -1;
	 }
	 return 1;
}

void main()
{
	int a[ssize];  // array a is acting as a stack
	int top=-1;    // top acts as index to stack, always points to
			// stack top
	int ele;      // elemenet to be inserted in push funciton
	int choice;   // For switch operation
	int dele;
	int flag; // flag=1 pal flag=-1 not pal

	for(;;)
	{
		printf("press1:Push\n2:pop\n3:display\n4:cpalindrome 5:exit\n");
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
			case 4: flag=cpalindrome(a,top);
				if(flag==-1)
					printf("Not a pailndrome\n");
				else
					printf("pailndrome\n");
				break;
			case 5: exit(0);

		}

	}


}

/*Multiple Stacks:
	Multiple stack can be implemented using single diemensional arrays.

  Note: Array is divided as Multiple stacks.
-> consider the following are
     0  1  2   3 4  5   6 7   8  9  10 11 12 13 14 15  16 17 18  19
    ................................................................
ms  |  |  |  |  |  |  |  |  |   |  |  |  |  |  |  |  |   |  |  |   |                       |
    ................................................................
ms-> multiple stack


-> Assume size of the each stack is 5, with the available array we can
create 4 stacks.

-> top[n] //n-> is no of stack user want n=4
-> boundray[n] // Indicates boudray of each stack.

First job of the programmer is creation of stacks. Formula to split the
array in to 4 stacks
	for(j=0;j<=n;j++)
	{
		boundray[j]=top[j]=Max_size/n*j-1; assume max_size is 20
		// it is the size of the array
	}

 ** Tracing for the above fromula***
	boundry[0]=top[0] = 20/4*0-1 =  -1
	boundry[1]=top[1] = 20/4*1-1 =  5-1  ->4
	boundry[2]=top[2] = 20/4*2-1 =  10-1 ->9
	boundry[3]=top[3] = 20/4*3-1 =  15-1 ->14
	boundry[4]=top[4] = 20/4*0-1 =  20-1 ->19


-> After the partition:


	    stack1           stack2        stack3          stack4
	       |                |            |                |
	       |                |            |                |
boud[0]=-1  bound[1]=4      bound[2]=9     bound[3]=14       bound[4]=19
	0  1  2   3  4|5  6  7   8  9 |10 11 12 13 14| 15  16 17 18  19
       ................................................................
ms     |  |  |  |  |  |  |  |  |   |  |  |  |  |  |  |  |   |  |  |   |                       |
       ................................................................
		      |               |              |
top[0]=-1     top[1]=4        top[2]=9       top[3]=14       top[4]=19

			  0     1    2    3     4
			..........................
	   top	  	| -1  | 4  | 9  | 14  |  19 |
			...........................
			   0     1    2    3     4
			  ..........................
	   boundray	  | -1  | 4  | 9  | 14  |  19 |
			   ...........................
*** How to check stack empty and stack full condtion for each stack.***
    ...............................................................
consider stack 2:

			    bound[2]=9
	0  1  2   3  4|5  6  7   8  9 |10 11 12 13 14| 15  16 17 18  19
       ................................................................
ms     |  |  |  |  |  |2 |3 |4 | 5 |6 |  |  |  |  |  |  |   |  |  |   |                       |
       ................................................................
		      |               |              |
				top[1]=9



     assumw     i=1
	      top[i]++;   //top[i]=9
	      ms[top[i]=item

stack Full condition in multiple stack:
.......................................

	    if(  top[i]==boundary[i+1])
	    {
		printf("ith stack is full);
	    }


stack empty condtion in multiple stack:
.....................................
	if(top[i]==boundray[i])
	{
		printf("i the stack is empty\n");
	}
stack display() :
................

for(j=boundary[i]+1;j<=top[i];j++)
{
	printf("%d",ms[j]);
}

Note:selection of the stack must be user choice*/
//programming example:

#include <stdio.h>
#include <stdlib.h>
#define Max_size 20

int ms[Max_size];//size of ms array is 20
int top[Max_size];
int boundary[Max_size];
int n;//No of stacks required
int item;// item to be inserted
int i;//Indicates particular stack


void push()
{
	printf("Enter the element to be inserted\n");
	scanf("%d",&item);
	if(  top[i]==boundary[i+1])
	{
		printf("i=%d\t",i);
		printf("the stack is full");
		return;
	}
	top[i]++;
	ms[top[i]]=item;
}
void pop()
{
	int item_deleted;
	if(top[i]==boundary[i])
	{
		printf("i=%d",i);
		printf(" the stack is empty\n");
		return ;
	}
	item_deleted=ms[top[i]];
	printf("item_deleted=%d",item_deleted);
	top[i]--;
}
void display()
{
	int j=0;
	if(top[i]==boundary[i])
	{
		printf("i=%d",i);
		printf(" the stack is empty\n");
		return ;
	}
	for(j=boundary[i]+1;j<=top[i];j++)
	{
		printf("%d\t",ms[j]);
	}

}

void main()
{
	int choice;//switch
	int j;//creation of multiple stacks


	printf("Enter No of stacks required\n");
	scanf("%d",&n);

	for(j=0;j<=n;j++)
	{
		boundary[j]=top[j]=Max_size/n*j-1;// assume max_size is 20
		// it is the size of the array
	}
	for(;;)
	{
		printf("stacks available\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",j);
		}
		printf("enter the stack no\n");
		scanf("%d",&i);
		printf("1:push 2:pop 3:display\ 4exitn");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();
				break;

			case 2: pop();
				break;

			case 3: display();
				break;

			case 4: exit(0);

		}


	}

}
//Note: At a time user can work with only one stack




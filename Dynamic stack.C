/*stack using Dynamic arrays: Stack is LIFO data structure.
-> stack is data structure where insertion and deletion can be at one end .
-> index "top" always pointer to top of the stack or elements which is
recently inserted.
-> the Dynamic array instructs the programmer to use "Memory hadling
functions( malloc(),calloc(),realloc(),free()"
->opeartion with the stacks
1. Push()
2. pop ()
3. display ()

How dynamic stack is different from normal stacks=?
-> W R T to pop opeation and display operation there is no difference between
normal stack and dynamic stack.
-> Dynamic stack  is different from stack(normal) W R T to push operation.

-> The below diagram shows normal stack with size 5
#define stack_size 5

	top
	  4 | 25 |      is it possible to insert 30 Y/N
	  3 | 20 |      ans: is No because *stack overflow cond*  push is not
	  2 | 15 |           possible
	  1 | 10 |
	  0 | 5  |

       Fig:noraml stack (ordinary stack)
-> The below fig shows *dynamic stack*

top
	  4 | 25 |  stack  reached *overflow cond*
	  3 | 20 |  **In dynamic stack when overflow codition occurs
	  2 | 15 |    stack doubles it capacity**
	  1 | 10 |
	  0 | 5  |
	  *when user tries to enter any element with stack overflow condition
	  stack doubles its capacity**
	  -> user it trying to insert 30
  * The below fig show douled stack capcity

	  9|    |
	  8|    |      **Now can store 4 more elements**
	  7|    |
	  6|    |
   top	  5| 30   |
	  4| 25   |
	  3| 20   |
	  2| 15   |
	  1| 10   |
	  0| 5   |


 -> this is process repeats.

 Note:Dynamic stack Infinite stack where overflow conditon will not occur*/

#include <stdio.h>
#include <alloc.h>
#include <stdlib.h>

//  concept of structure  is used
//  malloc and realloc fucniton are used to allocate the memroy
//dynamically

struct stack
{
	int key;
};
typedef struct stack element; //typedef is usedt to create alais data type
//struct stack is real data type (derived data type)
// element acts as alais data type.

element* stackFull(element *stack,int *capacity)
{
	 printf("Wait stack is getting doubled\n");
	 stack=(element*)realloc(stack,2*(*capacity)*sizeof(element));
	 (*capacity)=(*capacity)*2; //*capacity=4
	 return stack;


}

   //Function Returning pointer
// Function retures address as return value
//In this case  Fucniton returns address of structure varible
//*capcity represents the capacity of the stack
element* push(element *stack,int *top,int item,int *capcity)
{
	if(*top>=(*capcity)-1) // 3>=3    // stack should get doubled
	//beacuse it has reached overflow codition
	{
	   // This is palce to doule the capacity
	   // the programmer has to write a code to doubles
	   stack=stackFull(stack,capcity);//Fucntion stack full dobles the
	}
	(*top)++;
	(stack+*top)->key=item;
	return stack;

}
int pop(element *stack,int *top)
{
	int item_del;
	if(*top==-1)
	{
		printf("stack underflow\n");
		return -1;
	}
	item_del=((stack+*top))->key;
	(*top)--;
	return item_del;
}
void display(element *stack,int top)
{
	int i;
	if(top==-1)
	{
		printf("stack underflow\n");
		return ;
	}
	for(i=top;i>=0;i--)
	{
		printf("\t%d",(stack+i)->key);
	}

}
void main()
{
	int top=-1;
	int capacity=1; // in the begining stack can have only one element
	int item; // represents the items to be inserted
	int choice;//Menu purpose
	int item_deleted;// varible used in pop() funciton
	element *stack; //pointer to structure.
	//sizeof the element is 2 bytes



	stack=(element*)malloc(sizeof(element)*capacity);
	// 2 bytes of memory allocated and its base address is stored
	//in pointer stack.
	if(stack==NULL)
	{
	    printf(" Moemory not suff...\n");
	    exit(0);
	}
	for(;;)
	{
		printf("1:push 2:pop 3:display 4:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{

		       case 1: printf("Enter the element to be inserted\n");
			       scanf("%d",&item);
			       //it should structure pointer
			       stack=push(stack,&top,item,&capacity);
			       break;

		       case 2: item_deleted=pop(stack,&top);
			       if(item_deleted!=-1)
			       {
					printf("Deleted item %d",item_deleted);
			       }
			       break;


		       case 3:display(stack,top);
			      break;

		       case 4:exit(0);

		}

	}


}


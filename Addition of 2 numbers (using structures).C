/*Structurs And Functions: For structures to be fully useful, we must be able
to pass them as parameter t to a fucntion and return them from the functions.

->This concept mainly concentrates on passing structure as a parameter.
->The structures or structure members can be passed to the function in varios
	ways
	1. By passing members of structure
	2. By passing whole structure as parameter
	3. By passing structure through pointer.

1. passing structure member as parameter:
->passing structure members as parameter as shown below. Consider the
program to add two numbers to illustrate structure member as parameter

#include <stdio.h>

struct sum
{
	int x;
	int y;
};
typedef struct sum s;

int add(int a,int b)
{
     return (a+b);
}

void main()
{
	s a;
	int total;

	printf("Enter the values for a &b\n");
	scanf("%d%d",&a.x,&a.y);  // reading the varibles for structure mem
	total=add(a.x,a.y);
	printf("%d",total);

}

 passing entire structure as paramter:passing structure varible as parameter
 called as passing structure varibel as paramter
#include <stdio.h>

struct sum
{
	int x;
	int y;
};
typedef struct sum s;

int add(s a)
{
     return (a.x)+(a.y);
}

void main()
{
	s a;
	int total;

	printf("Enter the values for a &b\n");
	scanf("%d%d",&a.x,&a.y);  // reading the varibles for structure mem
	total=add(a);
	printf("%d",total);

}
passing structre thorugh pointers:Instead of passing struture as parameter
, we can also pass address of the structure varible parameter.
-> passing address of the structure varible is called passing structure
   through pointers. */

#include <stdio.h>

struct sum
{
	int x;
	int y;
};
typedef struct sum s;

int add(s *p)
{
     return (p->x)+(p->y);
}

void main()
{
	s a;
	int total;

	printf("Enter the values for a &b\n");
	scanf("%d%d",&a.x,&a.y);  // reading the varibles for structure mem
	total=add(&a);
	printf("%d",total);

}


POINTER TO STRUCTURES: Pointer to structure is implementd by assigning the
address of the struture varible to a pointer.
-> At this concept pointer is of type derived.
-> By using (->) Arrow operator we can access structure member using
   pointers.
-> General syntax to create pointer structure

	struct struct_name
	{
		dt var1;
		dt var2;
		dt var3;
	};
	struct struct_name s1,*p;
	//*p- > is called as pointer to structure.


-> General synatx to access a member using a pointer
     pointer to structure(varible) ->  stucture_member

				Arrow operator
// Programming example:
#include <stdio.h>

void main()
{
	struct student
	{
		char usn[11];
		char name[20];
		int marks;
	};
	struct student *cs,a; //*cs structue pointer

	int a;
	int *p

}















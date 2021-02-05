/* Accessing Structure member:  strcture member is accessed using
 dot(.)operator.

-> program to access structure variables
-> meaning of access is reading or writing
-> Reading is done in ways.
	1. Initialization
	2. Reading from keyboard

 */
#include <stdio.h>

void main()
{

	struct student
	{
		char usn[11];  // memroy will not be allocated for its members
		char name[20];
		int marks;
	};
	typedef struct student s; //typedef // is used to create an alternate name or an alias name
		// for exititing data type
	// Reading structure member from key board
	s a,b;
	printf("Enter student a usn,name,marks\n");
	scanf("%s%s%d",a.usn,a.name,&a.marks);
	printf("Enter student a usn,name,marks\n");
	scanf("%s%s%d",b.usn,b.name,&b.marks);
	printf("\USN ****  Namme ***** Marks***\n");
	printf("%s\t%s\t%d\n",a.usn,a.name,a.marks);
	printf("%s\t%s\t%d\n",b.usn,b.name,b.marks);
}
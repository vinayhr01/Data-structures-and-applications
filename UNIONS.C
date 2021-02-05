/*Unions:
	The union is a construct that allows the memory to be shared by
	differnet  types of data.
	-> A union is a derived data type like a structure
	-> similar to structure union will also have structure members.
	->The union is similar to structure with respect to definition
	and declaration, but the size of the memory allocated to union
	varible is same as of the size of the union member which occupies
	the maximum space.    */

	#include <stdio.h>

	void main()
	{
		union student
		{
			char usn[10];
			char name[20];
			int marks;
		};
		union student s; // s is a union varible
		// memory will be allocated
		// Memory allocated to s will be 20 bytes

       // Note: at a time union allows to work with one member

		printf("Enter USn\n");
		scanf("%s",s.usn);
		printf("USN= %s\t",s.usn);

		printf("Enter Name\n");
		scanf("%s",s.name);
		printf("USN= %s\t",s.name);

		printf("Enter Marks\n");
		scanf("%d",&s.marks);
		printf("MARKS= %d",s.usn);

	}



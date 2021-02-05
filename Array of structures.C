Array of structure:Like an array of integers,array of characters,it also
possible to create array of structures.
-> This concept allows us to represent array of related records.
-> Declaration of array of structure is shown below.

    Genenral format
	struct struct_name
	{
		dt var1;
		dt var2;
		dt var3;
	};
	struct struct_name s1[10];   // s1 array acts as array of structures

    -> member of array structure can be accessed like

    int a[10]
	 &a[i]

    s.var1;
    s1[i].var1
->let us constrct student infoamtion like usn,name and age to represent
  array of structures.



-> programming example is given below.*/
#include <stdio.h>

void main()
{
	struct student
	{
		char usn[11];
		char name[20];
		int marks;
	};
	struct student s,cs[10];
	int i,n;

	// s structure varible allocates 33 bytes
	// cs[10] allocates 33*10=330 bytes

	printf("Enter the no recods\n");
	scanf("%d",&n);
	printf("Enter the student details\n");
	for(i=0;i<n;i++)
	{
		scanf("%s%s%d",cs[i].usn,cs[i].name,&cs[i].marks);
	}

	printf("Details are\n");
	printf("USN **** NAME **** MARKS\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%s\t%d\n",cs[i].usn,cs[i].name,cs[i].marks);
	}


}


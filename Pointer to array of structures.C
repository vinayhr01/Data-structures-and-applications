/*POINTER TO ARRAY OF STRUCTURES:Pointer to Array of structure is implementd by assigning the
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
	struct struct_name s1[10],*cs;
	//*p- > is called as pointer to structure.

->assigning takes by
	cs=s1;


-> General synatx to access a member using a pointer
     (pointer to structure+index) -> structure_member
			(cs+i)->var1


				Arrow operator
// Programming example:                 */
#include <stdio.h>

void main()
{
	struct student
	{
		char usn[11];
		char name[20];
		int marks;
	};
	struct student *cs,a[10]; //*cs structue pointer
	int i,n;

	cs=a;
	printf("Enter the no of records\n");
	scanf("%d",&n);
	printf("Enter the details\n");
	for(i=0;i<n;i++)
	{
		scanf("%s%s%d",(cs+i)->usn,(cs+i)->name,&(cs+i)->marks);
	}

	printf("USN *****NAME  **** MARKS\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%s\t%d\n",(cs+i)->usn,(cs+i)->name,(cs+i)->marks);
	}



}















/*Design Develop and Implement a menu driven program in C for the following
Array operations.
a. Creating an Array of N Integer elements.c
b. Display of Array elements with Suitable Headings
c. Inserting an Element at a given valid position
d. Deleting an element at a given valid postiion
e. exit    */

#include <stdio.h>
#include <stdlib.h> // includes exit(0) fucntion
#define size 50

void create(int [],int );   //Creating an Array of N Integer elements.
void display(int [],int);  //Display of Array elements with Suitable Headings
void insert_pos(int [],int *,int ,int ); //Inserting an Element at a given valid position
void delete_pos(int [],int *,int ); // Deleting an element at a given valid postiion

void main()
{
	int a[size];
	int i;//looping purpose
	int choice;//crate a menu switch statement so choice varible
	int n; // no of elements user interested in
	int ele;//elelemnt  to be inserted at vailed postion
	int pos;//user input specfites a element in a given postition


	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	create(a,n);
	for(;;)//infinite loop and menu creation
	{
		printf("press 1.display\n2:Insert_ele_pos\n 3:Delete\n4:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{

			case 1: display(a,n);
				break;

			case 2: printf("Enter the element to be inserted\n");
				scanf("%d",&ele);
				printf("Enter tthe postion for insertion\n");
				scanf("%d",&pos);
				insert_pos(a,&n,ele,pos);
				break;

			case 3: printf("Enter the position for deletion\n");
				scanf("%d",&pos);
				delete_pos(a,&n,pos);
				break;

			case 4:exit(0);




		}
	}
}

void create(int a[],int n)
{
	int i;
	printf("Enter array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void display(int a[],int n)
{
	int i;
	printf("Array elements\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

void insert_pos(int a[],int *n, int ele,int pos)
{
	int i;
	if(pos>*n+1)
	{
	       printf("invalied position\n");
	       return; // just the key word  returns the contol to the
		       //calling fucntion
	}
	for(i=*n-1; i>=pos-1;i--)      //i=7   8>=8-1 (7)
	      a[i+1]=a[i];
	a[pos-1]=ele;
	*n=*n+1;
	printf("Array elements after insertion\n");
	for(i=0;i<*n;i++)
		printf("%d\t",a[i]);
	printf("\n");

}

void delete_pos(int a[],int *n,int pos)
{
	int i;
	if(pos>*n)
	{
		printf("Invalied postion\n");
		return;
	}
	for(i=pos-1;i<*n-1;i++) // pos=7   i=8   8 < 9
		a[i]=a[i+1];
	*n=*n-1;
	printf("Array elements after deletion\n");
	for(i=0;i<*n;i++)
		printf("%d\t",a[i]);
	printf("\n");


}

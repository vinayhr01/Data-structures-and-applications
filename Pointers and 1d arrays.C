/Pointer and Arrays:                         =
......................
In pointer we store address,In arrays we store elements.
-> Pointer holds the adress
-> Name of the array holds the address
-> array name is called as constant pointer.

Note: At any point of time array can be replaced by a pointer.

// One Dimensional Array
int a[10];
assume a=1000 // base address of  the array or address of 0th location

&a[0]  ->    (a+0)       a[0]  ->  *(a+0)
&a[1]  ->    (a+1)       a[1]  ->  *(a+1)
&a[2]  ->    (a+2)       a[2]  ->  *(a+2)
&a[3]  ->    (a+3)       a[3]  ->  *(a+3)
&a[4]  ->    (a+4)       a[4]  ->  *(a+4)
&a[5]  ->    (a+5)       a[5]  ->  *(a+5)

// Two Dimensional Array

int a[3][3];
assume a=5000
// First Row
&a[0][0] ->  ((a+0)+0)
&a[0][1] ->  ((a+0)+1)
&a[0][2] ->  ((a+0)+2)
// Second Row
&a[1][0]  ->  ((a+1)+0)
&a[1][1]  ->  ((a+1)+1)
&a[1][2]  ->  ((a+1)+2)
// Third Row
&a[2][0]  ->  ((a+2)+0)
&a[2][1]  ->  ((a+2)+1)
&a[2][2]  ->  ((a+2)+2)

In general
&a[i][j]    -> ((a+i)+j)    -> *(*(a+i)+j)

3rd arrays
&a[i][j][k] -> (((a+i)+j)+k)   -> *(*(*(a+i)+j)+k)

//porgram to read and print array elemtns using pointer

#include <stdio.h>

void main()
{
	int a[10];  // array
	int n; // No. of elements
	int i; // index variable

	printf("Enter n elements\n");
	scanf("%d",&n);
	printf("Read Array elements\n");
	for(i=0;i<n;i++)
	{
	     scanf("%d",(a+i));
	}
	printf(" Array elements are\n");
	for(i=0;i<n;i++)
	{
	     printf("\t%d\t",*(a+i));
	}

}                                          */
// program to read and read and print array elements using function and
//pointer
#include <stdio.h>
void read(int *,int );
void print(int *,int );

void main()
{
	int a[10];  // array
	int n; // No. of elements
	int i; // index variable

	printf("Enter n elements\n");
	scanf("%d",&n);
	read(a,n);
	print(a,n);

}
void read(int *p,int n)
{
	int i;
	printf("Read Array elements\n");
	for(i=0;i<n;i++)
	{
	     scanf("%d",(p+i));
	}
}
void print(int *p,int n)
{
	int i;
	printf(" Array elements\n");
	for(i=0;i<n;i++)
	{
	     printf("\t%d",*(p+i));
	}
}











Pointer and Arrays:                         =
......................
In pointer we store address,In arrays we store elements.
-> Pointer holds the adress
-> Name of the array holds the address
-> array name is called as constant pointer.

Note: At any point of time array can be replaced by a pointer.

// Two Dimensional Array

int a[3][3];
assume a=5000
// First Row
&a[0][0] ->  (*(a+0)+0)  to get the value -> *(*(a+0)+0)
&a[0][1] ->  (*(a+0)+1)                   -> *(*(a+0)+1)
&a[0][2] ->  (*(a+0)+2)
// Second Row
&a[1][0]  ->  (*(a+1)+0)
&a[1][1]  ->  (*(a+1)+1)
&a[1][2]  ->  (*(a+1)+2)
// Third Row
&a[2][0]  ->  (*(a+2)+0)
&a[2][1]  ->  (*(a+2)+1)
&a[2][2]  ->  (*(a+2)+2)                  -> *(*(a+2)+2)

In general
&a[i][j]    -> ((a+i)+j)    ->to get a content *(*(a+i)+j)

3rd arrays
&a[i][j][k] -> (((a+i)+j)+k)   -> *(*(*(a+i)+j)+k)


#include <stdio.h>

void main()
{
	int a[10][10];
	int i,j; //looping purpose
	int m,n;// row size, column size

	printf("Read order of the matrix\n");
	scanf("%d%d",&m,&n);
	printf("Read array elements\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",(*(a+i)+j));;
		}
	}
	printf("array elements are\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",*(*(a+i)+j));;
		}
	}


}

// program to replace 2d array by pointer using fucntions

#include <stdio.h>
#include <conio.h>

//Function Declaration
void read(int [][10],int *,int *);  // m and n are changeing use call
void print(int [][10],int ,int );     // by address
void sum(int [][10],int,int);

void main()
{
	int a[10][10];
	int m,n;//row and column

	 read(a,&m,&n);
	 sum(a,m,n);
	 print(a,m,n);
}

// Function Definition
void read(int a[][10],int *m,int *n)
{
	int i,j;

	printf("Enter m and n");
	scanf("%d%d",m,n);
	printf("Read array elements\n");
	for(i=0;i<*m;i++)
	{
		for(j=0;j<*n;j++)
		{
			scanf("%d",(*(a+i)+j));
		}
	}

}
void sum(int a[][10],int m,int n)
{
	int i,j;
	int sum=0;

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
		     sum=sum+*(*(a+i)+j);
		}
	}
	printf("sum=%d\n", sum);


}
//Function Definition
void print(int a[][10],int m,int n)
{
	int i,j;
	printf(" array elements\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",*(*(a+i)+j));;
		}
		printf("\n");
	}
}






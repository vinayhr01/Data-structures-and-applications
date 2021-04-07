/*how to pass 1d array as a parameter ?
1d is passed as a paramter by using its name.
similarly 2d array is also passed as parameter by using its name.
->Name of the 2d array holds base address.
->passing 2d array as a parameter is by default "pass by address"*/

//program to two add two 2d arrays.
#include <stdio.h>

void read(int [][],int [][],int,int);//First array,second array, row,col
void add(int [][],int [][],int [][],int ,int);//F arrray,s array, R array,Row,Col
void print(int [][],int,int);//Resulatant array , Row,Col

void main()
{
	int a[10][10]; // First array
	int b[10][10]; // Second array
	int c[10][10];  // Resulttant array
	int m,n;      // Rows and Columns

	int i,j;  // Looping purpose

	read(a,b,&m,&n);
	add(a,b,c,m,n);
	print(c,m,n);
}
// reads the array
void read(int a[][10],int b[][10],int *m,int *n)
{
	int i,j;
	printf("Read row and col\n");
	scanf("%d%d",&m,&n);
	printf("read array A elements\n");
	for(i=0;i<*m;i++)
	{
		for(j=0;j<*n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("read array B elements\n");
	for(i=0;i<*m;i++)
	{
		for(j=0;j<*n;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}


}

void add(int a[][10],int b[][10],int c[][10],int m,int n)
{
	int i,j;

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
}
void print(int a[][10],int m,int n)
{

	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",a[i][j]);
		}
	}
}




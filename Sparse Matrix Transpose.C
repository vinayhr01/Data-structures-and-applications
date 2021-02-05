Sparse Matrix: Sparse Matrix is one it consists of less no. of non zero
terms and more no. of zero terms


	col0   col1    col2   col3    col4    col5


  R0      15    0       0     22        0     -15

  R1      0    11       3      0	0      0

  R2      0     0       0      -6       0      0

  R3     91     0       0       0       0      0

  R4      0     0       28       0       0     0

		   martix with 5*5

-> to store above i need of of size a[5][5]
-> this wastes the memory,processing power  by storing zeros
	To overcome the above problem , the sparse matrix represetation  has introduced.

Sparse Matrix representaion :

 #define Max_Terms 101
 typedef struct
 {
	int Row;
	int Col;
	int value;
 }term; // data type
 term a[Max_Terms]; // a acts as array ofstrcture


 sparse Matrix Representation

	 Row   Col  Val

 a[0]     0      0   15
 a[1]     0      3   22
 a[2]     0      5   -15
 a[3]     1      1   11
 a[4]     1      2   3
 a[5]     2      3   -6
 a[6]     3      0   91
 a[7]     4      2   21


Transpose of Sparse Matrix:

A= 1 0 2       b= 1 4 3
   4 0 5          0 0 1
   3 1 0          2 5 0
	  3*3mat        3*3 mat

	  R   C   v
 a[0]	  3   3   6  //NR,NC,ND         R   C  V
 .......................
 a[1]     0   0   1               b[0]  3    3  6
				 ....................
 a[2]     0   2   2               b[1]  0    0  1
 a[3]     1   0   4               b[2]  0    1  4
 a[4]     1   2   5               b[3]  0    2  3
 a[5]    2   0   3                b[4]  2    0  2
* a[6]     2   1   1              b[5]  2   1   5
				  b[6]  2   1   1


 #include <stdio.h>
 #define Max 10
 typedef struct
 {
	int row,col,val;
 }t;
 void main()
 {
	 t a[Max],t b[Max];
	 int i,n;
	 printf("Enter row col and value\nSMR");
	 scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].val);
	 for(i=1;i<=a[0].value;i++)
		scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].val);
	 transpose(a,b)
	 printf( "ROW **COL *** val\n");
	 for(i=0;i<=a[0].value;i++)
		printf("%d%d%d",a[i].row,a[i].col,a[i].val);

}
 void transpose(t a[], t b[])
 {
	 int n,i,j,curb; // ccurrentb acts as indes to the array b
	 n=a[0].value;

	 b[0].row=a[0].col;
	 b[0].col=a[0].row;
	 b[0].val= n;

	 if(n>0)
	 {   curb=1;
			3
	     for(i=0;i<a[0].col;i++)      //i=2     ....3
	     {		     6
		  for(j=1;j<=n;j++)       //j=6    ....6
		  {
			if(a[j].col==i)   //a[j].col=2  i=2   //curb=6
			{
			      b[curb].row=a[j].col;
			      b[curb].col=a[j].row;
			      b[curb].val=a[j].val;
			      curb++;

			}
		  }
	     }
	 }
 }



FastTranspose of sparse Matrix:



Sparse Matrix Multiplication:



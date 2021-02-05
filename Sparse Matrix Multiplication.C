Sparse Matri Multiplication:

a= 1 2     b = 2 1     T newB=2 3    a*Tb   d= 8  9
   2 4         3 4            1 4              16 18

       R C V              R C V             R  C  V               R C V
 A[0]  2 2 4        B[0]  2 2 4       nB    2  2  4        D[0]   2  2 4
 ....................................................................
 A[1]  0 0 1        B[1]  0 0 2      nB[1]  0 0  2          D[1]  0 0 8
 A[2]  0 1 2        B[2]  0 1 1      nB[2]  0 1  3          D[0]  0 1 9
 A[3]  1 0 2        B[3]  1 0 3      nB[3]  1 0  1          D[0]  1 0 16
 A[4]  1 1 4        B[4]  1 1 4      nB[4]  1 1  4          D[0]  1 1 18
 A[5]  2                             nB[5]  2 0  X garbage
void MatrixMult(term a[],term b[],term d[])
{
	//Multiplication of two sparse matrix
	int i,j,colmn;
	int totalB=b[0].val;// 4
	int toatlD=0;
	int rowsA=a[0].row; //2
	int colsA=a[0].col;// 2
	int totalA=a[0].value;// 4
	int colsB=b[0].col // 2
	int rowBegin=1;
	int row=a[1].row;//0
	int sum=0; //0
	int newB[MAX_TERMS][3];

	if(colsA!=b[0].row)
	{

		printf("Incompitable matrixces \n");
		exit(0);
	}
	fastTranpose(b,newB);
	a[totalA+1].row=rowsA
	newB[toatlB+1].row=colsB
	newB[totalB+1].col=0;

		     4
	for(i=1;i<=totalA; )  //loop works for 4times i=1 2 3 1 2 3 1 2
	{
		column=newB[1].row; //0 0

				4+1
		for(j=1;j<=totalB+1; ) j=1 3 4 5 6 1
		{
			    0     0
		    if(a[i].row!=row)
		    {                0    0   1      8
		      storesum(d,&totalD,row,column,&sum);
		      i=rowBegin;  2    1
		      for(;newB[j].row==column;j++)
				;
		      column=newB[j].row;   //2

		    }               0     0
		    else if(newB[j].row!=column)
		    {
		       storesum(d,&totalD,row,column,&sum);
		       i=rowbegin;
		       column=newB[j].row;

		    }
		    else  switch(Compare(a[i].col,newB[j]].col))
		    {
			case -1: i++; //a[i].col<nb[j].col

			case 0: // a[i].col==nb[j].col
				sum=sum+ (a[i++].value*newB[j++].value);//garbage
				break;

			case 1: j++;//a[i].col> nb[j].col

		    }

		}
	}
	for(; a[i].row==row;i++)
	 ;
	rowbegin=i;
	row=a[i].row;
   }
   d[0].row=rowsA;
   d[0].col=colsB;
   d[0] .val=totalD

	}


}

void storesum(term d[],int *totalD,int row,int coulmn, int *sum)
{
	if(*sum)
	{
		if(toatlD<Max_terms)
		{
			d[++*toatlD].row=row;
			d[*toatlD].col=column;
			d[*totalD].val=*sum;
			*sum=0;
		}
	}
}
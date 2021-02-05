Fast Transpose of Sparse Matrix:The computer takes less time if
programmer uses this method of transposing.

a=  1  0  2     b= 1 4 3
    4  0  5        0 0 1
    3  1  0        2 5 0

	  R   C   v                          R  C  V
 a[0]	  3   3   6  /*NR,NC,ND*/    b[0]    3  3  6
 .......................             ...................
 a[1]     0   0   1                  b[1]   0	0  1			 ....................
 a[2]     0   2   2                  b[2]   0   1  4
 a[3]     1   0   4                  b[3]   0   2  3
 a[4]     1   2   5             *    b[4]   1   2  1
 a[5]     2   0   3                  b[5]   2   0  2
*a[6]     2   1   1                  b[6]   2   1  5

void fasttranspose(term a[],term a b[])
{
	int rowTerms[Max_cols]     ;    assume max_cols=3
	int spos[Max_cols] ;
	int i,j,no_cols=a[0].col; //  no_cols=3
	numTerms=a[0].val; // numTerms=6
	b[0].row= no_cols; // 3
	b[0].col=a[0].row; // 3
	b[0].val=a[0].val   //6
	     6
	if(numTerms>0)
	{                  3
		for(i=0;i<nocols;i++)               0 1 2
			rowTerms[i]=0; //rowTerms [ 3 1 2 ]
			    6
		for(i=1;i<=numTerms;i++) //i=6
			rowTerms[a[i].col]++//
					   0 1 2
		spos[0]=1; // startingpos [3 5 6 ]
			   3
		for(i=1;i<nocols;i++)        //i=2
		     spos[i]=spos[i-1]+rowTerms[i-1];//4+1
			      6
		for(i=1;i<=numTerms;i++)   //i =1  2  3 4  5  6
		{
			j=spos[a[i].col]++;//j=4
			b[j].row= a[i].col;
			b[j].col= a[i].row;
			b[j].val= a[i].val;
		}

	}

}
/*syllubas to be covered:
1. poly add
2. sparse matrix
3. sparse matrix represeantion
4. trapose using sparse
5. fasttranspose using sparse
6. sparse Matrxi multiplicaton

strings
definition
string operation ,strcat,sprcpy,strrev,strlen,strcmp
using builtin and without using builtin */


polynomial Representation and Addition:
consider the polynomial
	 3   2
	x +2x +x

 -> x is  common variable. so importancce is given for exponent and co-eff
 -> structure represenation of polynomial is shown below.
 -> coeff can be floating no.

/* #define max_terms 100
 struct poly
 {
	float coeff;
	int expo

 };
 typedef struct poly POLYNOMIAL;      */


  MAX_TERMS 100    // #define Max_terms 100
  typedef struct

  {
	float coeff;
	int expo
  }polynomial;        // polynomial data type
  polynomial terms[MAX_TERMS];// Array of structures
  int avail=0;  //avail is global variable

  consider two polynomials
	   1000
    A(x)=2x     +1
	   4      3    2
    B(x)=x   + 10x  +3x +1

    After adding two polynomials

		   1000    4       3    2
    D(x)=	 2x      +x   +10 x  +3x  +2

Condier term array of structure                      Avail->use store result

   term	     0      1      2      3       4     5     6     7     8      9
	 co  2      1      1      10      3     1     2
	 ep  1000   0      4      3       2     0    1000
						FB
	     SA     FA     SB


void padd(int startA,int finshA,int startB,int finshB,int *startD,int *finshD)
{
	//add A(x) and B(x) to obatin D(x)
	float coefficient;
	*startD=avail;
	       0        1         2        5
	while(startA<=finshA && startB <=finishB)
	{
		switch(COMPARE(terms[stratA].expon,terms[stratB].expon))
		{
		   case -1: //ep a<ep b
			   attach(terms[startB].coef,terms[startB].ep);
			   startB++;
			   break;
		   case 0;  //ep a== ep b

			    coeff= terms[startA].coef+terms[startB].coef;
			    if(coeff)
				attach(coeff, terms[startA].ep);
			    startA++;
			    startB++;
		   case 1:  //ep a>ep b
			  attach(terms[startA].coef,terms[startA].ep);
			   startB++;
			   break;
		}

	}
	for(;statA<=finshA;startA++)
		attach(terms[startA].coef,terms[startA].ep);

	for(;statB<=finshB;startB++)
		attach(terms[startB].coef,terms[startB].ep);

      *finsihD=avail-1;
      //
}


void attch(float coeff,int expo)
{
	if(avail>max_terms)
	{
		printf("NO place to store result\n");
		exit(0);
	}
	terms[avail].coeff=coeff;
	terms[avail].expo=expo;
	avail++;

}
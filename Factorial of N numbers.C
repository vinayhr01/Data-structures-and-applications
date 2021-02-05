/*Factorial of N:(6 Marks Question)
	The factorial of number is the product of elemnets from 1 to n.
 The recursive defintion is given below

 Asssume : Name of the function is fact

	Fact(n)=  if n==0 return 1  // Termerination condtion
		  if n==1 return 1  // Termination Condition
		  otherwise return n*fact(n-1)    //Recursive call

 Working of factorial of N:
     -> Assume value of N=5

	5!= 5*4!  ...........> in gernral n*fact(n-1)
	      4!=4*3!
		   3!=3*2!
			2!=2*1!
			     1!=1*0!
				    0!=1 -> terminating cond if(n==0)
			     1!=1*1                              return 1
			2!=2*1
		   3!=3*2
	      4!=4*6
	5!= 5*24


  */
 //C Implementation of factorial N(using Recursion)
 #include <stdio.h>
 #include <stdlib.h>

 int fact(int n)
 {
	if(n==0)
		return 1;//termination condition
	return n*fact(n-1);
	// recursion wont perfrom basic operation first, first it
	//does recursive calls later once basic terminating condtion
	//satisfies then it statrs doing basic operation
 Note: control comes out of reccursion only when stack beccomes emtpy

 }
 void main()                                    // |   | ->system stack
 {                                               //|   |
	int n;                                   //|   |
	int res;                                // |   |
						 //|   |
	printf("Read n\n");                      //|   |
	scanf("%d",&n);                          //.....
	res=fact(n);
	printf("The resulatnat is  %d",res);

 }

//Note: Function calling is application of stack
//Note: Recursion is applicaton of stack
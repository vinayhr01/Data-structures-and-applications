5.Design, Develop and Implement a Program in C for the following Stack Applications
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %,
^
b. Solving Tower of Hanoi problem with n disks 


Postfix expression is present in Reverse Polish Notation. Compilers
recommads postfix expression for evaluation.

-> compilers doesnt recomand infix expression due to below resons
 1.Evaluation of infix expresson requirs the knowledge of precedence.
 2.Conideration of parentheses in expression
 3.During evaluation of infix requires scanning from left to right or right
 to left (based on opperator preccedence).

->steps to evalute postfix expression
 step1. scan the symbol present in postfix expression from left to right
 step2. If the scanned symbol is operand push it on to the stack.
 step3: If the scanned symbol is operator, pop two elements(operands)from
	stack perfrom the operation using the operator, and push intermediate
	result to the stack.
			   0  1  2  3  4  5  6
     postfix Expression :  4  5  6  -  2  *  +       A->4 B->5 c-> 6 D->2
			   A  B  C  -  2  *  +

			    4  5 6  2
			   (A+(B-C)*D)  =2
     step1
		stack:
		     |     |                                     f s  T
		     | 6   |               op2=s[top--]    //op2=6 2  -2
	  top=1	     | 5   |               op1=s[top--]    //op1=5 -1  4
	  top=0	     | 4   |               res=op1 oper op2;    //res=-1 -2
	     top=-1  -----                s[++top]=res;

    step2:

	    top	   | 2  | push 2
		   |-1 |
		   |4  |
		   ....

    step3:

		   |   |
	       top |-2 |
		   |4  |
		   ....
    step4 :
		|    |
	    top	|.2.. |

 */

#include <stdio.h>
#include <stdlib.h>
#define stack_size 5

double compute(char symbol,double op1,double op2) // symbol reffers to oper
{
	switch(symbol)
	{
	      case '+':return op1+op2;

	      case '-':return op1-op2;

	      case '*':return op1*op2;

	      case '/':return op1/op2;

	      case '$':
	      case '^':return pow(op1,op2);
	}
}
void main()
{
	int top=-1;
	double s[20];
	double res;
	double op1;
	double op2;
	int i;
	char postfix[20];
	char symbol;

	printf("Enter the postfix expression\n");
	scanf("%s",postfix);

	for(i=0;i<strlen(postfix);i++)
	{
		symbol=postfix[i];

		if(isdigit(symbol))
			s[++top]=symbol-'0';
		else
		{
			op2=s[top--];
			op1=s[top--];
			res=compute(symbol,op1,op2);
			s[++top]=res;
		}

	}
	res=s[top--];
	printf("The result %lf\n",res);


}

// Solving Tower of Hanoi problem with n disks 
#include <stdio.h>
#include <stdlib.h>
void TOH(int n,char source,char inter,char dest)
{
	if(n==1)
	{
		printf("Move disc %d from %c to%c\nf", n,source,dest);
		return;
	}
	TOH(n-1,source,inter,dest);
	printf("Move disc %d from %c to%c\n", n,source,dest);
	TOH(n-1,inter,dest,source);
}
void main()
{
	int n;//No of disks
	printf("Enter no of discs\n");
	scanf("%d",&n);
	TOH(n,'A','B','C');
}

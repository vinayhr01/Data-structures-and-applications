/*conversion from infix to postfix expression:(6 to 8  Marks) Compilers
convert infix to postfix expression and then evaluate the postfix expression.
-> infix expression is evaluated based on precedence and associativity
   of operators.
-> Evaluating  postfix expression is esier to complier. In the evaluation
   of postfix expression doesnot require precedence and associativity
   of operators.
-> Example:

     ((A+(B-C)*D)^E+F) | (B-C) has highest preccedence
	  -T1-         |  T1=BC-

     ((A+T1*D)^E+F)    | (T1*D) has highest precedence
	 -T2-          | T2=T1D*

     ((A+T2)^E+F)      |(A+T2) has highest preccedence
       -T3-            | T3=AT2+

       (T3^E+F)        |(T3^E) has highest precedence
	-T4-	       |T4=T3E^

       ...................................................


       T4+F  ->  T4F+
	     ->  T3E^F+
	     ->  AT2+E^F+
	     ->  AT1D*+E^F+
	     ->  ABC-D*+E^F+ valid postfix expression  Rev polish Notation

  Input should be   infix expression a+b  -> ouput should be postfix ab+

// program to convert to infix to postfix expression
Let us use two precedence fucntion namely F() and G()
F() -> The Function F() contains the precedence value of
			symb->( operator and  operands,(,) to geather)which is
       present in the stack.

G() -> The Function G() contains the precedence values of symbols  present
	in the input string.

     -> Input must be in string format , should be a infix expression.
     -
     ------------------------------------------------------------------
     symbol      stack pre F()     Input pre G()        Associativity
     ------------------------------------------------------------------
      +,-           2                 1                   L->Left

      *,/           4                 3                   L

     $ or ^         5                 6                   R-> Right

     operands       8                 7                   Left

       (            0                 9                   Left

       )            NIl                 0                   -

       #            -1                -                   -

Procedure to convert infix to postfix: (3 marks 6marks)

Rule 1 -> As long as the precedence value of the symbol on top of the stack(F()) is
   greater than the precedence value of the current input symbol(G()),pop
   an item from the stack and place it in the postfix expression.


       j//indx of postfix

       while( F(s[top])>G(symbol))
       {
	   postfix[j++]=s[top--];

       }

Rule 2->once the while-loop condition fails, if the precedence of the symbol
on the top of the stack is not equal to the precedence of the input symbol,
push the current symbol on to the stack.

       if(F(s[top]!=G(symbol))
       {

		s[++top]=symbol;
       }
Rule 3:discard element from stack top

	top--;

Question : convert the given infix expression to postfix expression using
stack.                0  1 2 3 4  5  6  7  8  9  10
       infix:	      (  A + ( B  -  C  )  *  D  )

Rule in the conversion process: push # to stack in the beginging


     Stack       s[top]     symbol     F(s[top]>G(symbol)      postfix
							       0 1 2 3 4 5 6
 -----------------------------------------------------------------------
      #           #           (           -1> 9  push (
      ...................................................................
      #(          (           A            0> 7  push A
      ...................................................................
      #(A         A           +            8> 1  pop A         A
      #(          (           +            0> 1  push +        A
      ...................................................................
      #(+         +           (            2>9 push (          A
      ..................................................................
      #(+(        (           B            0>7 push B
	....................................................................
      #(+(B       B           -            8>1                 AB
      #(+(        (           -            0>1 psuh -
      ...................................................................
      #(+(-       -           c            2>7 push C
      ....................................................................
      #(+(-C      C           )            8>0 pop C           ABC
      #(+(-       -           )            2>0 pop -           ABC-
      #(+(        (           )            0>0 pop ( dp to pf
      ...................................................................
      #(+         +           *            2>3 push *          ABC-
      ...................................................................
      #(+*        *           D            4>7 push D          ABC-
      ..	.................................................................
      #(+*D       D           )            8>0 pop D           ABC-D
      #(+*        *           )            4>0 pop *           ABC-D*
      #(+         +           )            2>0 pop +           ABC-D*+
      #(          (           )            0>0 pop ( dp to pf
      ..................................................................
      #           #           NIl           NIL               ABC-D*+

  */

// program to convert infix to postfix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int F(char symbol) //stack precedence
{
	switch(symbol)
	{
		case '+':
		case '-':return 2;

		case '*':
		case '/':return 4;

		case '^':
		case '$':return 5;

		case '(':return 0;

		case '#': return -1;

		default: return 8;
	}
}
int G(char symbol) //input precedence
{
	switch(symbol)
	{
		case '+':
		case '-':return 1;

		case '*':
		case '/':return 3;

		case '^':
		case '$':return 6;

		case '(':return 9;

		case ')': return 0;

		default: return 7;
	}
}
void infix_postfix(char infix[],char postfix[])
{
	int top=-1; // index to the top of the stack
	int i,j; //looping purpose
	// i acts as a index to infix array

	int s[30];// represetns stack
	char symbol;
	s[top]='#';
	j=0;// acts as index to postfix array


	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];

		while(F(s[top])>G(symbol))
		{
			postfix[j]=s[top--];
			j++;

		}
		if(F(s[top])!=G(symbol))
			s[++top]=symbol;
		else
			top--;
	}
	while(s[top]!='#')
	{
		postfix[j++]=s[top--];
	}
	postfix[j]='\0';

}

void main()
{
	char infix[20];
	char postfix[20];

	printf("Enter a vaild infix expression\n");
	scanf("%s",infix);
	// Function which converts infix to postfix
	infix_postfix(infix,postfix);

	printf("the postfix expression is \n");
	printf("%s",postfix);

}


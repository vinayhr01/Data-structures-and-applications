4.Design, Develop and Implement a Program in C for converting an Infix Expression to Postfix
Expression. Program should support for both parenthesized and free parenthesized expressions
with the operators: +, -, *, /, % (Remainder), ^ (Power) and alphanumeric operands. 

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
		case '$':return
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


/*Fibonacci Series:
	The fibonacci series is sequencce of numbers where each number is
the sum of previous two number
-> The Fibonacci series is as follows:
-> n no of elements
	     |
FS ->  0   1 |  1   2    3    5    8     13   21 .................
	     |

->The Recursive Defintion:

	fib(n)=  if (n==0)   return  0
		 if (n==1)   return  1
		 return  fib(n-1)+fib(n-2)
  */
  Recusive trees:

				  fib(5)

			fib(4)        +              fib(3)

	     fib(3)     +        fib(2)           fib(2)    +       fib(1)

     fib(2)   +   fib(1)    fib(1) +   fib(0)  fib(1) +   fib(0)


fib(1) +   fib(0)

//Programming Example:
#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fib(n-1)+fib(n-2);
}

void main()
{
	int n;
	int res;
	int i;

	printf("read n\n");
	scanf("%d",&n);
	printf("Fibonaccci series\n");
	for(i=0;i<=n;i++)
	{
		res=fib(i);
		printf("%d\t",res);
	}
}






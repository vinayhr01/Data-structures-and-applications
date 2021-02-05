/* Design Develop and Implement a program in c for the following stack
application
b. Solving Tower of Hanoi problem with n disks
//This problem is called as well known problem of computer science.

Recursive Defintion:

	    TOH=   if(n==1) make one move from source to Dest
		   TOH(n-1,s,d,i)
		   show the tranfer of disk
		   TOH(n-1,t,s,d)

working of moving of disks:

  **** diagarm please take from video****/


#include <stdio.h>
#include <stdlib.h>

void TOH(int n,char source,char dest,char inter)
{
	if(n==1)
	{
		printf("Move  disc %d from  %c to%c\nf", n,source,dest);
		return;
	}
	TOH(n-1,source,dest,inter);
	printf("Move  disc %d from  %c to%c\n", n,source,dest);
	TOH(n-1,inter,source,dest);

}


void main()
{
	int n;//No of disks
	printf("Enter no of discs\n");
	scanf("%d",&n);
	TOH(n,'A','C','B');

}
				 n
//Note: No of moves in general is 2 -1
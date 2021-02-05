// Array of pointers
// assume base address of a =ffec
	//p[0] contains ffec

       // ffec ffee fff0 fff2 fff4
	//1000 1002 1004 1006 1008
	 //1     2   3    4    5

       //	p[0] -> *(p+0)

#include <stdio.h>

void main()
{
	int *p[10];
	int i;
	int a[5]={1,2,3,4,5};
	int b[5]={6,7,8,9,10};
	int c[5];

	p[0]=a; // name of the array holds the base address

	p[1]=b;

	for(i=0;i<5;i++)
		printf("%d\t",*(*(p+0)+i));
	printf("\n");

	for(i=0;i<5;i++)
		 printf("%d\t",*(*(p+1)+i));
	for(i=0;i<5;i++)
		c[i]=(*(*(p+0)+i))+(*(*(p+1)+i));
	printf("\n");
	p[2]=c;

	for(i=0;i<5;i++)
		printf("%d\t",*(*(p+2)+i));
}


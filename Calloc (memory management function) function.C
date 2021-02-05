/*calloc Function:
	The calloc function is used to allocate the memory dynamically
	in block wise.
	->malloc alloctes in byte wise,calloc allocates block wise.

	syntax:
		ptr=(dt*)calloc(n,size);

		ptr-> pointer
		dt-> data type
		n-> no of blocks to be allocated
		size-> s
		ize indicates number of bytes in each block

	example
		ptr=(int *)calloc(10,sizeof(int)) ; //allocates 20 bytes of memory
		ptr=(float*)calloc (20,4);//allocates 40 bytes of memroy

	-> let us consider the example1
	ptr=(int *)calloc(10,sizeof(int)) ;   // 20 bytes of memory

// For sucessful memory allocation
      ptr=100		100 101   102 103 ........................118 119
// Memory is insufficient

	ptr=NULL   as a indication of Unsucessful memory   */

//programming example

#include <stdio.h>

void main()
{
	int i,n=0,*ptr;

	printf("Enter the n of elements\n");
	scanf("%d",&n);
	ptr=(int *)calloc(n,sizeof(int));
	if(ptr==NULL)
	{
		printf("Insufficient memory\n");
		return;
	}
	printf("Enter the n elements\n");
	for(i=0;i<n;i++)
		scanf("%d",(ptr+i));

	printf("Array elements are\n");
	for(i=0;i<n;i++)
		printf("%d",*(ptr+i));



}



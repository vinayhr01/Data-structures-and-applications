Memory mangement Functions:
	C supports two kinds of memroy allocation

	1. static memeory allocation
	2. Dynamic memory allocation

Static memroy allocation: Memory allocated during compile time.
Dynamic Memory Allocation: Memroy allocated during run time

Various Memory Management Functions are given below.

1. malloc()
2. calloc()
3. realloc()
4. free()

Malloc: The malloc() function allocats a block of memory that contains the
	 of bytes speccified in its parameter
	 -> parameter to malloc() function indicates no of bytes.
	 -> suppose required memory is not sufficient then it returns null.

	 -> syntax or prototype of malloc function:

	     ptr=(dt*)malloc(size);

		dt- > data type-> for ex dt is int  (int*)
		size -> No. of bytes of memeory required.
		ptr -> must be a pointer varible

	   eXAMPLE:

	       ptr=(int*)malloc(10);// programmer is interested in 10 bytes
					//of memory

	   Note: dt* denotes thye of data stroing inside the memory
	   clause1: if required memroy is avialable, base address of the
		   allocated memroy will be store inside ptr
    ptr= 100	 address   100 101  102 103  104 105  106 107  108 109


	   clause2:if required memroy is not available ptr is initalized
		   with NULL.
    ptr= NULL	  ******Insufficient memory************


Note: The memory which is alloted using dynamic memory allocation functon
must be relesed using free()
	syntax:
		free(ptr);
	Note: after execution of free function ptr is initalized NULL



// programming Example
#include <stdio.h>

void main()
{
	int i,n,*ptr;

	printf("Enter the no of elements\n");
	scanf("%d",&n);
	ptr=(int*)malloc(sizeof(int)*n); //suppose n=20 40bytes
					 // can work with 20 integers

	if(ptr==NULL) // when required memroy is not avialable
	{
		printf("Insufficient memroy\n");
		return;
	}

	printf("Enter elements\n");
	for(i=0;i<n;i++)
		scanf("%d",(ptr+i));
	printf("Array elements are\n");
	 for(i=0;i<n;i++)
		printf("%d\t",*(ptr+i));

	free(ptr);

}








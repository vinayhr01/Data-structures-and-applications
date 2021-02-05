/*Searching and Sorting: Searching and Sorting are applications of arrys.
 -> the process searching searchs for a key in the given elements( array)
 -> Arrangement of elements in accessending or desecnding order.

searching techniques:
	1. Linear search
	2. Binary search
Sorting Tecchniques
	1. Bubble
	2. selecction sort


Linear Search:
	Linear serach is also called as sequential search.
	-> Array(set of elements)
	-> key to serached

For sucessful search:
	a[0] =10  compared with 15 key=15
	a[1] =30  compared with 15
	a[2] =35  compared with 15
	a[3] =15  compared with 15  // Key found search should be stopped.
	a[4] =25

For Unsucessful search:

	a[0] =10  compared with 80 key=80
	a[1] =30  compared with 80
	a[2] =35  compared with 80
	a[3] =15  compared with 80
	a[4] =25  compared with 80
				  // Key not found

programming example:      */

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int a[10];
	int key;
	int n;
	int i;

	printf("Enter the no of elements\n");
	scanf("%d",&n);
	printf("Read array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the key\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(key==a[i])
		{
			printf("key found\n");
			exit(0);
		}
	}
	printf("key not found\n");

}




/*Binary Search:binary serach is a searching technique  based on divide
and conquer problem solving technique.
 Essentials:
	-> Array(set of elements)
	-> postion of the first element called low
	-> postion of the last elemetn high
	-> key to serached

  condition: elements must be in sorted order

  working:  Assume  n=10
	       low =0
	       high=n-1
	       key=70

	      binary search divides the array logically into two parts.
	      mid=(low+high)/2   quo-> mid->4


	a[0]=10
	a[1]=20
	a[2]=30
	a[3]=40   high=mid-1
Mid ele a[4]=50   compared with 70         if(key==a[mid])
	a[5]=60   low =mid+1                        if(key<a[mid])
	a[6]=70                            else
	a[7]=80
	a[8]=90
	a[9]=100   high


Right part of the array
       a[5]=60   low =mid+1(4+1)                  mid=low 5+high 9 mid=7
	a[6]=70
mid lel	a[7]=80     70 key
	a[8]=90
	a[9]=100   high

Left part of the array
   a[5]=60  mid   key70                        mid=(low+high)/2 ->6
low=6  high=6	a[6]=70   key 70
  */

// programming example

#include <stdio.h>
#include <stdlib.h>


void main()
{
	int low,high;
	int mid;
	int a[10];
	int key;
	int  n;
	int i;

	printf("Enter n\n");
	scanf("%d",&n);
	printf("Read the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Read key\n");
	scanf("%d",&key);
	low=0;
	high=n-1;

	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==a[mid])
		{
			printf("key found\n");
			exit(0);
		}
		if(key<a[mid])
		{
			high=mid-1;
		}
		else
			low= mid+1;
	}
	printf("key not found\n");

}

/*Sorting : sorting is process of arranging the elements in ascending or in
descending order.
->sorting is an application of array.
Bubble sort: bubble sort is a sorting technique based on brute force problem
solving technique.
 -> brute force means it is one of the problem solving method.
 -> it is a straight forward way of solving the problem.
 -> this is sorting called bubble sort due to it holds the element in
     a particular postion of the array for a very short period(life time of
     bubble)
 -> so founder kept the name as bubble sort.
 -> condier array elements line 10 40 50 90 70
 -> Baisc oepration of the bubble sort is comparision.

Algorith : Bubble sort
for j<-0 to n-1
   for i<-0 to n-1
      if a[i]>a[i+1]
	 swap
pass1
i=0 a[0]=50   40    40    40   40
    a[1]=40 i 50    30    30   30
    a[2]=30   30  i 50    20   20
    a[3]=20   20    20  i 50   10
    a[4]=10   10    10    10   50    Largest element will in last posn.

 pass2

i a[0]=40    30     30    30
  a[1]=30  i 40     20    20
  a[2]=20    20   i 40    10
  a[3]=10    10     10    40
  a[4]=50    50     50    50      second largest will in last but one pos.

 pass3
  a[0]=30   20   20
  a[1]=20   30   10
  a[2]=10   10   30
  a[3]=40   40   40
  a[4]=50   50   50

  pass4:

  a[0]=20
  a[1]=10
  a[2]=30
  a[3]=40
  a[4]=50
 */

#include <stdio.h>

void main()
{
	int i,j,n;
	int a[10];
	int temp;

	printf("Enter n\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
		       if(a[i]>a[i+1])
		       {
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		       }
		}
	}
	printf("The sorted array\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}



}


/*Selection sort: Selection sort is sorting technique based on brute force.
	->selection sort at every pass it finds the smallest element and
	palce it at the approprite postiion
	-> so it is called as selection sort.
	-> consider array elements like 70 90 30 20 10

   Algorithm:select_sort()
   // input: array a[]
   // pos --> used to hold the postion of the smallest element

   pos=0
   i=1
   for i<-0 to n-1
	if a[i] <a[pos]
		pos<-i

   swap(a[0],a[pos]

   working:
  -> initally selection sort assumes first element as smallest element
  -> scanning of the array statrs from first postion
  -> always element indexed by pos is compared with other elements, if other
  other element is smaller we need change the position.

   pos=0
   a[pos]=
 pass1
       a[0]=10
       a[1]=90
       a[2]=30
       a[3]=20
   pos a[4]=70

 pass2 : it assumes second element as 2nd smallest ele
       a[0]=10
       a[1]=20
       a[2]=30
   p   a[3]=90
     a[4]=70

 pass3 : it assumes third element as 3nd smallest ele
       a[0]=10
       a[1]=20
    p  a[2]=30 replaced by 30
      a[3]=90
      a[4]=70

 pass4 : it assumes third element as 4nd smallest ele
       a[0]=10
       a[1]=20
      a[2]=30
      a[3]=70
    p  a[4]=90
  */
#include <stdio.h>

void main()
{
	int a[10];
	int i,j;
	int pos;
	int n;
	int temp;

	printf("Read n \n");
	scanf("%d",&n);
	printf("Read array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//comparison
	for(i=0;i<n-1;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
		     if(a[pos]>a[j])
		     {
			pos=j;
		     }
		}
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
	}
       printf("array elements\n");
       for(i=0;i<n;i++)
       {
	printf("%d\t",a[i]);
       }

}

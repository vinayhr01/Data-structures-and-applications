Insertion Sort:  insertion sort is a sorting technique based on decrese and
conquer".
->This sortig technique effficient, only when the array elements are partially
sorted.
-> The following example explains the working of insertion sort.
-> Conider the array elements
-> Each time we insert an element so this sroting technique is called
insertion sort.

	a[0]= 11 Re 11      11  10  9    8   7
	a[1]= 10    10 item 11  11  10   9   8
	a[2]=  9     9       9   9  11   10  9
	a[3]=  8     8       8   8   8   11  10
	a[4]=  7     7       7   7   7   7   11


Algorithm : Insertion Sort(a[],n)
//purpose : To srot an array
//input: an array
//ouput : sorted array

for (i=0 ; i<n-1;i++)         //i=4
{
	item=a[i]; //item =11  10  9  7
	j=i-1      //j=3
	while(j>=0 && item <a[j])
	{
		a[j+1]=a[j]
		j=j-1;  //j=-1
	}
	a[j+1]=item;
}
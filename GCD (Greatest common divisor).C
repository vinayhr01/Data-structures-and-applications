/*GCD of two numbers (Euclid's Algotithm)
	Euclids algorithm is used to find GCD of two numbers. The reursive
definition is shown below.

		      if(n==0) retrun m
	Gcd(m,n) =    if(m<n) return gcd(n,m)
		      otherwise return gcd(n,m%n)

-> The working of Euclids algorithm is  explained below.

	cosider m=6 and n=10
After recursive call
	m=10   n=6

ARC
	m=6    n=4
ARC
	m=4    n=2
ARC
	m=2    n=0           GCD(6,10) is 2
  */
#include <stdio.h>
#include <conio.h>

int gcd(int m,int n)
{
	if(n==0)
		return m;

	if(m<n) return gcd(n,m);
	return gcd(n,m%n);
}

void main()
{
	int m;
	int n;
	int res;// hols gcd of m and n

	printf("Read m and n\n");
	scanf("%d%d",&m,&n);
	res=gcd(m,n);
	printf("The Gcd of m and n is= %d",res);
}
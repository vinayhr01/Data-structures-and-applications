/*6 Design develop and implement a menu driven program in C
for the following operations on CQ of characters.
a. insert an element
b. Delete an element
c. Demonstrate overflow and underflow situations.
d. display the contents of ccircular Q(statuts)
e. exit    */

#include <stdio.h>
#include <stdlib.h>
#define size 5

void insert(char ele,int *r,char cq[],int *count);
void delet(int *f,char cq[],int *count);
void display(int f,char cq[],int count);

void main()
{
 int choice,front=0, rear=-1,count=0;
 char cq[size],ele;
 for(;;)
 {
	printf("1:insert 2:delete 3: disply 4:exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("Enter the char to be inerted\n");
			fflush(stdin);
			scanf(" %c",&ele);
			fflush(stdin);
			insert(ele,&rear,cq,&count);
			break;

		case 2: delet(&front,cq,&count);
			break;

		case 3: display(front,cq,count);
			break;
		case 4:exit(0);

	}
 }
}
void insert(char ele,int *r,char cq[],int *count)
{
	if(*count==size)
	{
		printf("CQ overflow\n");
		return;
	}
	*r=(*r+1)%size;
	cq[*r]=ele;
	(*count)++;
}
void delet(int *f,char cq[],int *count)
{
	if(*count==0)
	{
		printf("CQ is empty\n");
		return;

	}
	printf("The ele deleted is %c\n",cq[*f]);
	*f=(*f+1)%size;
	(*count)--;
}
void display(int f,char cq[],int count)
{       int i;
	int t;
	if(count==0)
	{
		printf("CQ is empty\n");
		return;

	}
	 t=f;
	printf("Q elements are\n");

	for(i=1;i<=count;i++)
	{
		printf("%c\t",cq[t]);
		t=(t+1)%size;
	}
    printf("\n");
}

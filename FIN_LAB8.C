/*8: Desgin develop and Implement a menu driven program in c for the following
operations on doubly linked list of employee data with the fields
1.SSN 2: Name 3: Dept  4:Desig 5: sal 6: pphno

a. Create  a DLL of N employee data using end insertion( insert_rear).
b.Display the status of dll and count the no of nodes.
c. Pefrom insertion and deletion at end of DLL
d.perfrom insertion and deletion at front of DLL
e. Deemonstrate how dll can used as a double ended
	queue.
  */
#include <stdio.h>

struct node
{
	struct node *llink;
	char ssn[10];
	char name[20];
	char dept[10];
	char desig[20];
	float sal;
	long int ph;
	struct node *rlink;
};
typedef struct node *NODE;

NODE getnode()
{
	NODE p;
	p=(NODE) malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("Mem shortage\n");
		exit(0);
	}
	return p;
}



NODE insert_front(NODE root);
NODE insert_rear(NODE root);
NODE delete_front(NODE root);
NODE delete_rear(NODE root);
NODE display(NODE root);




void main()
{
	NODE root=NULL;
	int choice;

	for(;;)
	{
		printf("1:insert_front\t 2:insert_rear\n");
		printf("3:delete_front\t 4:delete_rear\n");
		printf("5:dsiplay\t 7:exit\n");
		scanf("%d",&choice);
		switch(choice)
		{

			case 1:
				root=insert_front(root);
				break;

			case 2: root=insert_rear(root);
				break;

			case 3: root=delete_front(root);
				break;

			case 4: root=delete_rear(root);
				break;

			case 5: display(root);
				break;

			case 6:exit(0);
		}
	}

}
NODE insert_front(NODE root)
{
	NODE temp;
	temp=getnode();

	printf("Read SSN NAME  DEPT  DESIG  SAL PH NO\n");
	scanf("%s %s %s %s %f %ld",(temp->ssn),(temp->name),(temp->dept),
			      (temp->desig),&temp->sal,&temp->ph);

	if(root==NULL)
	{
		return temp;
	}
	temp->rlink=root;
	root->llink=temp;
	return temp;
}


NODE insert_rear(NODE root)
{
	NODE temp;
	NODE last;
	temp=getnode();
	printf("Read SSN NAME  DEPT  DESIG  SAL PH NO\n");
	scanf("%s%s%s%s%f%ld",(temp->ssn),(temp->name),(temp->dept),
			      (temp->desig),&temp->sal,&temp->ph);


	if(root==NULL)
		return temp;

	if(root->rlink==NULL) //only one node in the doubly linked list
	{
		root->rlink=temp;
		temp->llink=root;
		return root;
	}
	last=root;
	while(last->rlink!=NULL)// this cond is false only when last is realy
	//pointing to last node of the linked list
	{
		last=last->rlink;
	}
	last->rlink=temp;
	temp->llink=last;
	return root;
}

NODE delete_front(NODE root)
{
	NODE temp;
	if(root==NULL)
	{
		printf("Linked list is empty\n");
		return root;
	}
	if(root->rlink==NULL)
	{
		printf("The node deleted with fields information");
		printf("%s\t%s\t%s\t%s\t%f\t%ld\n",(root->ssn),(root->name),(root->dept),
			      (root->desig),root->sal,root->ph);

		free(root);
		return root;
	}
	temp=root;
	root=root->rlink;
	temp->rlink=NULL;
	root->llink=NULL;
	printf("%s\t%s\t%s\t%s\t%f\t%ld\n",(temp->ssn),(temp->name),(temp->dept),
			      (temp->desig),temp->sal,temp->ph);

	free(temp);
	return root;


}
NODE delete_rear(NODE root)
{
	NODE last;
	NODE plast;
	plast=NULL;
	last=root;

	if(root==NULL)
	{
		printf("Deletetion is not possible\n");
		return root;
	}
	if(root->rlink==NULL)
	{
		printf("The node deleted with fields information");
		printf("%s\t%s\t%s\t%s\t%f\t%ld\n",(root->ssn),(root->name),(root->dept),
			      (root->desig),root->sal,root->ph);
		free(root);
		return NULL;
	}
	while(last->rlink!=NULL)
	{
		plast=last;
		last=last->rlink;
	}
	last->llink=NULL;
	plast->rlink=NULL;
	printf("The node deleted with fields information");
		printf("%s\t%s\t%s\t%s\t%f\t%ld\n",(last->ssn),(last->name),(last->dept),
			      (last->desig),last->sal,last->ph);

	free(last);
	return root;


}
NODE display(NODE root)
{
	NODE temp;
	int count=0;
	if(root==NULL)
	{
		printf("LInked list emopty\n");
		return NULL;
	}
	temp=root;
	while(temp->rlink!=NULL)
	{
		printf("%s\t%s\t%s\t%s\t%f\t%ld\n",(temp->ssn),(temp->name),(temp->dept),
			      (temp->desig),temp->sal,temp->ph);
		count++;
		temp=temp->rlink;
	}
	printf("%s\t%s\t%s\t%s\t%f\t%ld\n",(temp->ssn),(temp->name),(temp->dept),
			      (temp->desig),temp->sal,temp->ph);
	count++;
	printf("No of Nodes=%d",count);

	return root;

}


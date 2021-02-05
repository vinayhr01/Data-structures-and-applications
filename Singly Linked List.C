/* Design Develop and Implement a menu driven program in c for the following
 operrations on singly linked list of student data with the fields
 1: USN  2: NAME  3: BRANCH  4: SEM 5: PHNO

 A. Create a SLL of N students Data by uisng front insertion.
 B. Display the status of SLL and count the number of nodes in it.
 C. Perform insertion/ Deletion at End of SLL
 D. perform insertion/ Delettion at Front of SLL
 E: exit */



#include <stdio.h>
#include <stdlib.h>

struct node
{
	char usn[10];
	char name[20];
	char branch[20];
	int sem;
	long int phno;
	struct node *link;
};
typedef struct node *NODE;



NODE getnode()
{
	NODE p;

	p=(NODE)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("insufficient memory\n");
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
	int item;
	int choice;

	for(;;)
	{
		printf("1:insert_front 2:delete_front\n");
		printf("3:insert_rear  4:delete_rear\n");
		printf("5:dsiplay  6:exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				root=insert_front(root);
				break;

			case 2: root=delete_front(root);
				break;

			case 3:
				root=insert_rear(root);
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
	printf("Enter USN,Name,BRANCH,SEM , PH \n");
	scanf("%s%s%s%d%ld",(temp->usn),(temp->name),(temp->branch),&temp->sem,&temp->phno);
	temp->link= root;
	return temp; // return  address of first node.
}

NODE delete_front(NODE root)
{
	NODE temp;
	if(root==NULL)
	{
		printf("Linked is empty\n");
		return root;
	}
	temp=root;
	printf("Node deleted with details\n");
	printf("Enter USN,Name,BRANCH,SEM , PH \n");
	printf("%s%s%s%d%ld",(temp->usn),(temp->name),(temp->branch),temp->sem,temp->phno);

	root=root->link;
	temp->link=NULL;
	free(temp);
	return root;

}

NODE insert_rear(NODE root)
{
	NODE temp;
	NODE last;

	temp=getnode();
	printf("Enter USN,Name,BRANCH,SEM , PH \n");
	scanf("%s%s%s%d%ld",(temp->usn),(temp->name),(temp->branch),&temp->sem,&temp->phno);
	temp->link= NULL;

	if(root==NULL)
	{
	      return temp;
	}
	last=root;
	while(last->link!=NULL)
	{
	       last=last->link;
	}
	//Note: When pointer last is really pointing to last node of llist
	last->link=temp;
	return root;

}
NODE delete_rear(NODE root)
{

	NODE last,prev;

	//linked list is empty

	if(root==NULL)
	{
		printf("Linked list is empty\n");
		return root;
	}

	// Only one node in the linked list
	if(root->link==NULL)
	{
	    printf("Node deleted with details\n");
	    printf("Enter USN,Name,BRANCH,SEM , PH \n");
	    printf("%s%s%s%d%ld",(root->usn),(root->name),(root->branch),root->sem,root->phno);
	    free(root);
	    return NULL;
	}
	prev=NULL;
	last=root;
	while(last->link!=NULL)
	{
		prev=last;
		last=last->link;
	}
	prev->link=NULL;
	printf("Node deleted with details\n");
	printf("Enter USN,Name,BRANCH,SEM , PH \n");
	printf("%s%s%s%d%ld",(last->usn),(last->name),(last->branch),last->sem,last->phno);
	free(last);
	return root;
}




NODE display(NODE root)
{

	NODE temp;
	if(root==NULL)
	{
		printf("Linked List is empty\n");
		return root;
	}
	temp=root;
	while(temp!=NULL)
	{
		printf("\n\nEnter USN\t,Name\t,BRANCH\t,SEM\t  PH \n");
		printf("%s\t%s\t%s\t%d\t%ld",(temp->usn),(temp->name),(temp->branch),temp->sem,temp->phno);

		temp=temp->link;
	}
	return root;


}


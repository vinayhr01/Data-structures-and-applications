#include <stdio.h>
#include <stdlib.h>

int count=0;
int count_leaf=0;
struct node
{

	struct node *llink;
	int info;
	struct node *rlink;
};
typedef struct node *NODE;

NODE getnode()
{
	NODE p;

	p=(NODE)malloc(sizeof(struct node));
	if(p==NULL)
	{
		printf("insufficient mem	ory\n");
		exit(0);
	}
	return p;

}

int search(int , NODE );
NODE insert(NODE root,int);
void preorder(NODE root);
void inorder(NODE root);
void postorder(NODE root);
int  search(int,NODE root);
void main()
{
	int key,flag;

	NODE root=NULL;
	int choice,item;

	for(;;)
	{
		printf("1:insert 2:preorder\n");
		printf("3:Inorrder 4:postorder\n");
		printf("5: search 6:exit \n");

		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				root=insert(root,item);
				break;


			case 2: preorder(root);
				printf("\n");
				break;

			case 3: inorder(root);
				printf("\n");
				break;

			case 4: postorder(root);
				printf("\n");
				break;

			case 5: printf("Enther the key\n");
				scanf("%d",&key);
				flag=search(key,root);
				if(flag==0)
					printf("Key not dound\n");
				else
					printf("key found\n");
				break;


			case 6:exit(0);
		}
	}
}



// Searching of Binary search tree

int search(int key, NODE root)
{	NODE cur;
	cur=root;
	while(cur!=NULL)
	{
	       if(key==cur->info) return 1; // as the indicaton of sucessful
					    //search
	       if(key<cur->info)
			cur=cur->llink;
	       else
			cur=cur->rlink;
	}
	return 0;

}

//Insertion of node to a binary search tree.

NODE insert(NODE root,int item)
{
	NODE temp,cur,prev;

	temp=getnode();
	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;

	if(root==NULL)
		return temp; // acts as a root node

	prev=NULL;
	cur=root;
	while(cur!=NULL)
	{
	     prev=cur;
	     if(item<cur->info)
			cur=cur->llink;
	     else
			cur=cur->rlink;
	}
	if(item <prev->info)
		prev->llink=temp;
	else
		prev->rlink=temp;

	return root;
}

// Traversals
void preorder(NODE root)
{
	if(root==NULL)
		return;
	printf("%d\t",root->info);
	preorder(root->llink);
	preorder(root->rlink);

}
void inorder(NODE root)
{
	if(root==NULL)
		return;

	inorder(root->llink);
	printf("%d\t",root->info);
	inorder(root->rlink);

}

void postorder(NODE root)
{
	if(root==NULL)
		return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d\t",root->info);
}

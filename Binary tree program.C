#include <stdio.h>
#include <stdlib.h>

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
		printf("insufficient memory\n");
		exit(0);
	}
	return p;

}

/*Creation of Binary tree:
	A binary tree can created by repeatdly inserting items into tree
	as shown below.

 step 1 : creation of NODE

	Assume the function get does this.

 setp 2: Binary tree is empty
	if(root==NULL)
		return temp; //temp becomes root;
 step 3: if tree is already exits:
		......
		   A
		......
	 .....          ......
	  B                C              Now i would like to insert E
	 .....          ......


    .....
      D
    .....

   // direction of insertion  must be given by user and program should check
  // wether it is correct or not.

  Examples of directions :LLL
			  RL
			  LR
			  LRLR // iNVALIED DIRECTION YOUR PROGRAM SHOULD
			  //CHECK DIRECCTION IT VALIED OR INVALIED.

*/

NODE insert(int item, NODE root);
void preorder(NODE root);
void inorder(NODE root);
void postorder(NODE root);


void main()
{
	NODE root=NULL;
	int choice,item;

	for(;;)
	{
		printf("1:insert 2:preorder\n");
		printf("3:Inorrder 4:postorder\n");
		printf("5:exit\n");
		printf("Enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the item to be inserted\n");
				scanf("%d",&item);
				root=insert(item,root);
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

			case 5:exit(0);
		}
	}
}
NODE insert(int item, NODE root)
{
	NODE temp;
	NODE cur;
	NODE prv;

	char direction [10];
	int i;
	temp=getnode();
	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;

	if(root==NULL)
		return temp;
	//we need directions for insertion
	printf("Give the directions where you wnat to insert(ERX:LRLR\n");
	scanf("%s",direction);
 /*		0 1 2 3 4 5
   exmaple 1:D [L L L]
   example 2:D [R L]
   example 3:D [R L R L R L
		......
		   A        ROOT
		......
	 .....          ......
	 B              C              Now i would like to insert E
	 .....          ......


    .....
     D     prv
    .....

.......
   E
......

   */
	cur=NULL;
	prv=NULL;
	cur=root;
	for(i=0;i<strlen(direction);i++)
	{
		if(cur==NULL) break;

		prv=cur;
		if(direction[i] == 'L')
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if(cur!=NULL || i!=strlen(direction))
	{
		printf("Insetion is not possible\n");
		free(temp);
		return root;
	}

	if(direction[i-1]=='L')
		prv->llink=temp;
	else
		prv->rlink=temp;
	return root;

}
void preorder(NODE root)
{
	if(root==NULL)
		return;
	printf("%d",root->info);
	preorder(root->llink);
	preorder(root->rlink);

}
void inorder(NODE root)
{
	if(root==NULL)
		return;

	inorder(root->llink);
	printf("%d",root->info);
	inorder(root->rlink);

}
void postorder(NODE root)
{
	if(root==NULL)
		return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d",root->info);
}

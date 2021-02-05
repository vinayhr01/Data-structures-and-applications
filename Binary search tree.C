/*Binary Search tree: A binary search tree is binary tree in which for each node
say "NODE x" in the tree, elements in the left subtree must be less than '
"NODE X "  and elements in the right subtree must be grater tahn "NODE X".

Costruct a binary searcch tree for below given elemetns
100, 50 ,200 , 150  300  25  90 80   180

	    Root      100
		      ...

	    50                   200
	    ...                  ....

       25       90	      150       300
      ...      .. .	      ....      ....

	     80                   180
	    ...                   ....  */
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
void maximaum(NODE root);
void minimum(NODE root);
void count_node(NODE root);
void cnt_leaf(NODE root);


void main()
{
	int key,flag;

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

			case 6: maximaum(root);
				break;

			case 7: minimum(root);
				break;

			case 8: count_node(root);
				printf("count_node=%d",count);
				break;

			case 9: cnt_leaf(root);
				printf("Count_leaf=%d",count_leaf);
				break;


			case 10:exit(0);
		}
	}
}

void maximaum(NODE root)
{
	NODE cur;
	if(root==NULL) return ;

	cur=root;
	while(cur->rlink!=NULL)
	{
		cur=cur->rlink;
	}

}
void minimum(NODE root)
{
	NODE cur;
	if(root==NULL) return ;

	cur=root;
	while(cur->llink!=NULL)
	{
		cur=cur->llink;
	}
	printf("The Max node is %d",cur ->info);


}
void count_node(NODE root)
{
	if(root==NULL)
		return;

	count_node(root->llink);
	count++;
	count_node(root->rlink);


}
void cnt_leaf(NODE root)
{
	if(root==NULL)
		return;

	count_node(root->llink);
	if(root->llink==NULL && root->rlink==NULL)
	count_leaf++;
	count_node(root->rlink);

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
Deletion from Binary search tree:
NOTE: it very important to remember that once the node is deleted the ordering
of the tree should be maintained.
Even after deleting a node left subtree should lesser and right sub tree
should be grater.
Question raises : How exactly node deletion can be done in binary searcch tree.

case 0:
	BST is empty deletion is not possible

		root=NULL

case  1: Empty leftsub tree and non empty right sub tree.
			 20
			....
				 40
			       ......

			    30         50
			   .....      .....



case  2: Empty right sub tree and non empty left sub tree.

			   20
			 ......


		      10
		    ......

		   5        12
		 .....     .....


case  3: NON Empty left sub tree and NON Empty right sub tree.

			   20
			 ......


		      10              40
		    ......           ....

		   5        12    30       50
		 .....     .....  ....    ....


NODE delete_item(int key,NODE root)
{

	if(root==NULL)
	{
		printf("Tree is empty\n");
		return root;
	}
	prev=NULL;
	cur=root;



}
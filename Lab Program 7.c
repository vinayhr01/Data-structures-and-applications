#include<stdio.h>
#include<stdlib.h>

struct node{
    char usn[10],name[20],branch[20];
    int sem;
    long int phno;
    struct node *link;
};
typedef struct node *q;

q getnode()
{
    q p;
    p=(q)malloc(sizeof(struct node));
    
    if(p==NULL)
    {
        printf("Insufficient Memory\n");
        exit(0);
    }
    return p;
}

q insertf(q root)
{
    q temp;
    temp=getnode();
    printf("Enter usn, name, branch, sem, phno\n");
    scanf("%s%s%s%d%ld",(temp->usn),(temp->name),(temp->branch),&temp->sem,&temp->phno);
    temp->link=root;
    return temp;
}

q deletef(q root)
{
    q temp;
    
    if(root==NULL)
    {
        printf("List is empty\n");
        return root;
    }
    temp=root;
    root=root->link;
    temp->link=NULL;
    free(temp);
    return root;
}

q insertr(q root)
{
   q temp,last;
   temp=getnode();
   
   printf("Enter usn, name, branch, sem, phno\n");
    scanf("%s%s%s%d%ld",(temp->usn),(temp->name),(temp->branch),&temp->sem,&temp->phno);
   
    temp->link=NULL;
    
    if(root==NULL)
    {
        return temp;
    }
    last=root;
    while(last->link!=NULL)
    {
        last=last->link;
    }
    last->link=temp;
    return root;
}

q deleter(q root)
{
    q last,prev;
    
    if(root==NULL)
    {
        printf("List is empty\n");
        return root;
    }
    
    if(root->link==NULL)
    {
        printf("Node deleted is \n");
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
    free(last);
    return root;
}

q display(q root)
{
    q temp;
    
    if(root==NULL)
    {
        printf("List is empty\n");
        return root;
    }
    temp=root;
    while(temp!=NULL)
    {
    printf("%s%s%s%d%ld",(temp->usn),(temp->name),(temp->branch),temp->sem,temp->phno);
    temp=temp->link;
    }
    return root;
}

int main()
{
    q root=NULL;
    int choice;
    for(;;)
    {
        printf("1:insertf\t2:deletef\n");
        printf("3:insertr\t4:deleter\n");
        printf("5:display\t6:exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1: root= insertf(root);
                break;
                
            case 2: root= deletef(root);
                break;
            case 3: root= insertr(root);
                break;
            case 4: root= deleter(root);
                break;
            case 5: display(root);
                    break;
            case 6: exit(0);
        }
    }
    
}

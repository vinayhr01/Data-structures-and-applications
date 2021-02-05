#include<stdio.h>
#include<stdlib.h>
 
#define MAX 55
 
struct node
{
      int data;
      struct node *link;
};
 
struct node *top[6];
int limit, elements[MAX];
int maximum;
 
void insert(int num, int address);
void address_sorting();
int hash_function(int number);
 
int main()
{
      int count;
      printf("\nEnter Total Number of Elements To Sort:\t");
      scanf("%d", &limit);
      for(count = 0; count < limit; count++)
      {
            printf("Enter Element No. %d:\t", count + 1);
            scanf("%d", &elements[count]);
      }
      for(count = 0; count < limit; count++)
      {
            if(elements[count] > maximum)
            {
                  maximum = elements[count];
            }
      }
      address_sorting();
      printf("\nSorted List\n");
      for(count = 0; count < limit; count++)
      {
	    printf("%d\t", elements[count]);
      }
      printf("\n");
      return 0;
}
 
void address_sorting()
{
      int count, temp;
      struct node *p;
      int address;
      for(count = 0; count <= 6; count++)
      {
            top[count] = NULL;
      } 
      for(count = 0; count < limit; count++)
      {
            address = hash_function(elements[count]);
            insert(elements[count], address);
      }
      printf("\n");
      for(count = 0; count <= 6; count++)
      {
            printf("top(%d) -> ", count);
            p = top[count];
            while(p != NULL)
            {
                  printf("%3d", p->data);
                  p = p->link;
            }
            printf("\n");
      }
      printf("\n");
      count = 0;
      for(temp = 0; temp <= 6; temp++)
      {
            p = top[temp];
            while(p != NULL)
            {
                  elements[count++] = p->data;
                  p = p->link;
            }
      }
}
 
void insert(int num, int address)
{
      struct node *q, *temp;
      temp = malloc(sizeof(struct node));
      temp->data = num;
      if(top[address] == NULL || num < top[address]->data)
      {
            temp->link = top[address];
            top[address] = temp;
            return;
      }
      else
      {
            q = top[address];
            while(q->link != NULL && q->link->data < num)
            {
                  q = q->link;
            }
            temp->link = q->link;
            q->link = temp;
      }
}
 
int hash_function(int number)
{
      int address;
      float temp;
      temp = (float)number / maximum;
      address = temp * 6;
      return(address);
}
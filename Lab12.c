#include<stdio.h>
#include<stdlib.h>

int key[20], n, m; int *ht, hashindex; int elecount = 0;

void createHashTable()
{
int i;
ht = (int*)malloc(m*sizeof(int));
if(ht  == NULL)
printf("\nUnable  to create the hash table"); 
else 

for(i=0; i<m; i++)
ht[i] = -1; 
}

void insertIntoHashTable(int  key)
{
hashindex  = key % m;
while(ht[hashindex]  != -1)
{
hashindex  = (hashindex+1)%m;
}
ht[hashindex]  = key;
elecount++;
}
void displayHashTable()
{
int i;
if(elecount  == 0)
{
printf("\nHash  Table is empty");
return;
}
printf("\nHash  Table contents are:\n\n ");
for(i=0; i<m; i++)
printf("\nT[%d]  --> %d ", i, ht[i]);
}

void main()
{
int i; 
printf("\nEnter  the number of employee   records (N) :  ");
scanf("%d",  &n);
printf("\nEnter  the four digit key values (K) of 'N' Employee Records:\n  ");
for(i=0; i<n; i++)
scanf("%d",  &key[i]);
printf("\nEnter  the two digit memory  locations  (m) for hash table:   ");
scanf("%d",  &m);
createHashTable();
printf("\nInserting  key values of Employee  records into hash table….. ");
for(i=0; i<n; i++)
{
if(elecount  == m)
{
printf("\nHash  table is full.  Cannot insert the %d record key value",  i+1);
break;
}
insertIntoHashTable(key[i]);
}
displayHashTable();
}

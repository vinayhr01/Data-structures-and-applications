/*Realloc: Realloc meanes reallocation of memory,we use realloc function to
reallocate the memroy dynamically which is allocated using malloc or calloc.

    syntax:
		ptr=(dt*)realloc(ptr,size);

		ptr-> pointer
		size-> No. of bytes
		dt-> data type
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char *str;

	str=(char*)malloc(10);

	if(str==NULL)
	{
		printf("Insufficient memory\n");
		return;
	}
	strcpy(str,"Hi"); // strcpy(dest,src)
	printf("Str=%s",str);

	str=(char*)realloc(str,20);
	if(str==NULL)
	{
		printf("Insufficient memory\n");
		return;
	}

	strcpy(str,"Hello how are you");
	printf("%s", str);





}
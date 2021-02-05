/*2.Design , Develop and Implement a program in C for the following operations
on String

a. Read a main string (STR), a pattern string (PAT) and  a Replace String
(REP)
b. Prefrom the Pattern matching operations: Find and replace all occurrences
of  PAT in STR  with REP if PAT exists in STR. Report suitable messages in
case pAT does not exit in STR.

Support the program with functions for each of the above operations. Dont
use Built-in Functions.*/

#include <stdio.h>
#include <stdlib.h>
void string_replace(char str[],char pat[],char rep_pat[],char new_str[],int *mlag,int *n);
void display_result(char new_str[],int mflag,int n);
void main()
{
	char str[100],pat[20],rep_pat[20],new_str[100];
	int mflag=0,n=0;
	printf("Enter the string\n");
	scanf("%s",str);
	fflush(stdin);
	printf("Enter the pattern string to be replaced\n");
	scanf("%s",pat);
	fflush(stdin);
	printf("Enter the replacing string\n");
	scanf("%s",rep_pat);
	string_replace(str, pat,rep_pat,new_str,&mflag,&n);
	display_result(new_str,mflag,n);
}
void string_replace(char str[],char pat[],char rep_pat[],char new_str[],int *mflag,int *n)
{
	int i=0,j=0,k,rep_ind, flag=0;
	while(str[i]!='\0' )
	{
		j=0, k=i,rep_ind=0;
		while((str[k]==pat[j]) && (pat[j]!='\0'))
		{
			k++;
			j++;

		}
		if(pat[j]=='\0')
		{
			flag=1;
			*mflag=1;
			while(rep_pat[rep_ind]!='\0')
			{
				new_str[*n]=rep_pat[rep_ind];
				rep_ind++;
				(*n)++;
			}
		}
		else
		{
			flag=0;
		}
		if(flag==1)
		{
			i=k;
		}
		else
		{
			new_str[*n]=str[i];
			i++;
			(*n)++;
		}

	}
}
void display_result(char new_str[],int mflag,int n)
{
	if(mflag!=1)
	{
		printf("pattern Not found\n");
		exit(0);
	}
	new_str[n]='\0';
	printf("The new string is \n");
	printf("%s\n",new_str);
}



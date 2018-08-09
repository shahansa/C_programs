/*-----------------------------------
Name:Shahansha Salim
Roll number:cs1803	
Date : 31-july-2018
Program description: to count occurances of words from 
		     one file on the other.
Acknowledgements:
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int count;
	char word[100];
	struct node *next;
	};
	
int searchFile(char *filename,char *word)
{
	FILE *fp = NULL;
	char temp[100],c;
	int count=0,i;

	if(word == NULL)
		return -1;
	fp = fopen(filename,"r");
	if( NULL == fp)
	{
		printf("\nERROR: file open failed\n");
		return -1;
	}
	while((c = getc(fp))!= EOF)
	{
		if(c != ' ' && c != '\n')
		{
			temp[i] = c;
			i++;
		}
		else
		{
			temp[i] = '\0';
			i = 0;
			if(0 == strcmp(word,temp))
			    count++;
		}
	}
	fclose(fp);
	return(count);
}

int insertWord(struct node **sorted,struct node **new)
{
	struct node *temp,*prev;
	if(NULL == *sorted)
	{
		*sorted = *new;
	}
	else
	{
		temp = *sorted;
		prev = temp;
		if(temp->next == NULL)
		{
			if(temp->count > (*new)->count)
				temp->next = (*new);
			else
			{
				(*new)->next = temp;
				*sorted = *new;
			}
		}
		else
		{
			while(temp->next != NULL && temp->count >= (*new)->count)
			{
				prev=temp;
				temp = temp->next;
			
			}
			if(temp == *sorted)
			{
				(*new)->next = temp;
				*sorted = *new;
			}
			else{

				prev->next = (*new);
				(*new)->next = temp;
			}
		}

	}
	return 0;
}
int printSorted(struct node *ptr)
{
	struct node *temp = ptr;
	if(NULL == ptr)
	{
		printf("\nERROR : empty header\n");
		return -1;
	}
	while(temp->next != NULL)
	{
		printf("\nword : %s count : %d",temp->word,temp->count);
		temp = temp->next;
	}
	return 0;
}
int main(int argc,char *argv[])
{
	FILE *fp1=NULL;
	char word[100],c;
	int i = 0,count;
	struct node *sorted=NULL,*new=NULL;

	if(argc <3)
	{
		printf("\nERROR : Enter file names\n");
		return -1;
	}
	
	fp1 = fopen(argv[1],"r");
	if(fp1 == NULL)
		return -1;
		
	while((c = getc(fp1))!= EOF)
	{
		if(c != ' ' && c != '\n')
		{
			word[i] = c;
			i++;
		}
		else
		{
			word[i] = '\0';
			count = 0;
			count = searchFile(argv[2],word);
			i = 0;
			printf("\nword : %s , count : %d \n",word,count);
			new = (struct node *)malloc(sizeof(struct node));
			if(NULL == new)
			{
				printf("\nERROR : malloc\n");
				return -1;
			}
			new->count = count;
			strcpy(new->word,word);
			new->next = NULL;
			insertWord(&sorted,&new);
		}
	}
	printSorted(sorted);
	return 0;

}
		

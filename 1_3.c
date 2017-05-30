#ifndef PERM
#define PERM

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define FAILURE 1


int countCharacters(char *string, int *array)
{
	
	int length=strlen(string);
	if(string == NULL)
	{
		return FAILURE;
	}
	int i,pos;
	for(i=0;i<length;i++)
	{
		pos=string[i];
		array[pos]++;
	}
	return SUCCESS;
}

int compareOccurrences(int *str1,int *str2)
{
	int i=0;
	for(i=0;i<256;i++)
	{
		if(str1[i]!=str2[i])
		{
			return FAILURE;
		}
	}
	return SUCCESS;
}

int main(void)
{
	char string1[1024],string2[1024];
	int count1[256],count2[256];

	scanf("%s",string1);
	printf("\nenter string2\n");
	scanf("%s",string2);
	if(strlen(string1) != strlen(string2))
	{
		printf("\nNot permutations\n");
		return SUCCESS;
	}
	countCharacters(string1,count1);
	countCharacters(string2,count2);
	if(SUCCESS == compareOccurrences(count1,count2))
	{
		printf("\nstrings are permutations\n");
	}
	else
	{
		printf("\nStrings are not permutations\n");
	}
        return SUCCESS;
}






#endif



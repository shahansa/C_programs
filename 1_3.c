#ifndef PERM
#define PERM

/*
	file : 1_3.c
	purpose : to check if two strings are permutations 
		  of each other. the number of occurrences of characters are 
		  recorded according to their ascii values as positions into an 	            integer array and they are later compared to see if they have
		  same number of occurrences of characters.
	author : Shahansha Salim, 30 may 2017
*/


#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define FAILURE 1

#define BUFFER_SIZE 1024
#define ASCII_SIZE 256


/* 
	function : countCharacters
	purpose  : scan through the string and store the number of occurrences
 		   of individual characters into an integer array
	parameters : the input string and the integer array
	returns		: SUCCESS or FAILURE depending on execution
*/

int countCharacters(char *string, int array[])
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

/*
	function : compareOccurrences
	purpose  : to scan and compare individual arrays which shows 
		   number of occurrence of characters in their ascii value
		   position. e.g : a(97),b(98) etc.
	parameters : two integer array pointers which are to be compared
	returns    : SUCCESS or FAILURE depending on program execution

*/
int compareOccurrences(int str1[],int str2[])
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
/*
	function : main
	purpose  : to read individual strings and to process them	
	parameters ; none
	returns   : success or failure to os

*/


int main(void)
{
	char string1[1024],string2[1024];
	int count1[256],count2[256];
        /*
	*memset is required since array was showing some random values in
	*one position.
        */
 	memset(count1,0,sizeof(count1));
	memset(count2,0,sizeof(count2));
        /*
	*using fgets to prevent buffer overrun
	*/
	fgets(string1,BUFFER_SIZE,stdin);
	printf("\nenter string2\n");
	fgets(string2,BUFFER_SIZE,stdin);
	if(strlen(string1) != strlen(string2))
	{
		printf("\nNot permutations\n");
		return SUCCESS;
	}
	if(SUCCESS != countCharacters(string1,count1))
 	{
		printf("\nERROR: exited abnormally \n");
		return FAILURE;
	}
	if(SUCCESS != countCharacters(string2,count2))
	{
		printf("\nERROR: exited abnormally \n");
		return FAILURE;
	}
		
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



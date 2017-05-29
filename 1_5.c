#ifndef RUN_LENGTH_ENCODING
#define RUN_LENGTH_ENCODING

/*  file : 1_5.c
    purpose : to implement run-length encoding
    author : shahansha salim ,26 may 2017
*/

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define FAILURE 1
#define BUFFER_SIZE 1024
#define SMALL_BUFF 100

/*
	function : findOccurrence
	purpose  : since we have seen repetition, this function has to count 
		   the number of times the character repeats
	input    : input string,pointer to index,pointer to character count
	returns  : SUCCESS or FAILURE depending on execution
*/

int findOccurrence(char *string,int *i,int *count)
{
	if(NULL == string)
	{
		return FAILURE;
	}
	do
	{
		(*count)++;
		(*i)++;
	}while(string[(*i)] == string[(*i)+1]);
 	return SUCCESS;
}	 



/* function : processString
   purpose  : parses and compresses the input string
   input    : the string to be processed
   return   : SUCCESS or FAILURE depeding on execution
*/

int processString(char *istring,char *ostring)
{
	int i=0,count=1,length;
        char buffer[SMALL_BUFF];	
	length = strlen(istring);
	if(NULL == istring)
	{
		printf("\nERROR : invalid input\n");
	}
	else if (1 == length)
	{
		return SUCCESS;
	}		
	while(i != length)
	{
		count=1;
		strcat(ostring,&istring[i]);
		if(istring[i] == istring[i+1]) //more processing required
		{
			findOccurrence(istring,&i,&count);
		}
		sprintf(buffer,"%d",count);
		printf("\nbuffer : %s",buffer);
		strcat(ostring,buffer);
	}
	return SUCCESS;
}

/*
   function : main
   input    : none
   output   : SUCCESS or FAILURE depending on execution
*/ 
int main(void)
{
	char istring[BUFFER_SIZE],ostring[BUFFER_SIZE];
	scanf("%[^\n]s",istring);
        if(SUCCESS == processString(istring,ostring))
	{
		if(strlen(ostring) < strlen(istring))
		{
			printf("\nafter compression : %s\n",ostring);
			return SUCCESS;
		}
		else
		{
			printf("\nBetter not to compress\n");
			return FAILURE;
		}
	}
}


#endif





















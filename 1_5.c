#ifndef RUN_LENGTH_ENCODING
#define RUN_LENGTH_ENCODING

/*  file : 1_5.c
    purpose : to implement run-length encoding
    author : shahansha salim ,26 may 2017
*/

#include stdio.h
#include string.h

#define TRUE 1
#define FALSE 0
#define SUCCESS 0
#define FAILURE 1
#define BUFFER_SIZE 1024

/* function : processString
   purpose  : parses and compresses the input string
   input    : the string to be processed
   return   : SUCCESS or FAILURE depeding on execution
*/

int processString(char *string)
{
	int i=0,count=1,length;
	char ostring[BUFFER_SIZE];
	
	length = strlen(string);
	if(NULL == string)
	{
		printf("\nERROR : invalid input\n");
	}
	else if (1 == length)
	{
		
	while(i != length)
	{
		count=1;
		strcat(ostring,&string[i]);
		if(string[i] == string[i+1]) //more processing required
		{
			findOccurrence(string,&i,&count);
		}


}

#endif



/*file :strrev.c 
  purpose:to print reverse of a character string terminated with NUL
  author : shahansha salim,25-may-2017
*/
#ifndef STRREV
#define STRREV

#include <stdio.h>
#include <string.h>

#define ZERO 0
#define FALSE 1
#define TRUE 0
#define BUFFER_SIZE 1024

/* function reverseString
   input : pointer to string to be reversed
   return : true or false depending on failure or success
*/
int reverseString(char *string)
{
	char temp;
	int length=strlen(string);
	int beg=0,end=length-1;
	if(length <= ZERO )
	{
		printf("\nERROR : wrong input\n");
		return FALSE;
	}
	while(beg < end)
	{
		temp = string[end];
		string[end] = string[beg];
		string[beg] = temp;
		beg++;
		end--;
	}
        return TRUE;	
}

/*main function
  input : none
  return : true or false depending on execution
*/
int main(void)
{
	char string[BUFFER_SIZE];
	scanf("%[^\n]s",string);
	if(string == NULL)
	{
		printf("\nERROR : Invalid input\n");
		return FALSE;
	}
	if(reverseString(string) == TRUE)
	{
		printf("\nconverted:%s\n",string);
		return TRUE;
	}
	return FALSE;
}
#endif


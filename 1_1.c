/****************************************************************
*   file : 1_1.c
*   purpose : to find if a string contains duplicate characters
*   author : shahansha salim ,25 may,2017
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define FALSE 1
#define TRUE 0
#define ASCII_SIZE 128
#define CLEAR 0

/*************************************************************** 
   function processString
   input : pointer to string to be processed
   returns: true or false depending on program success
****************************************************************/
int processString(char *string)
{
	int length=strlen(string);
        int i=0,position=0;
        int flags[ASCII_SIZE];
	
	if(ASCII_SIZE < length)
        {
 		printf("\nERROR : duplicate characters present\n");
                //according to pigeon hole principle, string must have duplicate
                // characters since it is having more characters than total number of ascii chars.
		return FALSE;
	}
	for(i=0;i<length;i++)
	{
		position = string[i];
		if(flags[position] == FALSE)
                {
 			printf("\nDuplicate!!\n");
			return FALSE;
	        }
		flags[position] = FALSE;
	}
	return TRUE;
}

/**************************************************************** 
   main function
   input : none
   return : true or false depending on success or failure run
****************************************************************/

int main()
{
 
	char string[BUFFER_SIZE];	
#if 0    //did not get this dynamic reading scheme to work.using scanf for the time being.  Should be fixed later.
        char *string = NULL,buffer[BUFFER_SIZE];
	int length=BUFFER_SIZE;
        do 
        {
		buffer[0]=CLEAR;
        	fgets(buffer,BUFFER_SIZE,stdin);
        	string =realloc(string,length);
                length = length + BUFFER_SIZE;
        	strcat(string,buffer);
        }while(buffer[BUFFER_SIZE-2] != '\n');
#endif
        scanf("%[^\n]s",string);
        if(TRUE == processString(string))
        {
 		printf("\nSuccess!\n");
	}
        return TRUE;

}




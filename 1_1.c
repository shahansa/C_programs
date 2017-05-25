#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
#define FALSE 1
#define TRUE 0
#define ASCII_SIZE 128
#define CLEAR 0

int processString(char *string)
{
	int length=strlen(string);
        int i=0,position=0;
        int flags[ASCII_SIZE];
	
	if(ASCII_SIZE < length)
        {
 		printf("\nASCII exception\n");
		return FALSE;
	}
	for(i=0;i<length;i++)
	{
		position = string[i];
		if(flags[position] == TRUE)
                {
 			printf("\nDuplicate!!\n");
			return FALSE;
	        }
		flags[position] = TRUE;
	}
	return TRUE;
}

int main()
{
	
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
        if(TRUE == processString(string))
        {
 		printf("\nSuccess!\n");
	}
        return TRUE;

}




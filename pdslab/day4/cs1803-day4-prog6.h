/*-----------------------------------
Name:shahansha salim
Roll number:cs1803      
Date:31-jly-2018
Program description:
                    
Acknowledgements:
------------------------------------*/


#ifndef _PROG_6_H
#define _PROG_6_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int memoryAlloc(char **arr,size_t size)
{
	if(size <=0)
		return -1;
	*arr = (char *)malloc(size);
	return 0;
}
int memoryAlloc2D(char ***arr,size_t m,size_t n)
{
	int i;	
	if(m <=0)
		return -1;
	
	**arr = (char *)malloc(m);
	if(**arr == NULL)
	{
		printf("\nERROR: memory allocation\n");
		return -1;
	}
	for(i=0;i<m;i++)
	{
		*arr[i] = (char *) malloc (n);
		if(*arr[i] == NULL)
		{
			printf("\nERROR: memory allocation\n");
			return -1;
		}
		
	}
	return 0;
}

#endif

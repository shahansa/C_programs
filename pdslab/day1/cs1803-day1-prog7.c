/*-----------------------------------
Name:shahansha salim
Roll number:cs1803	
Date:21-july-2018
Program description: sorting of collection of strings
Acknowledgements:
------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int sortStrings(char **,int);

int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	char *arr=NULL,*lines[100];
	struct stat statbuf;
	size_t size=0;
	int i=0,j=0;
//	for(i=0;i<100;i++)
//		lines[i]=NULL;

	if(argc <2){
		printf("\n input filename\n");
		return -1;
		}
	fp = fopen(argv[1],"r");
	if(NULL == fp)
		return -1;
	fstat(fileno(fp),&statbuf);
	size = (size_t)statbuf.st_size;
	printf("\n size:%lu\n",size);
	arr = malloc(size);
	if(NULL == arr)
		return -1;
	fread(arr,size,1,fp);
	fputs(arr,stdout);
	lines[j]=&arr[i];
	arr[strlen(arr)] = '\0';
	while('\0' != arr[i])
	{
		if(arr[i] == '\n')
		{
			j++;
			arr[i]='\0';
			lines[j]=&arr[i+1];
		}
		i++;
	}
	sortStrings(lines,j);
	fclose(fp);				
	return 0;
}

int sortStrings(char **lines,int c)
{
	int i,j;
	char *temp=NULL;
	for(i=0;i<(c-1);i++)
	{
		for(j=0;j<(c-i-1);j++)
		{
			if(strcmp(lines[j],lines[j+1]) >0)
			{	
				temp = lines[j+1];
				lines[j+1]=lines[j];
				lines[j]=temp;
			}
		}
	}
       printf("\n========aftr sort=====\n");
        for(i=0;i<c;i++)
        {
                printf("\n");
                fputs(lines[i],stdout);
        }
	printf("\n");	
	return 0;	
}

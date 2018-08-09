/*-----------------------------------
Name:shahansha salim
Roll number:cs1803      
Date:31-jly-2018
Program description: dynamic memory allocation+
		     file copy
                   
Acknowledgements:
------------------------------------*/

#include "cs1803-day4-prog6.h"

int main(int argc,char *argv[])
{
	FILE *fp1=NULL,*fp2=NULL;
	char *arr1=NULL,*arr2=NULL;
	struct stat statbuf;
	size_t f1size=0,f2size=0;

	if(argc <2){
		printf("\ninput files\n");
		return -1;
		}
	fp1 = fopen(argv[1],"r");
	fp2 = fopen(argv[2],"r");
	if(NULL == fp1	|| NULL == fp2)
	{
		printf("\nERROR : file open\n");
		return -1;
	}
	fstat(fileno(fp1),&statbuf);	
	f1size = (size_t)statbuf.st_size;
	printf("\nfile1 size : %lu\n",f1size);
	memoryAlloc(&arr1,f1size);
	fread(arr1,f1size,1,fp1);
	fstat(fileno(fp2),&statbuf);
	f2size = (size_t)statbuf.st_size;
	printf("\nfile2 size : %lu\n",f2size);
	memoryAlloc(&arr2,f2size);
	fread(arr2,f2size,1,fp2);
	printf("\nfile1::\n%s",arr1);
	printf("\nfile2::\n%s",arr2);
	fp1 = freopen(argv[1],"w",fp1);
	fp2 = freopen(argv[2],"w",fp2);
	fwrite(arr2,f2size,1,fp1);
	fwrite(arr1,f1size,1,fp2);
	return 0;	

}

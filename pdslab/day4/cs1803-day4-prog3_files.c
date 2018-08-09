/*-----------------------------------
Name:Shahansha Salim
Roll number:cs1803      
Date : 03-august-2018
Program description: to add two integers with length larger than 
		     system primary memory
Acknowledgements:
------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{
    FILE *fp1 = NULL,*fp2 = NULL;
    char c;
    if(argc < 3)
    {
        printf("\nEnter file names\n");
        return -1;
    }
    fp1 = fopen(argv[1],"r");
    fp2 = fopen(argv[2],"r");
    if(NULL == fp1 ||  NULL == fp2)
    {
        printf("\nERROR: file open failed\n");
        return -1;
    }
	
    fseek(fp1,-2,SEEK_END);
	
    c = fgetc(fp1);
    while(ftell(fp1)!=1)
    {
        
        printf(" %c ",c);
        fseek(fp1,-2,SEEK_CUR);
        c = fgetc(fp1);
     }   
    return 0;
}
    




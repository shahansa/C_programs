/*-----------------------------------
Name: shahansha salim 		
Roll number: cs1803	
Date: 31-july-2018
Program description: to find number of keywords in html file
Acknowledgements:
------------------------------------*/
/*input is html file and we need to count the number of 
 *keywords present in that.
 */

#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	char line[100],*token=NULL;
	int n=0;
	if(argc != 2)
	{
		printf("\nProvide the html source file\n");
		return -1;
	}
	fp = fopen(argv[1],"r");
	if(NULL == fp)
	{
		return -1;
	}
	while(NULL != fgets(line,100,fp))
	{
		token = strtok(line,"<>");
		while(NULL != token)
		{
			n++;
	//		printf("\n%s",token);
			token = strtok(NULL,"<>");
			
		}
	}
	printf("\nNo of tokens : %d\n",n);
	fclose(fp);
	return 0;
}
		
	



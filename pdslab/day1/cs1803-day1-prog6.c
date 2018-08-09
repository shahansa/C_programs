/*-----------------------------------
Name: shahansha salim 		
Roll number: cs1803	
Date: 21-july-2018
Program description: to find number of keywords
Acknowledgements:
------------------------------------*/
/*input is a c program file and we need to count the number of 
 *keywords present in that.
 */

#include <stdio.h>
#include <string.h>

int processString(char *str,const char **keywords)
{
	int len,i;
	if(str == NULL || strlen(str)<2)
		return 0;
	len = strlen(str);
	for(i=0;i<32;i++)
	{
			if(0 == strncmp(str,keywords[i],len-1))
				return 1;
	}
	return 0;	
		
}

#if 0
int removeSpace(char *token,char *str)
{
	char temp[100],trim[100];
	int i=0,j=0,len=0;
	if(NULL == token)
	    return -1;
	len = strlen(token);
	strcpy(temp,token);
	temp[len]='\n';
	while(temp[i]== '\t' || temp[i] == '\n' || temp[i] == ' ')
		    i++;
	for(;temp[i]!='\0';++i)
		trim[j++]=temp[i];
	printf("\n%s\n",temp);
	return 0;		

}
#endif

int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	char line[100],*token=NULL;
	int n=0;
	const char *keywords[] = {
			    "auto", 
			    "break", 
			    "case", 
			    "char", 
			    "continue", 
			    "do", 
			    "default", 
			    "const", 
			    "double", 
			    "else", 
			    "enum", 
			    "extern", 
			    "for", 
			    "if", 
			    "goto", 
			    "float", 
			    "int", 
			    "long", 
			    "register", 
			    "return", 
			    "signed", 
			    "static", 
			    "sizeof", 
			    "short", 
			    "struct", 
			    "switch", 
			    "typedef", 
			    "union", 
			    "void", 
			    "while", 
			    "volatile", 
			    "unsigned"
	};
	if(argc != 2)
	{
		printf("\nProvide the c source file\n");
		return -1;
	}
	fp = fopen(argv[1],"r");
	if(NULL == fp)
	{
		return -1;
	}
	while(NULL != fgets(line,100,fp))
	{
		token = strtok(line," ,;()[]{}#<>	");
		while(NULL != token)
		{
			n += processString(token,keywords);	
			token = strtok(NULL," ,;()[]{}#<>	");
	//		removeSpace(token,wtoken);
			
		}
	}
	printf("\n %d keywords\n",n);
	fclose(fp);
	return 0;
}
		
	



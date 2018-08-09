/*-----------------------------------
Name: Shahansha Salim
Roll number:1803
Date:20-July-2018
Program description: Implimenting string functions
Acknowledgements: 
------------------------------------*/

#include <stdio.h>
#include <string.h>

int strlen1(char *str)
{
	int len=0,i;
	for(i=0;str[i]!='\0';++i)
		len++;
	return len;
}

int strcmp1(char *str1,char *str2)
{
	int i,j;
	if(strlen1(str1) != strlen1(str2))
		return 0;
	for(i=0;i<strlen1(str1);++i)
	{
		if(str1[i] != str2[i])
			return 0;
	}
	return 1;
}

int diffByOne(char *str1,char *str2)
{
	int i,diffcount=0;
	if(1 != strcmp1(str1,str2))
		return 0;
	for(i=0;i<strlen1(str1);++i)
	{
	 	if(str1[i] != str2[i])
		{
			diffcount++;
			if(diffcount > 1)
				return 0;
		}
	}
	if(diffcount == 1)
		return 1;
	else 
		return 0;
}


int main(void)
{
	char str1[100],str2[100];
	fgets(str1,100,stdin);	
	fgets(str2,100,stdin);
	
 	printf("\nstrlen1(string1) =  %d\n",strlen1(str1));
 	printf("\nstrlen1(string2) =  %d\n",strlen1(str2));
	printf("\nStrcmp1(string1,string2) = %d\n",strcmp1(str1,str2));
	printf("\ndiffByOne(string1,string2) = %d\n",diffByOne(str1,str2));
	return 0;
	
} 

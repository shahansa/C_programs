/*-----------------------------------
Name:shahansha salim	
Roll number:cs1803
Date:27-july-2018	
Program description:to concatenate two strings and to 
		    check whether they are palindromes
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int concatenateStr(char *str1,char *str2,char *concat)
{
	int len1,len2,i,j=0;
	if(NULL == str1 || NULL == str2)
		return -1;
	len1 = strlen(str1);
	len2 = strlen(str2);
	for(i=0;i<len1;i++)
		concat[i] = str1[i];
	for(i=len1;i<=(len1+len2);i++)
	{
		concat[i] = str2[j];
		j++;
	}
	return 0;
}

int checkPalindrome(char *string)
{	
	int len,i=0,j;
	if(NULL == string)
	{
		printf("\nhere\n");
		return 0;
	}
	len = strlen (string);
	j = len-1;
	while(i<j)
	{
		if(string[i]!=string[j])
		{
			return 0;
		}
		else
		{
	//		printf("\n%c and %c are matched\n",string[i],string[j]);
			i++;
			j--;
		}
	}
	return 1;

}

int main()
{
	char str1[100],str2[100],*concat=NULL;
	int len1,len2,len,ret=0;

	fgets(str1,100,stdin);
	len1 = strlen(str1);
	len1--;
	str1[len1]='\0';
	fgets(str2,100,stdin);
	len2 = strlen(str2);
	len2--;
	str2[len2] = '\0';
	len = len1+len2;
	concat = malloc(len);
	concatenateStr(str1,str2,concat);
	printf("\nconcatenated : %s\n",concat);
	ret = checkPalindrome(concat);
	if(ret)
		printf("\nstring is palindrome\n");
	else
		printf("\nString is not palindrome\n");
	return 0;
}
	
	
	
	

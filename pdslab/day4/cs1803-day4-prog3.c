/*-----------------------------------
Name:shahansha salim
Roll number:cs1803      
Date:31-jly-2018
Program description: to add to integers having length 
		    more than that of long long int.
		    numbers are passed as cmd line args.
                   
Acknowledgements:
------------------------------------*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int add(char *int1,int len1,
	char *int2,int len2,
	char *res,int len)

{
	int i,j=len2-1,c=0,sum=0;
	
	printf("\n%s +",int1);
	printf("\n%s",int2);
	printf("\n-----------------------------");	
	
	for(i=len1-1;i>=0;i--)
	{	
		sum = 0;
		if(j >=0)
		{
			sum = (int1[i]-'0') + (int2[j]-'0')+c;
		}
		else
		{
			sum = (int1[i] -'0')+c;
		}
		if(sum >= 10)
		{
			c = 1;
			sum = sum%10;
		}
		else
			c = 0;
		j--;

		res[i] = sum +'0';
	}
	res[strlen(res)] = '\0';
	printf("\n%d",c);
	printf("%s\n",res);	
	return 0;
}

int main(int argc, char *argv[])
{
	char *int1,*int2,*res;
	int len1,len2,len;
	if(argc <3)
	{
		printf("\nERROR : give input numbers too\n");
		return -1;
	}
	int1 = argv[1];
	int2 = argv[2];
	len1 = strlen(int1);
	len2 = strlen(int2);
	len = len1>len2? len1: len2;
	res = (char *)malloc(len+1);
	if(len1 >= len2)
		add(int1,len1,int2,len2,res,len);
	else
		add(int2,len2,int1,len1,res,len);
	return 0;
}	

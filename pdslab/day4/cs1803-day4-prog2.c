/*-----------------------------------
Name:shahansha salim
Roll number:cs1803	
Date:31-jly-2018
Program description:to take password from user and to check if it is 
		    strong. password needs to be masked from input.
Acknowledgements:
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getPass(char *pass)
{
	char c;
	int i=0;
	system("/bin/stty raw");
	system("/bin/stty -echo");
	while(1)
	{
		c = getchar();
		if(c != 13)
		{
			pass[i] = c;
			printf("?");
			i++;
		}
		else
			break;
	}
	system("/bin/stty cooked");
	system("/bin/stty echo");
	return 0;
} 

int checkPrime(int n)
{
	int i;
	if(n == 0)
		return 0;
	if(n < 2)
		return 1;
	if(n == 2)
		return 0;
	for(i =2;i<(n/2);i++)
	{
		if((n%i) == 0)
		{
			return 1;
		}
	}	
	return 0;
}

int processPass(char *pass)
{
	int i=0,len,c_lower=0,
	    c_upper=0,c_special=0,
	    c_digits=0;
	char c;
	if(NULL == pass)
	{	
		return -1;
	}
	len = strlen(pass);	
	for(i=0;i<len;i++)
	{
		c = pass[i];
		if(isdigit(c))
			c_digits++;
		else if(islower(c))
			c_lower++;
		else if(isupper(c))
			c_upper++;
		else
			c_special++;
		
		
	} 
	if(checkPrime(c_digits) || checkPrime(c_lower) || checkPrime(c_upper) || checkPrime(c_special))
	{
		printf("\nWEAK\n");
	}
	else
		printf("\nSTRONG\n");
	
	printf("\ndigits: %d  lower : %d  upper : %d special : %d\n",c_digits,c_lower,c_upper,c_special);
	return 0;	
}

int main()
{
	char pass[100];
	getPass(pass);
	processPass(pass);
	return 0;
}

/*-----------------------------------
Name:shahansha salim	
Roll number:cs1803	
Date:24-july-2018
Program description:to compare two numbers 
		    without using relational op. 
Acknowledgements:
------------------------------------*/

#include <stdio.h>

int checkNumbers(int a,int b)
{
	int diff;
	if(a-b)
	{
		diff = a-b;
		if(diff & 1<<((8*sizeof(int))-1))
		{
			return(b);
		}
		else
			return (a);
	}
	else
		return 0;
}

int main(void)
{
	int a,b,ret;
	scanf ("%d%d",&a,&b);
	ret = checkNumbers(a,b);
	if(ret)
	    printf("\n %d is larger.\n",ret);
	else
	    printf("\nEqual\n");
	return 0;
}
		
	



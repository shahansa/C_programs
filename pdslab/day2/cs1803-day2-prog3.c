/*-----------------------------------
Name:shahansha salim
Roll number:cs1803
Date:24-july-2018
Program description: to check if a number is strong
Acknowledgements:
------------------------------------*/

#include <stdio.h>
#include <math.h>

int factorial(int n)
{
	int fact=1;
	if(n==0)
	    return 1;
	else
	  while(n>1)
	  {
		fact *= n;
		n--;
	  }
	return(fact);
}

int processNumber(int num)
{
	int n=num,factsum=0,rem=0;
	if(num == 0)
	    return 0;
	while(n >0)
	{
		rem=n%10;
		factsum+=factorial(rem);
		n=n/10;
	}
	if(factsum == num)
		return 0;
	else
	        return -1;

}
	
int main()
{
	int number,ret=0;
	scanf("%d",&number);
	ret = processNumber(number);
	if(ret == 0)
		printf("\nNumber is strong\n");
	else
		printf("\nNumber is not strong\n");
	return 0;
}


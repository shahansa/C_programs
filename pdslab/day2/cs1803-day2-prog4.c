/*-----------------------------------
Name:shahansha salim
Roll number:cs1803
Date:24-july-2018
Program description:to print * in fibanocci 
		    series
Acknowledgements:
------------------------------------*/

#include <stdio.h>

int main()
{
	int n,fib[20],i,j;
	fib[0]=0;
	fib[1]=1;
	scanf("%d",&n);
	n++;
	for(i=2;i<=n;i++)
		fib[i]=fib[i-1]+fib[i-2];
	printf("\n");
	for(i=2;i<=n;i++)
	{
		for(j=0;j<fib[i];j++)
		    printf("*");
		printf("\n");
	}
	return 0;
}

/*-----------------------------------
Name: shahansha salim           
Roll number: cs1803     
Date: 03-aug-2018
Program description: to find what a given function performs
Acknowledgements:
------------------------------------*/

#include <stdio.h>

int f ( int n )
{
	int s = 0;
	while (n--) s += 1 + f(n);
	return s;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("\nf(n) = %d\n",f(n));
	printf("function calculates 2^n-1?\n");
	return 0;
}
	

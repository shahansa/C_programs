/*
name: shahansha salim           
Roll number: cs1803     
Date: 31-july-2018
Program description: recursive implementation of c(n,r)
Acknowledgements:
------------------------------------*/
#include <stdio.h>

int computencr(int n,int r)
{
	
	if(r > n || n ==0)
		return 0;
	else if(r == 0)
		return 1;
	else if(r == 1)
		return(n);
	else if(n == r)
		return 1;
	else
		return(computencr(n-1,r)+computencr(n-1,r-1));
}

int main()
{
	int n,r,result = 0;
	printf("\nc(n,r) , n=? r=?\n");
	scanf("%d %d",&n,&r);
	result = computencr(n,r);
	printf("\nc(%d,%d) = %d\n",n,r,result);
	return 0;
}	

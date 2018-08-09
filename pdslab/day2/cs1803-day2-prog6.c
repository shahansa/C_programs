/*-----------------------------------
Name:shahansha salim
Roll number:cs1803
Date:27-july-2018
Program description:bitwise operations
Acknowledgements:
------------------------------------*/
#include <stdio.h>
int main()
{
	unsigned int m,n,compn;
	int k;
	scanf("%u",&n);
	m = n&1;
	if(m)
		printf("\nn is odd");
	else
		printf("\nn is even");
	compn=~n;
	//check if last two bits are set in compn
	if((compn&1) && (compn&(1<<1)))
		printf("\nn is divisible by 4\n");
	else
		printf("\nn is not divisible by 4\n");
	
	m = n<<1;
	printf("\n2n = %u\n",m);

        printf("\nk:?\n");
	scanf("%d",&k);
	
	m = n<<k|n>>((sizeof(int)*8)-k);
	printf("\nm after left rotation by k bits = %u\n",m);
	m = n>>k|n<<((sizeof(int)*8)-k);
	printf("\nm after right rotation by k bits = %u\n",m);
			
	return 0;
}

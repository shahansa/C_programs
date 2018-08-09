/*-----------------------------------
Name:shahansha salim
Roll number:cs1803
Date:24-july-2018
Program description: 
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <math.h>

int checkSum(float x,float y)
{
	float sum;
	sum = x+y;
	if(sum - (int)sum)
	    return 1;
	else 
	   return 0;
}

int main()
{
	float x,y,root;
	int ret,m,n,parm,parn;
	printf("\n x &y \n");
	scanf("%f%f",&x,&y);
	printf("\nm & n\n");
	scanf("%d%d",&m,&n);
	ret = checkSum(x,y);//checking if x+y is integer
	if(ret == 0)
	    printf("\nx+y is integer\n");
	else
	    printf("\nx+y is not integer\n");
 	
	if((x < m) && (m<y)) 
	   printf("\nm belongs to (x,y)\n");
	else
	   printf("\nm is not contained in (x,y)\n");	

	if(m == (int)x)
	    printf("\nm is equal to integer part of x\n");
	else
	    printf("\nm is not equal to integer part of x\n");

	if(((int)x >= 3 )&& ((x-(int)x)<0.3))
	    printf("\n x has integer part atleast 3 and frac part less than 0.3\n");
	else
	    printf("\n x > 3.3\n");
	
        parm = m%2;
	parn = n%2;
	if(parm == 1 && parn == 1)
		printf("\nm and n have same parity and are odd numbers\n");
	else if(parm == 1 && parn == 0)
		printf("\nm and n have different parity and m is odd,n is even\n");
	else if(parn == 1 && parm == 0)
		printf("\nm and n have different parity and n is odd,m is even\n");
	else
		printf("\nm and n have same parity and both are even\n");

	root = sqrt(m);
	if(0 == root-(int)root)
		printf("\nm is perfect square\n");
	else
		printf("\nm is not perfect square\n");

	return 0;
}

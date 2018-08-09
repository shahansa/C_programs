/*-----------------------------------
Name:shahansha salim
Roll number:cs1803
Date:27-july-2018
Program description: complex number manipulation
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

struct complex{
 	int real,imag;
	};

int main()
{
	struct complex c1,c2,sum;
	printf("\n a1+ib1 , a1,b1=?\n");
	scanf("%d%d",&c1.real,&c1.imag);
	printf("\na2,b2=?\n");
	scanf("%d%d",&c2.real,&c2.imag);
	sum.real = c1.real+c2.real;
	sum.imag=c1.imag+c2.imag;
	if(sum.real == 0)
		printf("\n1. x+y is an imaginary number without any real component\n");
	if(c1.imag == (-1*c2.imag)&& c1.real == c2.real)
		printf("\n2. x and y are conjugates\n");
	if(c1.imag == 0 && c2.imag == 0)
		printf("\n3. both x and y are real numbers\n");
	return 0;
	

}



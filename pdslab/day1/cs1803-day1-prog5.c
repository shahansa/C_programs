/*-----------------------------------
Name:Shahansha salim
Roll number:cs1803
Date:20ju;y2018
Program description:complex numbers and roots of quadratic eqn
Acknowledgements:
------------------------------------*/

#include <stdio.h>
#include<math.h>

struct complex{
	float a,b;
	};

int main()
{
	struct complex r1;
	int a,flag=0,b,c,bsq;
	float d,real,img,root1,root2;
	scanf("%d%d%d",&a,&b,&c);
	//ax^2+bx+c
	bsq= pow(b,2);
	d = bsq-(4*a*c);
	if(d<0)
	{
		flag = 1;
		d=d*-1;
	}
	
	d=sqrt(d);
	if(flag == 1)
	{

		real = (-1*b)/(2*a);
		r1.a=real;
		img = d/(2*a);
		r1.b=img;
		printf("\nroots are: %2.1f +/- i %2.1f \n",r1.a,r1.b);
		
	}	
	else if(flag == 0)
	{
		root1 = ((-1*b)+d)/(2*a);
		root2 = ((-1*b)-d)/(2*a);
		printf("\n roots are : %2.1f and %2.1f\n",root1,root2);
	}
	return 0;
}
	
	
	
	
	

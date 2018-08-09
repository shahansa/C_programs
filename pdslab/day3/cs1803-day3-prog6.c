/*-----------------------------------
Name:shahansha salim
Roll numbuer:cs1803
Date:27-july-2018
Program description: uses pointers to structure pointer
Acknowledgements:
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

struct complex{
	int real;
	int img;
};

int printNumbers(struct complex **ptr)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d+i%d \n",ptr[i]->real,ptr[i]->img);
	}
	return 0;
}
		

int main()
{
	int i;
	struct complex *ptr[10];
	for(i=0;i<10;i++)
		ptr[i]=malloc(sizeof(struct complex));
	for(i=0;i<10;i++)
	{
		ptr[i]->real = i;
		ptr[i]->img = i+1;
	}
	printNumbers(ptr);
	return 0;
}

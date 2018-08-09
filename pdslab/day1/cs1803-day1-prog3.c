/*-----------------------------------
Name:Shahansha Salim
Roll number: cs1803
Date: 20-july-2018
Program description : to check if array is in strictly increasing order
Acknowledgements:
------------------------------------*/

#include <stdio.h>

int processInput(int *arr)
{
	int present,prev=-1,i=0;
	while(1)
	{
		scanf("%d",&present);
		if(present == -1)
			break;
		if(prev < present)
		{
			arr[i] = present;
			i++;
			prev = present;
		}
		else if(prev >present)
			return -1;
	}
	return i;
}	

int main()
{
	int array[100],ret,i;
	ret = processInput(array);
	if(ret >= 0)
	{
		for(i=0;i<ret;i++)
			printf("%d ",array[i]);
	}
	printf("\n");
	if(ret >= 0)
		return 0;
	else
	{
		printf("\nInput was not in increasing order\n");
		return -1;
	}
}
	

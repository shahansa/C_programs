#ifndef MAX_SUM_SUBARRAY
#define MAX_SUM_SUBARRAY

/*  program to find maximal sum of a monotonically (continuously) increasing sub array in an array
 *  Author : Shahan, 01-Apr-2018
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1
#define ZERO    0
#define BUFFER_SIZE  1024

/* function : max
 * purpose  : returns maximum among arguments
 * input    : two integer numbers to be compared
 * returns  : maximum among inputs
 */
int max(int a,int b)
{
	return(a>b?a:b);
}



/* function : processArray
 * purpose  : the input array is scanned from left to right, for each sub sequence
 *            which is monotonically increasing, a local sum is kept which will be updated
 *            when the criteria is broken
 * input    : input array,size of array
 * returns  : SUCCESS or FAILURE depending on execution
 */

int processArray(int arr[],int size)
{
	if(arr == NULL || size <= ZERO)
	{ 
		return FAILURE;
	}
	int localSum = arr[0],
	     maxSum = arr[0];
	int  i = 0;    
	
	for(i = 1; i < size; i++)
	{
		if(arr[i] > arr[i-1])   /*monotonically increasing*/
		{
			localSum = max(arr[i],localSum + arr[i]); 
			/*in case we miss a large number due to previous -ve number.*/
		}
		else                    /*criteria is broken */
		{
		        maxSum = max(maxSum,localSum);
			localSum = arr[i];          /*new sequence starts here */
		}
	}
        maxSum = max(maxSum,localSum); 
	printf("\n%d\n",maxSum);
	return SUCCESS;
}

/*function : main
 *input    : array size and array elements from user
 *returns  : SUCCESS or FAILURE 
 */

int main(void)
{
	int arr[BUFFER_SIZE],
	    size = ZERO,
	    i = ZERO,retVal = FAILURE;
	
	scanf("%d",&size);      /*read array size*/
	
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);       /*read array elements*/
	}

	retVal = processArray(arr,size);
	if(SUCCESS == retVal)
	{
		return SUCCESS;
	}
	else 
	{
		return FAILURE;
	}
}
	


#endif
#if 0

=============================TEST CASES================================
[lemontree@Arch builds]$ ./a.out
5
1 2 -1 5 16

21
[lemontree@Arch builds]$ ./a.out
3
-3 -1 -2

-1
[lemontree@Arch builds]$ ./a.out
7
3 4 67 12 -1 100 99

100

#endif








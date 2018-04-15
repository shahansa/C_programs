#ifndef MAX_SUM_SUBARRAY
#define MAX_SUM_SUBARRAY

/*  program to find maximum sum sub array in an array
 *  Author : Shahan, 14-Apr-2018
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
 *            it will be checked to see if it adds to the current local sum and thereby 
 *            updating the maxsum
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
		localSum = max(arr[i],localSum + arr[i]);
	        maxSum = max(maxSum,localSum);
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
==========TEST CASES========
[lemontree@Arch C_programs]$ ./a.out 
7   
3 4 67 12 -1 100 99

284
[lemontree@Arch C_programs]$ ./a.out 
3
5 -9 6

6
[lemontree@Arch C_programs]$ 


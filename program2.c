#ifndef SUBSEQ_ARR_SUM
#define SUBSEQ_ARR_SUM

/* program to find maximum sum of increasing subsequence(may not be contiguous)
 * time complexity is not a concern here
 * Author : Shahan, 03-Apr-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SUCCESS 0
#define FAILURE 1
#define BUFFER_SIZE 1024

/* function : processArray
 * purpose  : iteratively process the array to form all possible sub sequences
 *            which are in increasing order and find the maximum sum among them
 * input    : Array to be processed,size of array
 * output   : SUCCESS or FAILURE based on execution
 */

int processArray(int arr[],int size)
{
	int maxSum=0,localSum=0;
	int powSize = pow(2,size);
	int i,j,prev=0,flag=0;

	for(i=0; i<powSize; i++)
	{
		for(j=0; j<size; j++)
		{
			if(i & (1<<j))
			{
				if(flag == 0)
				{
					prev=arr[j];
					flag = 1;
		    		}
				else
				{
					if(prev > arr[j])
					{
						break;
					}
				}
				localSum += arr[j];
				prev = arr[j];
				if(localSum > maxSum)
				{
					maxSum = localSum;
				}
			}
		}
		flag = 0;
		localSum = 0;		
	   }
	   if(localSum > maxSum)
	   {
		   maxSum = localSum;
 	   }

	   printf("\nMaxSum = %d\n",maxSum);





    	return SUCCESS;
}


/* function : main
 * input    : Array and size of array from user
 * returns  : SUCCESS or FAILURE based on execution
 */

int main(void)
{
    int arr[BUFFER_SIZE],size=0;
    int i=0,retval=FAILURE;
    
    scanf("%d",&size);
    for (i=0;i<size;i++)
    {
         scanf("%d",&arr[i]);
    }
    
    retval = processArray(arr,size);
    return(retval);
}
    

#if 0

======================TEST CASES============
[lemontree@Arch C_programs]$ ./a.out
5
5 80 70 79 100

MaxSum = 254
[lemontree@Arch C_programs]$ ./a.out
6
1 2 6 0 -3 9

MaxSum = 18
[lemontree@Arch C_programs]$ ./a.out
6
-3 1 2 -2 4 -1

MaxSum = 7













#endif


#endif 




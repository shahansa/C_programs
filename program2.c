#ifndef SUBSEQ_ARR_SUM
#define SUBSEQ_ARR_SUM

/* program to find maximum sum of increasing subsequence(may not be contiguous)
 * time complexity is not a concern here. time complexity is O(n.2^n)
 * Author : Shahan, 03-Apr-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SUCCESS 0
#define FAILURE 1
#define BUFFER_SIZE 1024

int max(int a,int b)
{
	return(a>b?a:b);
}

/* function : processArray
 * purpose  : iteratively process the array to form all possible sub sequences
 *            which are in increasing order and find the maximum sum among them
 * input    : Array to be processed,size of array
 * output   : SUCCESS or FAILURE based on execution
 */

int processArray(int arr[],int size)
{
	int maxSum=arr[0],localSum=arr[0];
	int powSize = pow(2,size);
	int i,j,prev=0,flag=0;

	for(i=1; i<powSize; i++)  /*if i in binary is 010, sequence generated will have only middle element*/
	{
		for(j=0; j<size; j++)
		{
			if(i & (1<<j))   /*check which element bit is set*/
			{
				if(flag == 0)
				{
					prev=arr[j]; /*prev is to check if sequence is increasing*/
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
				maxSum = max(localSum,maxSum);
			}
		}
		flag = 0;
		localSum = 0;		
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

[lemontree@Arch C_programs]$ ./a.out
3
-3 -2 -1

MaxSum = -1










#endif


#endif 




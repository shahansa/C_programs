#ifndef SUBSEQ_ARR_SUM
#define SUBSEQ_ARR_SUM

/* program to find maximum sum of increasing subsequence(may not be contiguous)
 * time complexity is not a concern here
 * Author : Shahan, 03-Apr-2018
 */

#include <stdio.h>
#include <stdlib.h>

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
    int maxSum=0,currentSum=0,prevnum;
    int i=0,j=0;

    if(NULL == arr || size <= 0)
    {
        return FAILURE;
    }
    maxSum = arr[0];    /*else when array is full of -ve numbers, maxSum will never update*/

    for(i=0; i<size ; i++)
    {
       currentSum = arr[i];   /*start looking from this number*/
       prevnum = arr[i];      /*this is to check continuity of sequence*/

       for(j = i+1;j<size;j++)
       {
	       if(arr[j] > prevnum && currentSum < currentSum+arr[j])
	       {
                    currentSum = currentSum + arr[j]; /*if we found a match, update values*/
		    prevnum = arr[j];
		    if(maxSum  < currentSum)    /*update maxsum if value satisfies criteria*/
                    {
                        maxSum = currentSum;
		    }
		}
	}
     }
     if(maxSum < currentSum) /*in case last number in array is very large*/
     { 
         maxSum = currentSum; 
     }                        
     
     printf("\n maxSum = %d\n",maxSum);
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

===========================TEST CASES=============

[lemontree@Arch C_programs]$ ./a.out
6
1 2 6 0 -3 9

 maxSum = 18
[lemontree@Arch C_programs]$ ./a.out
6
43 32 33 34 35 20

 maxSum = 134
[lemontree@Arch C_programs]$ ./a.out
6
-3 1 2 -2 4 -1

 maxSum = 7
[lemontree@Arch C_programs]$ ./a.out
3
-3 -2 -1

 maxSum = -1
[lemontree@Arch C_programs]$ 



#endif

#endif 




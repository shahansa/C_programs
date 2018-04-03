#ifndef SUBSEQ_ARR_SUM
#define SUBSEQ_ARR_SUM

/* program to find maximum sum of increasing subsequence(may not be contiguous)
 * efficient implementation using dynamic programming
 * Author : Shahan, 03-Apr-2018
 */

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1
#define BUFFER_SIZE 1024

/* function : processArray
 * purpose  : try to find possible max sum components and save them. 
 *            if some previous intermediate sum+present element results in larger sum than 
 *            what we have saved, it would be updated for the particular position for future reference. 
 *            using another auxillary array, the actual sequence can also be printed(not done here).
 * input    : Array to be processed,size of array
 * output   : SUCCESS or FAILURE based on execution
 */

int processArray(int arr[],int size)
{
	int maxarr[size],i=0,j=0,maxSum=0;
        
        if(NULL == arr || 0 == size)
	{
		return FAILURE;
	}

	for(i=0;i<size;i++)
	{
		maxarr[i] = arr[i]; /*since maximum value at each point is atleast 
				      as big as current value in that position*/  
	}
        /* take each value(at position i) and check for each element from the start of array(using j), 
	 * check if maximum sum till position j + arr value at position i gives a new bigger value than
	 * what we have already in the maxarr. if so, update maxarr for that position. also check if it
	 * satisfies the criteria of increasing sub sequence  */
         
	 for(i=0 ; i<size; i++)
	 {
		 for(j=0; j<i; j++)
		 {
			 if(arr[j] < arr[i] && maxarr[j]+arr[i] > maxarr[i])
			 {
				 maxarr[i] = maxarr[j]+arr[i];
			 }
		 }
	 }
         /*iterate through maxarr and find the maxSum*/
         
	 maxSum = maxarr[0];
	 for(i=0; i<size; i++)
	 {
		 if(maxarr[i] > maxSum)
		 {
			 maxSum = maxarr[i];
		 }
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

============================TEST CASES=======================
[lemontree@Arch C_programs]$ ./a.out
6
1 2 6 0 -3 9

MaxSum = 18
[lemontree@Arch C_programs]$ ./a.out
6
43 32 33 34 35 20

MaxSum = 134
[lemontree@Arch C_programs]$ ./a.out
6
-3 1 2 -2 4 -1

MaxSum = 7
[lemontree@Arch C_programs]$ ./a.out
3
-3 -2 -1

MaxSum = -1
[lemontree@Arch C_programs]$ ./a.out
5
5 80 70 79 100

MaxSum = 254
[lemontree@Arch C_programs]$ 


#endif

#endif 




/*-----------------------------------
Name:shahansha salim
Roll number:cs 1803
Date:28-july-2018
Program description:A and B are sets
		    (i)to find number of possible overlapping of B in A
		    (ii) to find if multisets A and B are equal
Acknowledgements:
------------------------------------*/
#include <stdio.h>


int readInput(int *arr)
{
	int i=0,c;
	while(1)
	{
		scanf("%d",&c);
		if(c == -1)
			break;
		arr[i] = c;
		i++;
	}
	return(i);
}
int sort(int *set,int len)
{
	int i,j,temp;
	for(i=0;i<(len-1);i++)
	{
		for(j=0;j<(len-i-1);j++)
		{
			if(set[j+1]<=set[j])
			{
				temp = set[j];
				set[j]=set[j+1];
				set[j+1]=temp;
			}
		}		
	}
	return 0;

}

int printSet(int *set,int len)
{
	int i;
	printf("\n");
	for(i=0;i<len;i++)
		printf("%d ",set[i]);
	printf("\n");
	return 0;
}

int checkOverlapping(int *set1,int *set2,int len1,int len2)
{
	int i;
	for(i=0;i<len2;i++)
	{
		if(set1[i] != set2[i])
		{
			return 0;
		}
	}
	return 1;
	
}

int checkIfEqual(int *set1,int len,int *set2)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(set1[i] != set2[i])
		{	
			return 0;
		}
	}
	return 1;

}

int main()
{
	int set1[100],len1,set2[100],len2;
	int overlapping=0,i;
	len1 = readInput(set1);
	len2 = readInput(set2);
	for(i=0;i<len1;i++)
	{
		if(set1[i] == set2[0])
		{
 			overlapping+=checkOverlapping(&set1[i],set2,len1-i,len2);
		}
	}
	printf("\n(1). possible overlappings = %d\n",overlapping);
	if(len1 != len2)
	{
		printf("\n(2). multisets A and B are not equal\n");
		return 0;
	}
	sort(set1,len1);
	sort(set2,len2);
	if(checkIfEqual(set1,len1,set2))
	{	
		printf("\n(2). multisets A and B are equal\n");
	}
	else
		printf("\n(2). multisets A and B are not equal\n");
	       	
//	printSet(set1,len1);
//	printSet(set2,len2);
	return 0;
}	

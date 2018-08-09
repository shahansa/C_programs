/*-----------------------------------
Name:shahansha salim
Roll number:cs1803
Date:20-july-2018
Program description: set operations
Acknowledgements:
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int readInput(int *arr)
{
	int c=0,i=0;
	while(1)
	{
		scanf("%d",&c);
		if(c == -1)
			break;
		arr[i] = c;
		i++;
		c=0;
	}
	return(i);
}

int printSet(int *set,int size)
{
	int i;
	printf("\n");
	for(i=0;i<size;++i)
		printf("%d ",set[i]);
	printf("\n");
	return 0;	
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
int removeDuplicates(int *set,int len)
{
	int temp[100],i,prev=0,loc=0;
	prev = set[0];
	temp[loc]=set[0];
	loc++;
	for(i=1;i<len;i++)
	{
		if(set[i] > prev)
		{
			temp[loc] = set[i];
			prev = temp[loc];
			loc++;
		}
		
	}
	for(i=0;i<loc;i++)
	{
		set[i]=temp[i];
	}
	return (loc);
}


int findUnion(int *set1,int len1,int *set2,int len2)
{
	int unionarr[200],i,j,len;
	for(i=0;i<len1;i++)
		unionarr[i]=set1[i];
	for(i=len1,j=0;i<(len1+len2);i++,j++)
		unionarr[i] = set2[j];
	sort(unionarr,(len1+len2));
	len=removeDuplicates(unionarr,(len1+len2));
	printf("\nUnion ::");
 	printSet(unionarr,len);	
	return 0;
	
}
int checkPresence(int *set,int elem,int len)
{
// to check if element is present in a set
	int i;
	for(i=0;i<len;i++)
		if(set[i] == elem)
		{
			return 0;
			break;
		}
	return 1;
}

int findIntersection(int *set1,int len1,int *set2,int len2)
{
	int intersection[200],i,loc=0;
	for(i=0;i<len1;i++)
	{
		if(0 == checkPresence(set2,set1[i],len2))
		{
			intersection[loc] = set1[i];
			loc++;
		}
	}
	printf("\nIntersection ::");
	printSet(intersection,loc);
	return 0;
	
}	
		
int findIfSubset(int *set1,int *set2,int len1,int len2)
{
//finds if set1 is subset of set2
	int i,flag=0;
	for(i=0;i<len1;i++)
	{
		if(0 != checkPresence(set2,set1[i],len2))
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		printf("A is subset of B\n");
		return 1;
	}
	else
	{
		printf("A is not subset of B\n");
		return 0;
	}
	
}

int printPowerSet(int *set,int len)
{
	int psize,i,j,pos=0;
	if(len <=0)
		return -1;
	psize = pow(2,len);
	pos = log(psize);
	printf("\nPowerset of A ::\n");
	printf("1.  { }");
	
	for(i=1;i<psize;i++)
	{
		printf("\n%d . {",i+1);
		for(j=0;j<=pos;j++)
			if(i & (1<<j))
				printf(" %d ",set[j]);
		printf("}");
	}
	printf("\n");
	return 0;
}
	
int main()
{
	int set1[100],set2[100],len1,len2;
	len1=readInput(set1);
	len2=readInput(set2);
	printSet(set2,len2);
	sort(set1,len1);
	sort(set2,len2);
	len1 = removeDuplicates(set1,len1);
	len2 = removeDuplicates(set2,len2);
	findUnion(set1,len1,set2,len2);
	findIntersection(set1,len1,set2,len2);
	findIfSubset(set1,set2,len1,len2);
	printPowerSet(set1,len1);
	return 0;
}
	
					

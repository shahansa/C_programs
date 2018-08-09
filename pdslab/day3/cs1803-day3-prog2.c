/*-----------------------------------
Name:shahansha salim
Roll number:cs1803	
Date:27-jly-2018
Program description:to find largest and second largest elements of an array
		    using less than 2n-3 comparisons
Acknowledgements: looked up tournament algorithm in stackoverflow
------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FAILURE -1
#define SUCCESS 0

static int ncomp; // to count number of comparisons
struct node {
	int value;
	struct node *left,*right;
	};

int printArray(struct node *arr,int len)
{
	int i;
	printf("\n");
	for(i=0;i<len;i++)
	{
		printf(" %d ",arr[i].value);
	}
	printf("\n");
	return 0;
}

int readInput(struct node *arr)
{
	int i=0,c;
	while(1)
	{
		scanf("%d",&c);
		if(c == -1)
			break;
		arr[i].value = c;
		arr[i].left = NULL;
		arr[i].right = NULL;
		i++;
	}
	return(i);
}

struct node* findMax(struct node *arr,int len)
{
	int i=0,j=0;
	struct node *round = NULL;
	
	if(len == 0)
		return NULL; //error condition
	if(len == 1)
		return(&arr[0]); //base condition
	
	round =(struct node *)malloc(((len/2) + 2)*sizeof(struct node));
	if(round == NULL)
		return NULL;
		
	while(i < (len-1))
	{
		if(arr[i].value >= arr[i+1].value)
		{
		    ncomp++;
		    round[j].value = arr[i].value;
		    round[j].left = &arr[i];
		    round[j].right = &arr[i+1];
		}
		else
		{
		    ncomp++;
		    round[j].value = arr[i+1].value;
		    round[j].left = &arr[i+1];
		    round[j].right = &arr[i];
		}	
		j++;
		i = i+2;
	}
	if((len %2) == 1)
	{
		round[j].value = arr[len-1].value;
		round[j].right = &arr[len-1];
		j++;
	}
	
	printArray(round,j);
	
	return(findMax(round, j));
				
}	

struct node* findSecondMax(struct node *max)
{
	struct node *secmax = max->right, *p = max,*temp=NULL;
	while(p->left != NULL)
	{
		p = p->left;
		if(p ->right  != NULL)
 		{
			temp = p->right;
			if(temp->value > secmax->value)
			{	
			    secmax = temp;
			}
		        ncomp++;		
		}
	}
	return secmax;	
}	
	

int main()
{
	struct node arr[100];
	 int len = 0;
	 struct node *max = NULL,*secmax = NULL;
	
	len = readInput(arr);
//	printArray(arr,len);
	if(len == 0)
	    return FAILURE;
	max = findMax(arr,len);
	printf("\n Max : %d\n",max->value);
	secmax = findSecondMax(max);
	printf("\n Second max : %d\n",secmax->value);
	return 0;
}
	

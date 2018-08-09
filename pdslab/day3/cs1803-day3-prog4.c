/*-----------------------------------
Name:shahansha salim
Roll number:cs1803
Date: 27-july-2018
Program description: multiply two matrices without using a new matrix
		     using dynamically allocated 2-D arrays
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define FAILURE -1
#define SUCCESS 0

int printMatrix(int **mat,int m,int n)
{
	int i,j;
	if(NULL == mat)
	{
		return FAILURE;
	}
	printf("\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	return SUCCESS;

}

int readMatrix(int **mat,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	
	return SUCCESS;
}
int multiplyMatrices(int **mat1,int **mat2,int m1,int n1,int m2,int n2)
{
	int i,j,k=0,res;
	printf("\nResult of multiplication:\n");
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{
			res=0;
			for(k=0;k<n1;k++)
			{
				res=mat1[i][k]*mat2[k][j];
			}
			printf("%d ",res);
		}
	printf("\n");
	}
	return SUCCESS;
}

int main(void)
{
	int **mat1=NULL,**mat2=NULL,m1,n1,m2,n2,i;
	printf("\n m1*n1 = ?\n");
	scanf("%d %d",&m1,&n1);
	printf("\n m2*n2 = ?\n");
	scanf("%d %d",&m2,&n2);
	if(n1 != m2)
	{
		printf("\nERROR : incompatable matrices\n");
		return FAILURE;
	}
	mat1 = (int **)malloc(m1*sizeof(int*));
	if(NULL == mat1)
	{
		printf("\nFAILURE : memory allocation\n");
		return FAILURE;
	}
	for(i=0;i<m1;i++)
	{
		mat1[i] = (int*)malloc(n1*sizeof(int));
	}
	mat2 = (int **)malloc(m2*sizeof(int*));
	if(NULL == mat2)
	{
		printf("\nFAILURE : memory allocation\n");
		return FAILURE;
	}
	for(i=0;i<m2;i++)
	{
		mat2[i] = (int*)malloc(n2*sizeof(int));
	}

	readMatrix(mat1,m1,n1);
	readMatrix(mat2,m2,n2);
	printMatrix(mat1,m1,n1);
	printMatrix(mat2,m2,n2);
	multiplyMatrices(mat1,mat2,m1,n1,m2,n2);
	return SUCCESS;
}

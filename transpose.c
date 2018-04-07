#include<stdio.h>
#include<stdlib.h>

/* program to find tranpose of a tensor
 * author: shahan , 7-Apr-2018 */



/*
 *Matrix transposition must be a familiar task. This problem is a generalization of it.  
 We can assume matrix transposition as a permutation of the two dimensions of the matrix. 
 Suppose the matrix dimensions are 16 x 8, the permutation for transpose is "1 0" where
 "1" means the first dimension of output comes from the 2nd (starting from 0) dimension of input
 and "0" means the second dimension of output comes from the first dimension of input. 
 The only other permutation possible here is "0 1" which gives output same as input. 
 For a 3D array, we can have 3!= 6 possible permutations possible. Now we can generalize this problem. 
 Given any higher dimensional array -- called a tensor -- and a given permutation, we should produce the output tensor. 
 Input must be read from a file and should be of the following form:

5   15 14 13 12 11       4 3 2 1 0

where the first entry denotes the number of dimensions followed by as many dimension values (lowest most or fastest 
varying dimension first) followed by the required permutation - explanation given in the previous paragraph. 

*/


static size_t total = 1;
void transpose(int n, const double *A, double *B,  const int *lda,  int *perm)
{
	int i,temp=0,j,loc=0;
	int *orgdim=NULL,*r_dim=NULL,*transp_dim=NULL;
	double *dimsize=NULL,*r_dimsize=NULL;
	
	orgdim = malloc(n*sizeof(int));
	r_dim = malloc(n*sizeof(int));
	dimsize = malloc(n*sizeof(double));
	r_dimsize = malloc(n*sizeof(double));
	transp_dim = malloc(n*sizeof(int));

	//find how much size each dimention takes starting from plane,3d subset,4d subset and so on.
	dimsize[0]=lda[0]; //size of a row
	dimsize[1] =  dimsize[0]*lda[1]; //size of 2d submatrix
	for(i=2,j=2; i<n ; i++)
	{
		dimsize[j] = dimsize[j-1] * lda[i];
		//dimsize[1] = size of 2d component
		//dimsize[2] = size of 3d component matrix
		//dimsize[3] = size of 4d component
		j++;
	}
	for(j=0;j<n;j++)
	{
		r_dim[j] = lda[perm[j]]; //dimentions of transposed matrix
	}
	r_dimsize[0]=r_dim[0]; //size of a row
	r_dimsize[1] = r_dimsize[0]*r_dim[1]; //size of 2d submatrix
	for(i=2,j=2; i<n ; i++)
	{
		r_dimsize[j] = r_dimsize[j-1] * r_dim[i];  //to calculate size of tranposed dimentions
		j++;
	}
	
        for(i=0;i<total;i++)
	{
		//for each value in A,find location in terms of dimentions and store in orgdim array.
		temp = i;
		for(j=n-1;j>0;j--)
		{
			orgdim[j] = temp/(int)dimsize[j-1];
			temp = temp % (int)dimsize[j-1];
		}
		orgdim[j] = temp;
		//now orig dim is like 0-1-2-3-4-5 . change it according to permutation
	 	for(j=0;j<n;j++)
		{
			transp_dim[j] = orgdim[perm[j]];
		}
		//store the value in B in corresponding transposed location
		for(j=n-1;j>0;j--)
		{
			loc+=transp_dim[j]*r_dimsize[j-1];
		}
		loc+=transp_dim[0];
		B[loc] = A[i];
		loc=0;
		
	}
	free(r_dimsize);
	free(r_dim);
        free(transp_dim);
	free(orgdim);
	free(dimsize);


}

#if 0
======================test==================
[lemontree@Arch C_programs]$ ./a.out inp1
16 15 14 13 12 	4 3 2 1 0 Number of errors: 0	
16 16 16 16 16 	4 3 2 1 0 Number of errors: 0	
16 16 	1 0 Number of errors: 0	
16 7 	1 0 Number of errors: 0	
10 10 10 10 	2 1 0 3 Number of errors: 0	
14 10 10 10 	2 1 0 3 Number of errors: 0	
10 10 10 10 	2 0 1 3 Number of errors: 0	
10 11 15 5 	2 0 1 3 Number of errors: 0	

#endif




int transpose_equal(const double *A, const double*B, int total_size){ 
	int error = 0; 
	const double *Atmp= A; 
	const double *Btmp= B; 
	for(int i=0;i < total_size ; ++i){ 
		double Aabs = (Atmp[i] < 0) ? -Atmp[i] : Atmp[i]; 
		double Babs = (Btmp[i] < 0) ? -Btmp[i] : Btmp[i]; 
		double max =  (Aabs < Babs) ? Babs : Aabs; 
		double diff = (Aabs - Babs); 
		diff = (diff < 0) ? -diff : diff; 
		if(diff > 0){ 
			double relError = (diff/max); 
			if(relError > 1.000000e-10){ 
				error += 1; 
			} 
		} 
	} 
	printf("Number of errors: %d\t\n",error); 
	return (error > 0) ? 0 : 1; 
}
int main(int argc, char* argv[])
{
	FILE * f;
	int dim[10];
	int permutation[10];
	int i, j;
	if(argc < 2)
	{
		fprintf(stderr, "Please input filename to read data\n");
		exit(0);
	}
	f = fopen(argv[1], "r");
	char line[255];
	char temp[50];
	int ndim;
	while(1)
	{
		total = 1;
		fscanf(f, "%d", &ndim);
		if(feof(f)){
			break;
		}
		for(i = 0; i < ndim; i++)
		{
			fscanf(f, "%d", &dim[i]);
			if(feof(f)){
				break;
			}
			printf("%d ", dim[i]);
			total *= dim[i];
		}
		printf("\t");
		for(i = 0; i < ndim; i++)
		{
			fscanf(f, "%d", &permutation[i]);
			printf("%d ", permutation[i]);
		}

		size_t totalsize = total * sizeof(double);
		double* A = (double*) malloc(totalsize);
		double* B = (double*) malloc(totalsize);
		double*	B_trans = (double *) malloc(totalsize);
		for(i=0; i < total ; ++i){
			A[i] = (double)i;
		}
		int r_perm[10], r_dim[10];
		for(i = 0; i < ndim; i++)
		{
			for(j = 0; j < ndim; j++)
			{
				if(permutation[j] == i)
				{
					r_perm[i] = j; 
					//r_dim[i] = dim[j];
					break;
				}
			}
			r_dim[i] = dim[permutation[i]];
		}
		transpose(ndim, A, B_trans, dim, permutation);
		transpose(ndim, B_trans, B, r_dim, r_perm);
		transpose_equal(A, B, total);
		free(A);
		free(B);
		free(B_trans);
	}
}



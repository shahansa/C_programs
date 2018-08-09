/*-----------------------------------
Name:Shahansha salim
Roll number:cs1803
Date:24-july-2018
Program description: to determine spearman's rank correlation
		     coefficient between two sets of floating point values
Acknowledgements:
------------------------------------*/

#include <stdio.h>
#include <math.h>

struct datanode{
	float num;
	float rank;
	}; 

int readInput(struct datanode *arr)
{
	int i=0;
	float c;
	while(1)
	{
		scanf("%f",&c);
		if(c == -1)
			break;
		arr[i].num = c;
		i++;
	}
	return(i);
}

int sortAndRank(struct datanode *set,int len)
{
	int i,j,n=1,pos,loc;
	float temp_var,rank_avg,rank_sum=0;
	struct datanode temparr[100];
	for(i=0;i<len;i++)
		temparr[i].num = set[i].num;
	for(i=0;i<(len-1);i++)
	{
		for(j=0;j<(len-i-1);j++)
		{
			if(temparr[j+1].num<=temparr[j].num)
			{
				temp_var = temparr[j].num;
				temparr[j].num=temparr[j+1].num;
				temparr[j+1].num=temp_var;
			}
		}		
	}
	for(i=0;i<len;i++)
		temparr[i].rank = (i+1);
	
	//handle ties
	for(i=0;i<len;i++)
	{
		if(temparr[i].num == temparr[i+1].num)
		{
			//chance for sequence of tied values starting from i
			pos=i;
			loc = i;
			rank_sum =0;
			rank_sum=temparr[pos].rank;
			while(temparr[pos].num == temparr[pos+1].num)
			{
				rank_sum+=temparr[pos+1].rank;
				pos++;n++;
				
			}
			rank_avg=rank_sum/(float)n;
			for(j=loc;j<=pos;j++)
			{
				temparr[j].rank = rank_avg;
				i++;
			}
			i--;
				
					
		}
	}

	//test print
	printf("\n");
	for(i=0;i<len;i++)
		printf(" %2.1f ",temparr[i].rank);
	
	//assign the ranks in sorted temp array back to original unsorted data set

	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(temparr[i].num == set[j].num)
			{
				set[j].rank = temparr[i].rank;
				break;
			}
		}
	}
	return 0;

}

int main()
{
	struct datanode set1[100],set2[100];
	int len1,len2,i,lensq;
	unsigned int diffrank[100],sum_d_sq=0;
	float rho;
	len1 = readInput(set1);
	len2 = readInput(set2);
	if(len1 != len2)
		return -1;
	sortAndRank(set1,len1);
	sortAndRank(set2,len2);
	
 	//calculate d for each data set value
	for(i=0;i<len1;i++)
		diffrank[i]=set1[i].rank-set2[i].rank;
	
	//calculate d^2
	for(i=0;i<len1;i++)
		diffrank[i]=pow(diffrank[i],2);
	
	for(i=0;i<len1;i++)
		sum_d_sq+=diffrank[i];
	lensq = len1*pow(len1,2);
	rho = 1-((float)(6*sum_d_sq)/(float)lensq);
	
	printf("\nSpearman's rank correlation coefficient(rho) = %2.2f\n",rho);
	
	
	return 0;
	

}

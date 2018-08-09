/*-----------------------------------
Name:Shahansha Salim
Roll number:cs1803      
Date : 31-july-2018
Program description: to calculate given function recursively and iteratively

Acknowledgements:
------------------------------------*/

#include <stdio.h>

int recursiveGx(int n)
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else if( n == 2)
		return 2;
	else
		return (recursiveGx(n-1)+recursiveGx(n-2)+recursiveGx(n-3));

}

int iterativeGx(int n)
{
    int fnm1,fnm2,fnm3,result=0; 
   	if(n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
    fnm1 = iterativeGx(n-1);
    fnm2 = iterativeGx(n-2);
    fnm3 = iterativeGx(n-3);
    result = fnm1+fnm2+fnm3;
    return(result);    
}

int main()
{
	int n;
	scanf("%d",&n);
	if(n<0)
	{
		printf("\ninvalid\n");
		return -1;
	
	}
    printf("\nfunction value recursive : %d\n",recursiveGx(n));
     
    printf("\nfunction value iterative : %d\n",iterativeGx(n));
    return 0;
} 

/*
name:Shahansha Salim
Roll number:cs1803      
Date : 31-july-2018
Program description: last one picks looses game
		 
                    
Acknowledgements:
------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

int getChoosing(int,int);

int firstUser(int sticks)
{
	int choosing=0,turn=0;
	printf("\nusers turn :\n");
	scanf("%d",&choosing);		
	sticks = sticks-choosing;
	printf("\nsticks left :%d\n",sticks);
	while(sticks > 1)
	{	
		turn = turn==0?1:0;
		choosing = getChoosing(turn,sticks);
		sticks -= choosing;
		printf("\nsticks left :%d\n",sticks);
	}
	if(turn == 0)
	{
		printf("\n computer lost\n");
	}
	else
		printf("\nuser lost\n");

	
	return 0;
}
int getChoosing(int turn,int sticks)
{
	int choosing=0,limit;
	if(turn == 0)
	{
		printf("\n users turn :\n");
		scanf("%d",&choosing);
	}
	else
	{
		//computers turn
		// try to make stics 4n+1
		printf("\ncomputer's turn");
		if(sticks >=9)
			limit = 9;
		else if(sticks >=5)
			limit = 5;
		else
			limit = 1;
		if((sticks-limit) <= 3)
		{
			if(sticks-limit != 0)
				choosing = sticks-limit;
			else 
				choosing = ((rand())%3)+1;
		}
		else
			choosing = 3;
		printf("\ncomputer chose %d\n",choosing);
	}
	return(choosing);
}
int firstComputer(int sticks)
{
	int choosing,turn=1;
	printf("\n sticks remaining :%d",sticks);
	printf("\n Computer takes 2");
	sticks = sticks -2;
	while(sticks >1)
	{
		
		turn = turn==0?1:0;
		choosing = getChoosing(turn,sticks); 
		sticks -= choosing; 
		printf("\nsticks left :%d\n",sticks);
	}
	if(turn == 0)
	{
		printf("\n computer lost\n");
	}
	else
		printf("\nuser lost\n");
	return 0;	
}

int main()
{

	int sticks = 11,choice;
	printf("\nwho plays first ? 1. computer 2. user\n");
	scanf("%d",&choice);
	if(choice == 1)
		firstComputer(sticks);
	else if (choice == 2)
		firstUser(sticks);
	else 
		printf("\ninvalid choice\n");
	return 0;
}

/*
	in this program we create 3 function including main and 2 helper function
*/

#include<stdio.h>
#include<stdlib.h>


void fun()
{
	printf("inside fun\n");
}

void gun()
{
	printf("inside gun\n");
}

int main()
{
	
	if(atexit(fun) != 0)
	{
		printf("Error to call fun\n");
	}
	
	if(atexit(gun) != 0)  //gun internally represent address
	{
		printf("Error to call gun\n");
	}
	
	printf("End of main \n");
	
	
}

/*
write a program to demonstrate use of flushall
*/

#include<stdio.h>

int main()
{
	
	int ires = 0;
	
	printf("inside main\n");
	
	ires = fflush(stdout);
	
	printf("ires is : %d\n",ires);
	
	return 0;
}

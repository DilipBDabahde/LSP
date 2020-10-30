#include<stdio.h>

void fun(), gun();	//function declaration

int main()
{
	printf("inside main\n");
	fun();
	gun();
	
	return 0;
}

void fun()
{
	printf("inside fun\n");
}

void gun()
{
	printf("inside gun\n");
}

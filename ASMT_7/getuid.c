/*
	program to display user id and group id
*/
#include<stdio.h>
#include<unistd.h>


int main()
{

	printf("user id : %d\n",getuid());
	printf("group id: %d\n",getgid());
	
	return 0;
}

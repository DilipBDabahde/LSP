/*
	program to create max child process
*/

#include<stdio.h>
#include<unistd.h>


int main()
{

	printf("Max child process can create : %ld\n",sysconf(_SC_CHILD_MAX));
	
	
	return 0;
}

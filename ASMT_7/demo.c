/*
	create exe of this program to use into parent child vfork program
	
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("child process running with pid: %d\n",getpid());
	return 0;
}

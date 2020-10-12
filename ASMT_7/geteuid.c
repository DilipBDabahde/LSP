/*
	program to display get effective uid and effective gid
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Effective uid : %d\n",geteuid());
	printf("Effective gid : %d\n",getegid());


	return 0;
}

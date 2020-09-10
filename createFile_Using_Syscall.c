// accept cml input from user and such as filename and create file using open sys call

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	
	fd = open("Dada.txt", O_RDWR`);
	
	printf("%d\n",fd);


	return 0;
}

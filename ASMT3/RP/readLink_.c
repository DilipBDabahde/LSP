/*
accept softlink filename from use and read path from that file


*/

#include<stdio.h>
#include<unistd.h>

#define MAXSIZE 256

int main(int argc, char *argv[])
{
	ssize_t ret;
	char buff[MAXSIZE];
	
	if(argc != 2)
	{
		printf("insufficient arguments\n");
		return -1;
	}
	
	ret = readlink(argv[1], buff, MAXSIZE);
	
	if(ret == -1)
	{
		printf("Error to read link\n");
		return ret;
	}
	
	printf("linked path is read sucessfully : %s\n",buff);

	return 0;
}

/*
accept file name from user and check that file is existing or not

input: demo.txt  

if it is existing in . dir that display its existing else display given file doen not exist
*/

#include<stdio.h>
#include<unistd.h>


int main(int argc,char *argv[])
{
	int fd;
	
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	fd = access(argv[1], F_OK);  //F_OK to test file is existing or not
	
	if(fd == -1)
	{
		printf("%s : file is not existing\n",argv[1]);
		return -1;
	}

	printf("%s : file is existing\n",argv[1]);


	return 0;
}

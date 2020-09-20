/*
accept filename from user and remove

return 0 on sucees
return -1 on error
*/

#include<stdio.h>

int main(int argc, char *argv[])
{
	int fd;
	
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	fd = remove(argv[1]);
	
	if(fd == -1)
	{
		printf("Error : To remove file\n");
		return -1;
	}
	
	printf("File removed successfully\n");
	
	
	return 0;
}

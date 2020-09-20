/*
accept file name fromuser and unlink/remove that file
return 0 on success
return -1 on error
*/


#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
	int fd;

	if(argc != 2)
	{
		printf("Insufficient argument\n");
		return -1;
	}
	
	
	fd = unlink(argv[1]);
		
	if(fd == -1)
	{
		printf("Error to unlink file\n");
		return -1;
	}
	
	printf("File Unlinked successfully\n");
	
	close(fd);
	


	return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int  main(int argc, char const *argv[])
{
	
	int fd;
	int ret;

	fd = open(argv[1], O_RDWR);

	if(fd == -1)
	{
		printf("Unable to open file\n");
	}
	printf("file opened file\n");

	printf("Enter value: ");
	scanf("%d",&ret);

	printf("Entered value is: %d\n",ret);

	int status = close(STDIN_FILENO); //we close here keyboard inut so below scanf function does not working
	printf("status of STDIN_FILENO is %d\n",status);

	printf("Enter value: ");
	scanf("%d",&ret);	//not able to take input from keyboard 
	printf("Entered value is: %d\n",ret);

	close(fd);
	

	return 0;
}
/*


*/

#include<stdio.h> //to input output operation 
#include<fcntl.h>
#include<unistd.h> // to read file


int main(int argc, char *argv[])
{

	int fd = -1;
	
	fd = open(argv[1], O_RDWR); //no need to add file access permission now
	
	ssize_t read(int fd1, void *buf, size_t len);
	
	while(*buf != '\0')
	{
		printf("%c",*buf);
		buf++;
	}
	
	
	printf("%d\n",fd);
	


	
	return 0;
}


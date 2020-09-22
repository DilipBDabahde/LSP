/*
accept source dir file and dest dir file and data from src to dst file

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXSIZE 128

int main(int argc, char *argv[])
{
		int fd1, fd2, fd, ret1, ret2;
		char buff[MAXSIZE];
		
		//checking arguments count that we expect
		if(argc != 3)
		{
			printf("Insufficent arguments\n");
			return -1;
		}
		
		//opening src file
		fd1 = open(argv[1], O_RDONLY);
		
		if(fd1 == -1)
		{
			printf("Error to access source file\n");
			close(fd);
			return -1;
		}
		
		//opening dst file
		fd2 = open(argv[2], O_WRONLY | O_APPEND );
		
		if( fd2 == -1)
		{
			printf("Error to open destination file\n");
			close(fd1);
			close(fd2);
			return -1;
		}
		
		//once both file opened then perfomr read/write operation on them
		
		while( (ret1 = read(fd1, buff, MAXSIZE)) > 0) //reading till buff gets full or till end of data
		{
			if( ret2 = write(fd2, buff, ret1) != ret1) //writtiing till end of buff or till gets 0
			{}
		}
		
		if(ret1 == -1)
		{
			printf("Error to read source file\n");
			close(fd1);
			close(fd2);
			close(ret1);
			close(ret2);
			return -1;
		}
		
		if(ret2 == -1)
		{
			printf("Error to write destination file\n");
			close(fd1);
			close(fd2);
			close(ret1);
			close(ret2);
			return -1;
		}
		
		printf("Data gets copied to destination file\n");
		
		close(fd1);
		close(fd2);
		close(ret1);
		close(ret2);
		
	
	return 0;
}

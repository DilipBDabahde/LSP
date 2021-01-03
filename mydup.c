/*
in this application we create duplicate fd of existing fd

here we dup old fd with new fd then fd1 and fd2 has diff id but they have same opened entry of file table
so fd1 and fd2 can perform same type operation on opened file
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


#define BUFSIZE 512

int main(int argc, char *argv[])
{

	int fd1 =0, fd2 =0, ret =0;
	char buff[BUFSIZE] = {'\0'};
	
	
	if(argc != 2)
	{
		printf("invalid arguments count\n");
		return -1;	
	}


	fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1)
	{
		printf("error to open file\n");
		return -1;
	}
	printf("%s file open successfully\n",argv[1]);
	
	
	fd2 = dup(fd1);	//fd1 and fd2 with get diff ids but the location address they get that is same with open mode/flags
	if(fd2 == -1)
	{
		printf("dup fails\n");
		return -1;
	}
	printf("fd1 is : %d\n",fd1);
	printf("fd2 is : %d\n",fd2);
	
	while((ret = read(fd2, buff, BUFSIZE)) > 0)
	{
		if(ret == -1)
		{
			printf("error to read\n");
			close(fd1);
			close(fd2);
			return -1;
		}
		
		if(write(1, buff, ret) != ret)
		{
			write(1, "write error\n", strlen("write error\n"));
			close(fd1);
			close(fd2);
			return -1;
		}
	}
	
	close(fd1);
	close(fd2);

	return 0;
}

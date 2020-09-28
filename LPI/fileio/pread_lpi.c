/*
	accept file name from user and perform read from perticular offset using pread(fd, buff, sizeof(buff), offset)
	
	in this applicatiion  instead of lseek(fd, offset, whence) and read(fd,buff, sizeof(buff)) 
	we do it in one call this pread() sys call is used to perform atomica operation of perticular offset 
	with no lseek
	usage : 	//random read from perticular bytes onward 

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>


#define MAXSIZE 1024

int main(int argc, char *argv[])
{

	int fd, ret;
	char buff[MAXSIZE] = {'\0'};
	
	if(argc != 3)
	{
		printf("invalid arguments count\n");
		return -1;
	}
		
	//open file
	
	fd = open(argv[1], O_WRONLY);  // O_RDONLY not work
	
	if(fd == -1)
	{
		printf("error to open : %s\n",argv[1]);
		close(fd);
		return -1;
	}
	
	printf("file opened succcessfully\n");	
	
	//random read from perticular bytes onward 
	
	ret = pread(fd, buff, MAXSIZE, atoi(argv[2]));  //10 bytes onward read till EOF
	
	if(ret == -1)
	{
		printf("error to read file : %s\n",argv[1]);
		close(fd);
		return -1;
	}	
	
	
	printf("Total read bytes : %d\n",ret);
	printf("%s\n",buff);
	

	return 0;
}

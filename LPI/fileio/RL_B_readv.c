/*
	accept file name from user and read data into file 
	using readv(fd, iov, count)
	
*/


#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/uio.h>
#include<unistd.h>
int main(int argc, char *argv[]) 
{
	int fd, ret;
	struct iovec iov[3]; 
	//char *buff[] = { "what is your name_\n", "My name is Ravi\n", "Wow very nice name\n" };	
	char buff1[48], buff2[51], buff3[49];
	
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}	
	fd = open(argv[1], O_RDONLY);	
	if(fd == -1)
	{
		printf("Error to open file: %s\n",argv[1]);
		return -1;
	}							//assign address of 3 buffer and their len for buffer	

	iov[0].iov_base = buff1;
	iov[0].iov_len = sizeof(buff1);
	iov[1].iov_base = buff2;
	iov[1].iov_len = sizeof(buff2);
	iov[2].iov_base = buff3;
	iov[2].iov_len = sizeof(buff3);
	
	ret = readv(fd, iov, 3);				//now we fill all buffer with data
	
	if(ret == -1)	
	{
		printf("readv error\n");
		return -1;
	}
	
	for(int i = 0; i < 3; i++)
	{
		printf("%d : %s",i, (char*) iov[i].iov_base);  //to display data of filled buffer
	}
		
	printf("%d bytes wrote\n",ret);	
	close(fd);
	return 0;
}


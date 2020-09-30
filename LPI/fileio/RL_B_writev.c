/*
	accepting file name from user and writing 3 string in one call
	
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
	char *buff[] = {
					"The term buccaneer comes from the word boucan.\n",
					"A boucan is a wooden frame used for cooking meat.\n",
					"Buccaneer is the West Indies name for a pirate.\n" };
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}	
	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);	
	if(fd == -1)
	{
		printf("Error to open file: %s\n",argv[1]);
		return -1;
	}							//assign address of 3 buffer and their len for buffer	
	for(int i = 0; i < 3; i++)
	{
		iov[i].iov_base = buff[i];
		iov[i].iov_len = strlen(buff[i])+1;		
		printf("Len is : %ld\n",iov[i].iov_len);
	}	
	ret = writev(fd, iov, 3);			
	if(ret == -1)
	{
		printf("writev\n");
		return -1;
	}	
	printf("%d bytes wrote\n",ret);	
	close(fd);
	return 0;
}


//writing data into file

#include<stdio.h>  //to i/o operation
#include<fcntl.h> //for file flags
#include<unistd.h>  // to accept system calls

int main()
{
	
	int fd;
	int ret;
	int offset;
	
	char buff[] = "India is my country";
	char buff1[sizeof(buff)];
	
	
		fd = open("mytext.txt", O_RDWR | O_CREAT);
		
		if(fd == -1)
		{
			printf("Unable to open file\n");
			return -1;
		}
		
		ret = write(fd, buff, sizeof(buff)); //write data into antother bfuff
		
		
		if(ret != sizeof(buff))
		{
			printf("unable to write\n");
		}
		
		lseek(fd, 0, SEEK_SET);	//SEEK_SET to start of file 
		
		ret = read(fd, buff1, sizeof(buff1)); //reading data of file 
		
		printf("Writtern data is ---> %s\n",buff1); //displaying data of file
		
		close(fd);	//closing file which is above opened
		close(ret);

	return 0;
}

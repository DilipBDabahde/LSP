/*
	customized readv function 
	in this program we read data from file into multiple buffer
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/uio.h>


int myread(int fd, struct iovec *iov, int count)
{
	ssize_t ret, rn;
	
	for(int i = 0; i < count; i++)
	{		
		rn = read(fd, iov[i].iov_base, iov[i].iov_len);
		
		if(rn == -1)
		{
			break;
		}
		
		ret += rn;	
	}
	
	if(rn == -1)
		return rn;
	else
		return ret;
}

int main(int argc, char *argv[])
{
	int fd, ret;
	char arr[20], brr[17], crr[20];
	struct iovec iov[3];	
	
	if(argc != 2)
	{
		printf("invalid arguments count\n");
		return -1;
	}

	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file: %s\n",argv[1]);
		return -1;
	}
	
	////////////////////////////////////////////////
	iov[0].iov_base = arr;
	iov[0].iov_len = sizeof(arr); //bcs we read
	
	iov[1].iov_base = brr; ///address assign
	iov[1].iov_len = sizeof(brr);
	
	iov[2].iov_base = crr;
	iov[2].iov_len = sizeof(crr);  
	
	///////////// all member initialized with address and length ////////////
	
	ret = myread(fd, iov, 3);  //till call everything should be set ok to fill data into arrays
	
	if(ret == -1)
	{
		printf("error read\n");
		return -1;
	}
	
	printf("read works\n");
	
	for(int i =0; i< 3; i++)
	{
		printf(" %d : %s\n",i,  (char*)iov[i].iov_base);
	}
	
	
	close(fd);
	return 0;
}



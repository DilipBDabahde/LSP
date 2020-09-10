#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>


char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";


int main(int argc, char *argv[])
{


	int fd;
	
	if ( fd = creat(argv[1],S_IRWXU) < 0)
		printf("can't create file\n");
		return -1;
	
	if(write(fd, buf1, 10) != 10)
		printf("Buf write error\n");
		return -1;
	
	


	

	return 0;
}

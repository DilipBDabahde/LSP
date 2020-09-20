/*
accept fiile name from user and dispaly its inode number name size uisng fstat(int fd, struct stat *ptr/&obj)

&obj is empty object when we provide fd then all info of file stores into obj

*/

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h> 

int main(int argc, char *argv[])
{
	int fd ;
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		return -1;
	}
	else
	{
		printf("File is open with O_RDONLY\n");
	}

	struct stat Obj1;
	fstat(fd, &Obj1); 	//obj initilization

	printf("File Name : %s\nFile Inode : %ld\n",argv[1], Obj1.st_ino);
	printf("File size is : %ld\n",Obj1.st_size);
	
	close(fd);
	
	return 0;
}



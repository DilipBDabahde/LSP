//accept  cmd input as file name from user and create file with given name in . dir
//input : Demo.txt   <---- this named file would be created in . dir

#include<stdio.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
	int fd;
	
	fd = creat(argv[1], 0777);
	if(fd == -1)
	{	
		printf("Unable to create file\n");	
	}

	printf("%s file created sucessfully\n",argv[1]);
	
	return 0;
}


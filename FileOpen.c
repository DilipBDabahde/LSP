
// to open file with flags  O_WRONLY | O_CREAT | O_TRUNC 
//file access permition 👨‍👨‍👦️ S_IWUSR | S_IRUSR | S_IWGRP | S_IWUSR | S_IROTH 👨‍👨‍👦️
//if file is all ready exists newly created file update atplace
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{

	int fd;
	
	fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC , S_IWUSR | S_IRUSR | S_IWGRP | S_IWUSR | S_IROTH);
	
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	printf("%s file opened Successfully\n",argv[1]);

	return 0;
	
}

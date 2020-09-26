/*
create struct of file such as

struct file_
{
	char fname[255];
	int fsize;
};

after creating structure fill some entries of filenames and sizes randomly

to do this task create one new file and write file names and size of file into newly created file

$gcc writer.c
$ ./a.out fileinfo   <-----new file is gets created to write file names ans sizes



*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio_ext.h>

struct file_
{
	char fname[255];
	int fsize;
};

int main(int argc, char *argv[])
{

	int size = 0;
	int fd;
	char arr[512];
	int ret;
	
	
	printf("Enter size of files entries: ");
	scanf("%d",&size);
	
	struct file_ Obj[size]; //array of object
	
	
	fd  = creat(argv[1], 0777);
	
	if(fd == -1)
	{
		printf("Error to create new file\n");
		close(fd);
		return -1;
	}
	
	int i = 0;
	while(i < size)
	{	
		__fpurge(stdin);
		printf("Enter filename: ");
		scanf("%[^'\n']s",Obj[i].fname);
		
		printf("Enter filesize: ");
		scanf("%d",&Obj[i].fsize);
		
		write(fd, &Obj[i], sizeof(Obj[i]));
			
		i++;
	}
	
	printf("%d file entries created\n",i);


	return 0;
}

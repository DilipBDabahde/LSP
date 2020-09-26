/*
create struct of file such as

struct file_
{
	char fname[255];
	int fsize;
};

after creating structure fill some entries of filenames and sizes randomly

to do this task create one new file and write file names and size of file into newly created file


Use created file which gets created in Write_struct 

$gcc readr.c
$./a.out fileinfo

fileinfo need to read in this program which is filled with filename and size

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
	
	
	fd  = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		close(fd);
		return -1;
	}
	
	int i = 0;
	while(i < size)
	{	
		__fpurge(stdin);
				
		read(fd, &Obj[i], sizeof(Obj[i]));
		printf("Filename: %s\nfilesize%d\n",Obj[i].fname, Obj[i].fsize);
		printf("-----------------------------------------------------\n");
		i++;
	}
	
	printf("%d file entries written to file %s\n",i, argv[1]);


	return 0;
}

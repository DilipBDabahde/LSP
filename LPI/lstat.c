/*
accept file name from user nd displayy its  use lstat
Name
inode
size 
type

int ret = lstat(filename, &obj1);   //obj will gets initilized in call gets back with file info


stat, lstat, fstat 3 functions
retun 0 on sucess
return -1 on error

stat struct holds metadata about file
*/

#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>


int main(int argc, char *argv[])
{
	
	
	int ret;
	struct stat obj;
	
	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	ret = access(argv[1], R_OK); //access to test file permission
	
	if(ret < 0)
	{
		printf("Error to access file\n");
		close(ret);
		return -1;
	}
	
	printf("file accessed properly\n");
	
	ret = lstat(argv[1], &obj);
	
	if(ret == -1)
	{
		printf("Error to lstat file\n");
		return -1;
	}
	
	printf("Obj initilized with file info\n");
	
	printf("File name: %s\n",argv[1]);
	printf("FileiNode: %ld\n",obj.st_ino);
	printf("FileSize : %ld\n",obj.st_size);
	printf("FileblkSZ : %ld\n",obj.st_blksize);
	printf("FileBlocks : %ld\n",obj.st_blocks);
	
	close(ret);


return 0;
}

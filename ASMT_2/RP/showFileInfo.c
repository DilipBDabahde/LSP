/*
4. Write a program which accept file name from user and print all information about that file.

all info file gets into inode structure

struct stat {
               dev_t     st_dev;         
               ino_t     st_ino;         
               mode_t    st_mode;      
               nlink_t   st_nlink;      
               uid_t     st_uid;        
               gid_t     st_gid;         
               dev_t     st_rdev;        
               off_t     st_size;        
               blksize_t st_blksize;     
               blkcnt_t  st_blocks;      
		   }

		
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
	struct stat obj;
	
	int fd;
	
	if(argc != 2)
	{
		printf("insufficient arguments\n");
		return -1;
	}
	
	fd = access(argv[1], F_OK); //to check file exist or not
	
	if(fd == -1)
	{
		printf("Given file name is not existing\n");
		return -1;
	}
	
	//stat objected initilizing in stat call and display info of file
	
	stat(argv[1], &obj);
	
	printf("File name:\t\t%s\n",argv[1]);
	printf("File type:\t\t");
	if(S_ISREG(obj.st_mode))
	{
		printf("regular\n");
	}
	else if(S_ISDIR(obj.st_mode))
	{
		printf("Directory\n");
	}
	else if(S_ISCHR(obj.st_mode))
	{
		printf("Character\n");
	}
	else if(S_ISLNK(obj.st_mode))
	{
		printf("Symbolik link\n");
	}
	else
	{
		printf("Unknonw file type\n");
	}
	
	printf("File inode:\t\t%ld\n",obj.st_ino);
	printf("File uid:\t\t%d\n",obj.st_uid);
	printf("File gid:\t\t%d\n", obj.st_gid);
	printf("File size:\t\t%ld\n", obj.st_size);
	printf("File block size:\t%ld\n", obj.st_blksize);
	printf("File block:\t\t%ld\n",obj.st_blocks);
	printf("File dev num of Filesystem :\t%ld\n",obj.st_dev); //actual block where file data stores in file system
		
	return 0;
}

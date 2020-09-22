/*
accept file name from user and directory name path where we want to create hard link of our file

$ gcc mydemo.c  -o myexe
$ ./myexe /home/user/Programs/c/today.c  /home/user/Desktop/Sunday.c

in this case our source file path is: /home/user/Programs/c/today.c
our destination path is:			  /home/user/Desktop/Sunday.c

Hardlink of today.c gets created into destination path with link count 2 and their inode number is same


*/

#include<stdio.h>
#include<unistd.h>



int main(int argc, char *argv[])
{
	
	int ret;
			
	ret = link(argv[1], argv[2]);
	
	if(ret == -1)
	{
		printf("Error : Create file link to targeted  location\n");
		return -1;
	}
	
	printf("Hard link is created of given file into destination location\n");
	
	return 0;
}

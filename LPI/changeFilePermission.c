/*
accept file name from user as well as file permission
change permission of file

input: filename 	S_IRSER | S_IWUSE


On success return 0
on error return -1

before chmod
  File: file.txt
  Size: 21        	Blocks: 8          IO Block: 4096   regular file
Device: 807h/2055d	Inode: 2760717     Links: 1
Access: (0644/-rw-r--r--)  Uid: ( 1000/   dilip)   Gid: ( 1000/   dilip)
Access: 2020-09-20 02:55:35.748181862 +0530
Modify: 2020-09-20 02:55:33.243803332 +0530
Change: 2020-09-20 02:55:33.243803332 +0530
 Birth: -

after chmod
  File: file.txt
  Size: 21        	Blocks: 8          IO Block: 4096   regular file
Device: 807h/2055d	Inode: 2760717     Links: 1
Access: (0774/-rwxrwxr--)  Uid: ( 1000/   dilip)   Gid: ( 1000/   dilip)
Access: 2020-09-20 02:55:35.748181862 +0530
Modify: 2020-09-20 02:55:33.243803332 +0530
Change: 2020-09-20 13:37:25.990138381 +0530
 Birth: -
dilip@dilip-In


*/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
	int ret;
	
	int permission = S_IRWXU | S_IRWXG | S_IROTH;
	
	printf("%d\n",permission);
	
	ret = chmod(argv[1], permission);
	
	if(ret)
	{
		perror("chmod\n");
		return -1;
	}
	
	printf("Permission chaged \n");


	return 0;
}

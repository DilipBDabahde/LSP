/*
accept regular file name to create symbolic link 
input: "Source_path"   "Destination_path" 		<---- at both location there are two files to perform this operation

source location which contains regular type file and in destination location it contains path of source location file
but type of destination location file is symlink/softlink/symbolik link

when we open file destination file mean softlink then we get access of regulartype file which is mention in softlink

if we regular file is deleted and we try to open it then it may generate error known as dangling symbolik link
*/

#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]) //array of pointer of type char *argv[]
{
	int ret;
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	ret = symlink(argv[1], argv[2]);   //return 0 on success / on error -1
	
	if(ret == -1)
	{
		printf("Error to create symlink/sorflink\n");
		return ret;
	}

	printf("Symbolink link is created in destination location\n");
	
	return 0;
}

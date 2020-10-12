/*
	cmd ls implementaion
	
	accept path from user and display its files
	
	
*/


#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>




void Display_ls(char *path)
{
	printf("Given path is : %s\n",path);
	
	struct dirent *dir = NULL;
	DIR *dp = NULL;
	
	
	dp = opendir(path);
	
	if(dp == NULL)
	{
		printf("Error to open directory\n");
		return;
	}
	
	printf("Dir open successfully : %s\n",path);
	
	while((dir = readdir(dp)) != NULL)
	{
		printf("%s\n",dir->d_name);	
	}
	
	
	

}

int main(int argc, char *argv[])
{

	if(argc != 2)
	{
		printf("invalid arguments count\n");
		return -1;
	}
	
	Display_ls(argv[1]);

	return 0;
}

/*
1.  Write a program which creates new process which is responsible to write all file names which
    are present on desktop in demo.txt file which should be created newly.
    
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>



int main(int argc, char *argv[])
{
	pid_t pid;			// to get pid
	struct dirent *dp;	//to read dir entries
	DIR *dir;			//to open dirstream
	int fd;
	char ch = '\n';
	int icnt = 0;
	
	if(argc != 3)
	{
		printf("invalid argumets count\n");
		return -1;
	}
	
	printf("parent process pid: %d\n",getpid());
	
	//create new process
	
	pid =fork();		//call to create child proc
	
	if(pid == -1)
	{
		perror("fork");
		return -1;
	}
	else if(pid != 0)
	{
		printf("parent process pid: %d\n",getpid());
		exit(EXIT_SUCCESS);
	}

	printf("child process pid: %d\n",getpid());
	
	dir = opendir(argv[1]);  //opening directory
	
	if(dir == NULL)
	{
		perror("opendir");
		return -1;
	}
	
	printf("Dir open successfully\n");
	
	fd = creat(argv[2], 0777); //creat file to write all files entries into this file
	
	if(fd == -1)
	{
		perror("creat");
		return -1;
	}
	
	printf("file created successfully\n\n");
	
	while((dp = readdir(dir)) != NULL)
	{
		if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
		{
			continue;
		}
		
		char *ptr = (char*)malloc(sizeof(strlen(dp->d_name)+1));
		
		sprintf(ptr, "%s%c",dp->d_name,ch);
		
		write(fd, ptr, strlen(dp->d_name)+1);
		
		free(ptr);
		icnt++;
	//	printf("%s\n",dp->d_name);
	}
	
	printf("Total files entries made : %d\n",icnt);
	close(fd);
	closedir(dir);

	exit(EXIT_SUCCESS);

	return 0;
}

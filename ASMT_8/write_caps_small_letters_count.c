/*
2.  Write a program which creates two processess.
	Process 1 count number of capital characters from demo.txt file. And process 2 count
	number of capital characters from hello.txt file. Both the processess writes its count in
	count.txt file.
    
 input: $gcc progra.c -o myexe
 	    $./myexe demo.txt hello.txt  count.txt


data of demo.txt -:  My Love Sweet   
				  : 3 cap letters

data of hello.txt : mY lOVE sWEET
				  : 3 small letters

count in count.txt
				 : data.txt contains  : 3 caps letters
				 : hello.txt contains : 3 small letters
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>



int main(int argc, char *argv[])
{	

	pid_t child_1, child_2;
	int icap = 0, ismall = 0;
	char buff[128] = {'\0'};
	int fd1, fd2;
	
	
	fd2 = creat(argv[3], 0777);
	
	if(fd2 == -1)
	{
		perror("creat");
		return -1;
	}
		
	//process creation
	(child_1 = fork()) && (child_2 = fork());
	
	
	if(child_1 == -1 || child_2 == -1)
	{
		perror("fork");
		close(fd2);
		close(fd1);
		return -1;
	}	
	
	if(child_1 == 0)  //capital count
	{
		int icnt = 0;
		int i = 0, ret  = 0;
		
		//file openeing
		fd1 = open(argv[1], O_RDONLY);	
		if(fd1 == -1)
		{
			printf("Error to open file: %s\n",argv[1]);
			return -1;
		}
		
		while((ret = read(fd1, buff, sizeof(buff))) != 0)
		{
			i = 0;
			while(i < ret)
			{
				if(buff[i] >= 'A' && buff[i] <= 'Z')
				{
					icnt++;
				}
				i++;
			}
		}
		
		char *ptr = (char*)malloc(512);
		
		sprintf(ptr,"In file [- %s -] total capital letters are : %d\n",argv[1], icnt);		
		
		write(fd2, ptr, strlen(ptr));	
		free(ptr);	
		memset(buff, 0 ,sizeof(buff));
	}
	else if(child_2 == 0)
	{
		int icnt = 0;
		int i = 0, ret  = 0;
		
			//file openeing
		fd1 = open(argv[2], O_RDONLY);	
		if(fd1 == -1)
		{
			printf("Error to open file: %s\n",argv[2]);
			return -1;
		}
			
		while((ret = read(fd1, buff, sizeof(buff))) != 0)
		{
			i = 0;
			while(i < ret)
			{
				if(buff[i] >= 'a' && buff[i] <= 'z')
				{
					icnt++;
				}
				i++;
			}
		}
		
		char *ptr = (char*)malloc(512);
		
		sprintf(ptr,"In file [- %s -] total small letters are : %d\n",argv[2], icnt);		
		
		write(fd2, ptr, strlen(ptr));	
		free(ptr);	
		
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
	
	return 0;
}

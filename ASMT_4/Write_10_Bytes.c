/*
4. Write a program which accept directory name from user and copy first 10 bytes from all
   regular files into newly created file named as demo.
   
input: Mydir	Filedata.txt

output: from Mydir each regular file open and read first 10 or < 10 bytes to write into Filedata.txt
	
*/

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>


#define MAXSIZE  10


int main(int argc, char *argv[])
{
	int fd1, fd2, ret1;
	DIR  *dirp = NULL;					//to open directory
	struct dirent *dp = NULL;			// to get access of directory entries
	struct stat fileinfo;
	char buff[MAXSIZE];
	char *temp = NULL;
	int icnt = 0;
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	//check given dir is exist or not
	
	stat(argv[1], &fileinfo);
	
	if(! S_ISDIR(fileinfo.st_mode))
	{
		printf("%s directory not existing\n",argv[1]);
		return -1;
	}
	
	
	dirp = opendir(argv[1]);
	
	if(dirp == NULL)
	{
		printf("Error to open %s directory\n",argv[1]);
		return -1;
	}
	
	printf("%s directory opened\n",argv[1]);
	//now file to get write data
	
	fd1 = open(argv[2], O_WRONLY |  O_APPEND);
	
	if(fd1 == -1)				//if given file not existing then we return from this if
	{
		printf("Error to open %s file\n",argv[2]);
		return -1;
	}
	
	printf("%s file opened\n",argv[2]);
	//taking entries of directory
	
	//to check files list
	/*
	while(	(dp = readdir(dirp)) != NULL)
	{
		if( strcmp(dp->d_name, "..") == 0 || strcmp(dp->d_name, ".") == 0)	
		{	
			continue;
		}
		
		printf("%s\n",dp->d_name);
	}*/
	
	
	//open each file and read data and display
	while(	(dp = readdir(dirp)) != NULL)
	{
		stat(dp->d_name, &fileinfo);
		
		//if we get ./../DIR type file then skill next part and continue ahead
		if( strcmp(dp->d_name, "..") == 0 || strcmp(dp->d_name, ".") == 0 || (!S_ISDIR(fileinfo.st_mode)))	
		{	
			continue;
		}
		
		//when size is greather than 1byte
		if(fileinfo.st_size > 0)
		{
			temp = (char*)malloc(sizeof(char)* (sizeof(dp->d_name)+sizeof(argv[1])));
			
			sprintf(temp,"%s%s",argv[1], dp->d_name); //write on heap
			
			fd2 = open(temp, O_RDONLY);
			
			if(fd2 == -1)
			{
				printf("Error to open %s file\n",dp->d_name);
				continue;
			}
			
			printf("File opened successfull: %s\n",temp);
			
			//read data from file
			ret1 = read(fd2, buff, sizeof(buff));
			
			if(ret1 == -1)
			{
				printf("Error to read data\n");
				continue;
			}
			
			char newln = '\n';
			
			//write data to file
			ret1 = write(fd1, buff, ret1);
			write(fd1, &newln,1);
			
			if(ret1 == -1)
			{
				printf("Error to write data\n");
				continue;
			}	
			
			printf("data read and write successfully\n");
			
			free(temp);
			close(fd2);
			icnt++;
		}
	}
	
	printf("Number of files data written  is : %d\n",icnt);
	
	return 0;	
}

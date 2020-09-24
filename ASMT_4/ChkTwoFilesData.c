/*
3. Write a program which accept two file names from user and check whether contents of
   that two files are equal are not.
	
	input: Demo1.txt	  ->>>>>>>>   Data of file
								 _______________________
						        |						|
								|Marvellous			    |  10 chars   
								|						|
								|_______________________|
								Demo1.txt

	
	
	input: Demo1.txt	  ->>>>>>>>   Data of file
								 _______________________
						        |						|
								|Marvellous			    |  10 chars   
								|						|
								|_______________________|
								Demo2.txt
	output: Both are same
	
*/

#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>


#define MAXSIZE  128


int main(int argc, char *argv[])
{

	int fd1, fd2, ret1, ret2, i ;
	char buff1[MAXSIZE] = {'\0'};
	char buff2[MAXSIZE] = {'\0'};
	
	fd1 = fd2 = ret1 = ret2 = i = 0;
	
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	fd1 = open(argv[1], O_RDONLY);
	
	
	if(fd1 == -1)
	{
			printf("error to open first file\n");
			close(fd1);
			return -1;
	}
	
	fd2 = open(argv[2], O_RDONLY);
	
	
	if(fd2 == -1)
	{
			printf("error to open second file\n");
			close(fd2);
			return -1;
	}


	while( (ret1 = read(fd1, buff1, MAXSIZE)) > 0  &&
		   (ret2 = read(fd2, buff2, MAXSIZE)) > 0  )
	{	
		if(ret1 == ret2)
		{	
			i = 0;
			while( i < ret1)
			{
				if(buff1[i] != buff2[i])
				{
					break;	
				}	
				i++;
			}		
			
			if(ret1 != i)
			{
				break; 
			}
			
		}
		else
		{
			break; 
		}
	} //end of outer loop	
	
	if(i == ret2)
	{
		printf("Both are same\n");
	}
	else
	{
		printf("Both are not same\n");
	}
	
	close(fd1);
	close(fd2);

	return 0;	
}

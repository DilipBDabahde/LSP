/*
7. Write a program which is used to pring home directory and login user name.

input: $gcc mydemo.c -o myexe
	   $./myexe HOME  LOGNAME

output:
		HOME=/home/Shani
		
		LOGNAME=shani
	
*/	

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/resource.h>

extern char **environ; //this pointer help to print envirnment list of our application

int main(int argc, char *argv[])
{	
	char **list = environ;
	int j =0 , k = 1,icnt = 0;
	char arr[256] = {'\0'};
	

	
	for(int i = 0; list[i] != NULL; i++)
	{
		j = 0;
			
		while(*list[i] != '=')
		{
			arr[j] = *list[i];
			list[i]++;
			j++;
		}
		
		
		for(j = 1; j < argc; j++)   
		{
			if(strcmp(arr, argv[j]) == 0)
			{
				printf("%s%s\n",arr, list[i]);
			}
		}
		
		memset(arr, 0 , sizeof(arr));
	}
			
	return 0;
}

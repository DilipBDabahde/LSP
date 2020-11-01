/*
	strsignal this functioon is use to display signal info
	
	we can accept one to 64 signals in this application
*/

#define _GNU_SOURCE
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main()
{
	char *ptr = NULL;
	
	for(int i = 1; i <=64; i++)
	{
		ptr = strsignal(i);
		
		if(ptr == NULL)
		{
			perror("strsignal");
			exit(-1);
		}
	
		printf("Signal Num:  %d  : %s\n",i, ptr);
	}	
	
	return 0;
}

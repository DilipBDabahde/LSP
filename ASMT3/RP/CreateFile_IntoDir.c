/*

	accept dirname/path  as well as filename from user and create file into given directory name

*/


#include<stdio.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	char *p = NULL;
	int ret;
	
	p = strcat(argv[1],argv[2]);
	
	ret = creat(p, 0777);
	
	if(ret == -1)	
	{
		printf("Error to create file into targeted dir\n");
		return ret;
	}
	
	printf("%s file created into %s directory \n",argv[2],argv[1]);
	
	
	
	return 0;
}

#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{
	char buff[128];
	char *ptr = NULL;
	
	
	ptr = realpath(argv[1], buff);
	
	if(ptr == NULL)
	{
		printf("Error to get realpath\n");
		return -1;
	}
	
	printf("real path is  %s\n",ptr);

	return 0;
}

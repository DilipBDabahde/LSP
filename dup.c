

/*
wap to dup fd
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>


int main()
{
	
	int fdx = dup(1);
	
	if(fdx  == -1)
	{
		printf("Error to dup\n");
		return -1;
	}
	
	//fdx is gets duplicate copy of fd 1 
	printf("fdx = %d\n",fdx);
	write(fdx, "Hello World", strlen("Hello World"));

	return 0;
}

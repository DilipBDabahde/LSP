

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{	

	if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)	
	{
		printf("Can not seek\n");
	}
	else
	{
		printf("Seek ok");
	}


	
	return 0;
}

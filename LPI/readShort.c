

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define MAX_READ 20

char buff[MAX_READ];

int main(int argc, char const *argv[])
{

	if(  read(0, buff, MAX_READ)  == -1)
	{
		printf("Unable to read \n");
	}
	printf("\nRead data is:->  %s\n",buff);

	return 0;
}
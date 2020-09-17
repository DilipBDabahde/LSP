

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define MAX_READ 20

char buff[MAX_READ];
char arr[] = "Enter data: ";

int main(int argc, char const *argv[])
{

	if(write(1,arr,sizeof(arr)) == -1)
	{
		printf("Unable to write\n");
	}

	if(  read(0, buff, MAX_READ)  == -1)
	{
		printf("Unable to read \n");
	}
	printf("\nRead data is:->  %s\n",buff);

	return 0;
}
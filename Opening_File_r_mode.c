

//open file

#include<stdio.h>


int main()
{
	
	FILE *fd;
	
	fd =fopen("Demo.txt", "r"); //Demo.txt file should be existing file  to open else error
	
	
	if(fd == NULL)
	{
		printf("Unable to open file\n");
	}
	
	printf("File open sucessfully\n");
	
	fclose(fd); //closing file
	
	printf("Closing all open file\n");
	
	return 0;
}

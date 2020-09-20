/*
accept file name from user and display file size using stat funcion
input : filename
output: Size
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>


int main(int argc, char *argv[])
{

	struct stat sb;		//obj creatd
	int ret;			//to hold return value of stat fun
	
	if(argc != 2)
	{	
		fprintf(stderr, "Usage : %s <filename>\n",argv[0]); //stderr is terminal
		return -1;
	}
	
	ret = stat(argv[1], &sb);
	
	if(ret) // ret == 0 stat works but if does not execute
	{
		perror("Stat\n");
		return -1;
	}
	
	printf("%s is %ld\n",argv[1], sb.st_size);
	
	return 0;
}

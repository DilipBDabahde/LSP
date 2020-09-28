/*
	accept file path and truncate file with given file
	
	if filesize is greater than lenth then from given length point onward data truncated or lost
	but
	if length is greater than filesize in that case till then after filesize length finish on that size null bytes get added or hole also known as padding
	
	file.c
	ABCDEFGHIJ  filesize =  10      length = 2
	
	output : CDEFGHIJ    this data will be trancated 8 bytes
	-------------------------------------------------------------------------	
	But filesize is less and length is more then null bytes addes or hole
	-------------------------------------------------------------------------
	file.c 
	ABCDEFGHIJ   filesize = 10   length = 20	WE REQUEST TO TRUNCATE FROM 20 ONWORD which is not file length to do
	
	output:
			ABCDEFGHIJ----------  10 filesize + 10 nullbytes
	
	
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>	

int main(int argc, char *argv[])
{

	int fd, ret;
	
	
	if(argc != 3)
	{
		printf("incorrect argument\n");
		return -1;
	}
	
	
	ret = truncate(argv[1], atoi(argv[2]));
	
	if(ret == -1)
	{
		printf("Error to truncate file\n");
		return -1;
	}
	
	printf("file truncated with given length\n");
	
	return 0;

}


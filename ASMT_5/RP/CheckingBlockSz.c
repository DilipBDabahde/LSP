/*
accept file name from user and read its its data and display 

ChuckSize 					
Iteration to read file	
Blocksize 
num of block used 

आपल्या program मध्ये blocksize  ४०९६ आहे . तर आपल्याला एक chunk  बनवून आपल्याला file  चा data  read  करायचा आहे . read  करत असताना तो read  साठी किती iteration  करतो ते check करून दाखवू . 
उदा . फाइल्स नाव : abc.c    
 chunksize ५१२  
sizeof  file  ४०९७    <------------- दोन blocks  allocate  झाले  ४०९६*२

पहिला Blcok  read  केले त्याला ८ वेळा iteration  केला . ४०९६/५१४ = ८  iteration  झाली 
पण आपल्या file  ची size  ४०९७ होती तर ४०९६ read  केल्या पहिल्या block  मधून उरलेला १ byte  हा दुसरय्या block  मध्ये होता. 
तो read  करण्या साठी दुसरा block  access  केले व १ byte  read  केले व नंतर read call  मधून return  zero  भेटला 
त्या नंतर 
display  केले total chunk  size 
व iteration  अँड file  size . 

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define MAXSIZE 512

int main(int argc, char *argv[])
{
	int fd, ret;
	char buff[MAXSIZE];
	int icnt = 0;
	long size = 0;
	
	if(argc != 2)	
	{
		printf("Insufficient argumts\n");
		return -1;
	}
	
	
	fd = open(argv[1], O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error : to open file %s\n",argv[1]);
		close(fd);
		return -1;
	}
	
	while( (ret = read(fd, buff, MAXSIZE)) != 0)  //read until EOF
	{
		if(ret == -1)
		{
			printf("Error : read to file\n");
			return -1;
		}
		icnt++;
		size +=ret;
	}	
	
	
	printf("\nfilesize size : %ld\n",size);
	printf("Block size: 4096\n");
	printf("Chuck Size : %d\n",MAXSIZE);
	printf("iteration %d\n",icnt);

	
	if(size > 4096)
	{
		if(size % 4096 == 0)
		{
			printf("used blocks : %ld\n",(size/4096));
		}
		else
		{
			printf("used blocks : %ld\n",(size/4096)+1);
		}
	}
	else
	{
		printf("used block : 1\n");
	}
	close(fd);
	
	
	return 0;
}

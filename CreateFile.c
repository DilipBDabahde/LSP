/*
accept file name from user &
write program to create file using create function and R_WRONLY  file opening mode

$ gcc filename data.txt    

data.txt file will be created using create fucntion in current directory 

once file is created in current dir than by using close(int) fucntion we have to close the file

skip below contents
ls
ls           lscpu        lsipc        lsmod        lspcmcia     
lsattr       lsdiff       lslocks      lsns         lspgpot      
lsblk        lshw         lslogins     lsof         lsusb        
lsb_release  lsinitramfs  lsmem        lspci    
*/


#include<stdio.h> //to perform input output operation
#include<fcntl.h>  // to creat("filename", fileOpeningMode) function 
#include<unistd.h>  // to close(int)  function

int main(int argc, char *argv[])
{
	int fd = -1;
									//S_IRWXU  User can  R W X
	fd = creat( argv[1], S_IRWXU); //here file is created 
	
	if(fd == -1)	
	{
		printf("not able to create file\n");
		return -1;
	}
	else
	{
		printf("File is created successfully\n");
	}
	printf("%d\n",fd);	// fd value
	
	fd  = close(fd);	//close file by providing fd
	
	printf("%d\n",fd);  // if fd = 0 then file close sucessfully either it return -1 as error
	


	return 0;
}

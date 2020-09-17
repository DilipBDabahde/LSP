#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>


int  main(int argc, char const *argv[])
{
	int fd4, fd2, fd3, fd1, fd5, status;


	fd1  = open(argv[1], O_RDWR);

	if(fd1 == -1)
	{
		printf("Error : Unabel to open file fd1\n");
		close(fd1);
		return -1;
	}

	printf("Fd1 Opend successfulyy fd is : %d\n",fd1);

	fd2  = open(argv[1], O_RDWR);

	if(fd2 == -1)
	{
		printf("Error : Unabel to open file fd2\n");
		close(fd2);
		return -1;
	}
	printf("Fd2 Opend successfulyy fd is : %d\n",fd2);


	//here we close fd of fd1  to make reuse and we can't close same fd 2times if it tries then it returns -1 for 2nd time
	
	status = close(fd1); //closing fd 3
	printf("After closing fd1 status is %d\n",status);


	fd3  = open(argv[1], O_RDWR);

	if(fd3 == -1)
	{
		printf("Error : Unabel to open file fd3\n");
		close(fd3);
		return -1;
	}

	printf("Fd3 Opend successfulyy fd is : %d\n",fd3);



	fd4  = open(argv[1], O_RDWR);

	if(fd4 == -1)
	{
		printf("Error : Unabel to open file fd4\n");
		close(fd4);
		return -1;
	}
	printf("Fd4 Opend successfulyy fd is : %d\n",fd4);

	return 0;
}

/*
	unnamed pipe
	in this application we create pipe in parent process then we create two child process
	
	parent process write data into created pipe 
	example:
			Write end	------------------------data in pipe---------------------Read End
						A		B		C		D		E		F		G		H				total 8 chars
	
	
	First siblig reads : ABCD		
	Second siblig reads: EFGH
	
	parent written pipe read by two child process one by one 		

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>


int main()
{
	int fds[2], ret;
	pid_t pid1, pid2;
	char buff[4] = {'\0'};
	
	if(pipe(fds) == -1)
	{
		perror("pipe");
		exit(-1);
	}
	
	pid1 = fork();
	pid2 = fork();
	
	if(pid1 == 0 && pid2 > 0)
	{

		close(fds[1]);		//close write end of pipe	
			
		ret = read(fds[0], buff, 4);
		printf("First child read data : %s\n",buff);
	
		close(fds[0]);		//close read end of pipe			
		exit(0);			//end of first child			
	}
	else if(pid2 == 0 && pid1 > 0)
	{

		close(fds[1]);		//close write end of pipe	
			
		ret = read(fds[0], buff, 4);
		printf("First child read data : %s\n",buff);
	
		close(fds[0]);		//close read end of pipe			
		exit(0);			//end of first child	
	}
	else
	{
		close(fds[0]);	//close write end of pipe		
		write(fds[1],"ABCDEFGH", strlen("ABCDEFGH"));		
		close(fds[1]);	//close read end of pipe
		wait(NULL);
	}

	printf("Terminating parent process\n");
	
	exit(0);

}

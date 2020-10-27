//demonstaration of signle usage in 


//include req header files which contins prototype

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

//function prototype which are gonna define bellow

void sighup();
void sigint();
void sigquit();

int main()  //definition
{
	
	int pid;
	
	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	
	if(pid == 0)  //child process area
	{
		//child calling another fucntions
		//syscallname(signame/num, fun_name);
		signal(SIGHUP, sighup);
		signal(SIGINT, sigint);
		signal(SIGQUIT, sigquit);
		for(;;);	
	}
	else  //parent process area
	{
		printf("\nParent : sending SIGHUP\n\n");
		kill(pid, SIGHUP);
		sleep(3);
		
		printf("\nParent : sending SIGINT\n\n");
		kill(pid, SIGINT);
		sleep(3);
		
		printf("\nParent ; sending SIGQUIT\n");
		kill(pid, SIGQUIT);
		sleep(3);	
	}	
}



void sighup()
{
	signal(SIGHUP, sighup);
	printf("Child : I have recieved a SIGHUP\n");
}


void sigint()
{	
	signal(SIGINT, sigint);
	printf("Child : I have received a SIGINT\n");
}

void sigquit()
{
	signal(SIGQUIT, sigquit);
	printf("Child : I have received a SIGQUIT\n");
	exit(0);
}

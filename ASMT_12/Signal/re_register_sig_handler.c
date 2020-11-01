/*
	in this application we register our signal handler in application it wourld be like register in single statment
	
	
	raise function is used to send signal to itself and then in size main 
	register handle gets used then process execution suspend now handler executte and re-register signal for this process
	handler execution, process again start execution from where it caught signal
*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int Number)
{
	printf("SIGQUIT caught\n");	
	signal(Number, sig_handler); 	//re-register signal
}

int main()
{
	
	printf("insize main\n");
	
	if(signal(SIGQUIT, SIG_IGN) != SIG_IGN)
	{
		if(signal(SIGQUIT, sig_handler) == SIG_ERR)
		{
			printf("failed to handle signal\n");
		}
	}
	
	
	kill(getpid(), SIGQUIT);
	
	
	return 0;
}

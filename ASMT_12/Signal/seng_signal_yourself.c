/*
	sending signal to your self
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
	
	
	//kill(getpid(), SIGQUIT);
	raise(SIGQUIT);		//sending signal to itself
	
	return 0;
}

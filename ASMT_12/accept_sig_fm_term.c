/*
3. Write a program which creates such a process which accept signals from the terminal.

when our program runs at then time we get pid of our process and program run in loop
from second tab of terminal we pass single to our process
 
  syscall/cmd	signame  	PID
$ kill 			-SIGTERM 	31775

*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>


void sig_int()
{
	printf("sigint caught\n");
	exit(0);
}

void sig_quit()
{
	printf("sigquit caught\n");
	exit(0);
}

int main()
{
	printf("our process id : %d\n",getpid());
	signal(SIGINT, sig_int);
	signal(SIGQUIT, sig_quit);
	
	while(1);
	
	exit(0);
}

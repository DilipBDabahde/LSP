/*
5. Write a program which creates two process as sender and receiver in which sender process
   send signal to receiver process.

   Receiver_Process
   
   this is sender process in this process we create one child process from that child process space we exec receiver 
   process and receiver process runs in loop then after some time slice from sender process signal pass to receiver 
   process and receiver process display signal msg and exit from receiver process and back to sender process
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


void sig_hup(int sig)
{
	printf("receiver caught sighup : %d\n",sig);
	exit(0);
}

void sig_int(int sig)
{
	printf("receiver caught sigint : %d\n",sig);
	exit(0);
}

void sig_quit(int sig)
{
	printf("receiver caught sigquit : %d\n",sig);
	exit(0);
}


int main()
{
	printf("child pid : %d\n",getpid());
	printf("inside reciever main\n");
	signal(SIGINT, sig_int);
	signal(SIGHUP, sig_hup);
	signal(SIGQUIT, sig_quit);
	while(1);
	
	exit(0);
}

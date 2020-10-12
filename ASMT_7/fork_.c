/*
	program to demonstrate use of fork() system call and creation of child new process

We love hocky
Before fork
current process contents
parent process pid: 16353
current process pid: 16354
inside child : 12
inside child : 22
parent process contents
parent process (terminal):9816
current proccess id(program exe):16353
inside parent : 11
inside parent : 21

or

We love hocky
Before fork
parent process contents
parent process (terminal):9816
current proccess id(program exe):16192
inside parent : 11
inside parent : 21
current process contents
parent process pid: 16192
current process pid: 16193
inside child : 12
inside child : 22

*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int out = 11;
char buff[] = "We love hocky\n";

int main()
{
	int val_gid;
	int ret;
	
	ret = write(1, buff, sizeof(buff)-1);

	if(ret == -1)
	{
		printf("Error to write\n");
	}
	
	ret = 21;
	
	
	printf("Before fork\n");
	
	val_gid  = fork();  //call to create new process
	
	if(val_gid == 0)		//child process change value of vars but doen not affect to parent process
	{
		sleep(5);
		printf("current process contents\n");
		printf("fork() parent process pid(program exe): %d\n",getppid()); //running program pid
		printf("fork() current process pid: %d\n",getpid());  //fork creation
		out++;
		ret++;
		printf("inside child : %d\n",out);
		printf("inside child : %d\n",ret);
	}
	else
	{
		sleep(5);
		printf("parent process contents\n");
		printf("parent process (terminal):%d\n",getppid());
		printf("current proccess id(program exe):%d\n",getpid());
		printf("inside parent : %d\n",out);
		printf("inside parent : %d\n",ret);
	}
	

	exit(0);
}

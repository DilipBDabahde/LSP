/*
	demonstration of parent child data segment sharing after fork
*/

#include<stdio.h>
#include<unistd.h>


//global and static vars stores into data segment of process 

int i = 11;			//Non-BSS 
static int j = 21;	//Non-BSS  block started with value
int y; 				//BSS   block started with symbol

int main()
{
	pid_t pid;
	static int x =10;  //Non-BSS 	
	pid = fork();  //child process creation call
	
	if(pid == 0)  //child process runs in block
	{
		printf("\nchild process copy for data section\n");
		printf("i : %d\n",++i);
		printf("j : %d\n",j);
		printf("x : %d\n",x);
		printf("parent pid : %d\n",getpid());		
	}
	else	//parent process runs 
	{
		printf("\nparent process copy for data section\n");
		printf("i : %d\n",i);
		printf("j : %d\n",++j);	
		printf("x : %d\n",++x);	
		printf("parent pid : %d\n",getpid());		
	}
	
	printf("Hello work\n");

	return 0;
}

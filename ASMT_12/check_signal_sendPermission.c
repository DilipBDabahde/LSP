/*
	from this application we send signal but we check our process has permission to send signal to perticular process
	id
	
*/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

int main()
{
	int ppid = getppid(),   pid = getpid();
	
	printf("parent pid is: %d\n",ppid);

	int ret = kill(ppid, 0);  //can't use pid 1
	
	if(ret)
	{
		printf("child doen not have signal sending permisiion\n");
	}
	else
	{
		printf("child is able to send signal\n");
	}

	return 0;
}

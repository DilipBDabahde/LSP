/*
	vfork function works like fork but in this vfork function child first run then parent
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int out = 11;  //global var gets store into data semgemnt in nbss bcs its initiated

int main(int argc, char *argv[])
{
	int var;
	int result;
	var = 21;
	
	printf("Before vfork call\n");
	
		
	result = vfork();
	
	if(result == 0)
	{
		printf("vfork created pid : %d\n",getpid());
		printf("vfork parent pid : %d\n",getppid());
		printf("return value of vfork to our process is : %d\n\n",result);
		var++;
		out++;
	}
	else
	{
		printf("our exe running pid :: %d\n",getpid()); // program exe running pid
		printf("parent of exe running : %d\n",getppid());
		printf("fork created process id: %d\n\n",result);	
		exit(0);
	}
	
	printf("\nValue of : out  : %d\nValue of : var : %d\nprocess id :%d\n",out, var,getpid());
	exit(0);

	return 0;
}

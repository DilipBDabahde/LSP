/*
	demonstration of copying heap section of parent to child
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>	

int main()
{
	pid_t pid;
	
	int *ptr = malloc(sizeof(int)); //Head section memory allocation
		
	*ptr = 11;	//allocated memory initialization
	
	
	pid  = fork();  //process creation
	
	if(pid == 0)  //child runs
	{
		++(*ptr);	// changing child heap copy
		printf("heap value: %d\n",*ptr);
		printf("child pid: %d\n",getpid());
		free(ptr);
		printf("heap value after free : %d\n\n",*ptr);
	}
	else  //parent runs
	{
		printf("heap value : %d\n",*ptr);  //no change with parent heap copy
		printf("parent pid: %d\n",getpid());	
		free(ptr);
		printf("heap value after free : %d\n\n",*ptr);
	}
	
	return 0;
}

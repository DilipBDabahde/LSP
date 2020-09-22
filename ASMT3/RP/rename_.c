/*
rename file
*/

#include<stdio.h>
#include<unistd.h>

int main()
{

	int ret = 0;
	
	ret = rename("./src/makefile", "./dst");
	
	printf("%d\n",ret);	
	

	return 0;

}

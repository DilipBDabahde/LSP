/*
accept two string from user and concate them
*/


#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char *p = NULL;
	
	p = strcat(argv[1], argv[2]);
	
	printf("%s\n",p);
	
	return 0;
}

/*
echo demo
in this program we add logic to work like echo cmd
compile this file : gcc myecho.c -o myEcho
run		  : ./myEcho  This is my World

output: on console is : This is my world
*/

#include<stdio.h>

int main(int argc, char *argv[])
{
	for(int i = 1; i < argc; i++)
	{
		printf("%s ",argv[i]);
	}
	
	printf("\n");
	return 0;
}

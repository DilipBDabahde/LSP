/*
2. Write a program which accept name from command line argument and display it on
screen.
input: Marvellous

output: Marvellous

*/


#include<stdio.h>


int main(int argc, char *argv[])
{
	printf("Given name is: %s\n",argv[1]);

	return 0;
}
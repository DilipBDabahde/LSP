/*
1. Write a program which is used to demonstrate concept of I/O redirection.


$ gcc Demo.c -o myexe
$ myexe  < input.txt  >  output.txt 


*/

#include<stdio.h>

int main(int argc, char *argv[])
{

	int no1, no2;
	
	scanf("%d%d",&no1, &no2);
	
	printf("Addition of %d + %d is = %d\n", no1, no2, (no1+no2));
	
	
	return 0;
}

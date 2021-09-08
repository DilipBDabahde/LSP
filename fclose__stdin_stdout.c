/*
write a program to close default streams using fclose
*/


#include<stdio.h>


int main()
{
	
	printf("Hello World\n");
	int i;
	scanf("%d",&i);
	
	fclose(stdin);
	fclose(stdout);
	
	printf("Hello world\n");
	scanf("%d",&i);	


	return 0;
}

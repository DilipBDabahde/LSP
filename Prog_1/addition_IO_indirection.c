	/*
	Write a program which is used to add two numbers.

	to perform addition of two numbers create one file 
	as input.txt by using touch cmd
	$ touch input.txt & echo 11 22 > input.txt

	so 11 and 22 will be passed to input.txt

	pass this input file to program file as input

	output: 33
	*/

	#include<stdio.h>

	//helper fucntion to perform addtion
	int add(int x, int y)
	{
		int iresult = 0;

		iresult = x + y;

		return iresult;
	}

	int main()
	{
		
		int ival1 = 0;
		int ival2 = 0;

		scanf("%d %d", &ival1, &ival2);

		int res = add(ival1, ival2);

		printf("Addition of %d %d is %d\n",ival1, ival2, (ival1 + ival2));

		return 0;
	}
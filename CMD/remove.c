/*
write a program to delete file using remove function

*/

#include<stdio.h>

int main()
{
	int res = 0;
	
	char fname [] = "DEMO.txt";
	char dirname[] = "Demo";
	
	res = remove(fname);
	
	if(res == 0)
	{
		printf("%s file is deleted\n",fname);	
	}
	else
	{
		printf("%s file is not deleted\n",fname);
		return -1;
	}
	
	res = remove(dirname);
	if(res == 0)
	{
		printf("%s dir is deleted\n",dirname);
	}
	else
	{
		printf("%s dir is not deleted\n",dirname);
		return -1;
	}
		
	return 0;
}

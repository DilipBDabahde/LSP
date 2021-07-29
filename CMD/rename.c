/*
write a program to rename file

input:
	oldname.txt   newname.txt

oldname file renamed by newname
*/


#include<stdio.h>
#include<string.h>

int main()
{
	
	char *oldName = "Demo.txt", *newName = "DEMO.txt";
	char *olddir = "Demo", *newdir = "DEMO";
	int res = 0;
	
	res = rename(oldName, newName);
	
	if(res == 0)
	{
		printf("rename file is: %s\n",newName);
	}
	else
	{
		printf("Error to rename file\n");
	}
	
	
	res = rename(olddir, newdir);
	
	if(res == 0)
	{
		printf("rename dir is: %s\n",newdir);
	}
	else
	{
		printf("Error to rename dir\n");
	}
	
	
	return 0;	
}

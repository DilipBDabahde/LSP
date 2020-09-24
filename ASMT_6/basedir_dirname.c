/*
/home/dilip/Programs/Java/demo.java

dirname() return -> /home/dilip/Programs/Java
basename() return   -> demo.java


*/

#include<stdio.h>
#include<libgen.h>

int main(int argc, char *argv[])
{
	char *dname = NULL;	 // to point dirname
	char *bname = NULL;  //to point basename

	dname = dirname(argv[1]);
	
	if(dname == NULL)
	{
		printf("error to get dirname\n");
	}
	else
	{
		printf("dirname is : %s\n",dname);
	}
	
	bname = basename(argv[1]);
	
	if(bname == NULL)
	{
		printf("error to get basename\n");
	}
	else
	{
		printf("basename is : %s\n",bname);
	}
	
	
	return 0;
}

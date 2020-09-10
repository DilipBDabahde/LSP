#include <stdio.h>
#include<string.h>

struct demo
{
	int i;
	char arr[6];
};

int main(int argc, char const *argv[])
{
	FILE *fp = NULL;
	int ret;

	struct demo obj1, obj2;


	obj1.i = 11;
	strcpy(obj1.arr, "Hello");

	//openn file
	fp = fopen("Demo.txt", "wb"); //write block

	if(fp == NULL)	
	{
		printf("Unable to open file\n");
	}

	//this below call is used to writeblock
	ret = fwrite(&obj1, sizeof(obj1),1, fp);
	

	if(ret != 1)	
	{
		printf("Error while writing");
		return -1;
	}

	fclose(fp);

	//open the file
	fp = fopen("Demo.txt", "rb");

	if(fp == NULL)
	{
		printf("Unable to open file\n");
	}

	fread(&obj2, sizeof(obj2), 1, fp);

	printf("%d %s\n", obj2.i, obj2.arr);

	return 0;
}
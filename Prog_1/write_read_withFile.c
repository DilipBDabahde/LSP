//accept data from user as
//user id
//user name
//user salary
//user address
//write all data into file
//after written data display it on console

#include<stdio.h>

int main()
{
	int id = 0;
	char name[30];
	float salary = 0;
	char address[50];

	FILE *fptr = NULL;
	int len = 0;
	char buff[255];

	fptr = fopen("Empinfo.txt", "w+");

	if(fptr == NULL)
	{
		printf("unable to open\n");
		return -1;
	}

	printf("Enter id: ");
	scanf("%d",&id);
	fprintf(fptr,"ID : %d\n",id);

	printf("Enter name: ");
	scanf("%s",name);
	fprintf(fptr,"Name : %s\n",name);

	printf("Enter salary: ");
	scanf("%f",&salary);
	fprintf(fptr, "Salary : %f\n",salary);

	printf("Enter Address:");
	scanf(" %[^'\n']s",address);
	fprintf(fptr, "Address: %s\n", address);


	fclose(fptr);

	fptr = fopen("Empinfo.txt", "r+");

	while(fscanf(fptr, "%s\n", buff) != EOF)
	{
		printf("%s ",buff);
	}

	fclose(fptr);

	return 0;
}
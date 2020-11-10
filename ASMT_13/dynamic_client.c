

#include "dynamic_header.h"

int main()
{
		
	
	int arr[] = {11, 61, 41, 1, 91, 51, 111}, iVal = 41;
	
	BOOL Result = 0;
	
	Result = Search(arr,sizeof(arr)/sizeof(int), iVal);
	
	if(!Result)
	{
		printf("Element does not exists into array\n");
	}
	else
	{
		printf("Given element exists into array list\n");
	}

	//////////////////////////////////////////////////////////
	
	int iarr[] = {11, 7, 9, 2, 28}, i = 0;
	
	printf("before sort\n");
	
	for(i = 0; i < sizeof(iarr)/sizeof(int); i++)
	{
		printf("%d ",iarr[i]);
	}
	
	sort(iarr, sizeof(iarr)/sizeof(int));
	
	printf("\nafter sort\n");
	
	for(int i = 0; i < sizeof(iarr)/sizeof(int); i++)
	{
		printf("%d ",iarr[i]);
	}
	
	printf("\n");
	
	
	
	return 0;
}

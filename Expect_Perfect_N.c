/*
	accept one value from user and display that number of Prime number
	
	input:
			1
	output:
			6
	---------------
	
	input:
			2
	output:
			6	28
			
	perfect Number is such number where sum of its all divisible is equal to targeted Number
*/

#include<stdio.h>

typedef int BOOL;

#define True 1
#define False 0

////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Taking decision to return given number is perfect or not
BOOL ChkPefect(int iNo)
{
	int iSum = 0;
	
	for(int i = 1; i <= iNo/2; i++)
	{
		if(iNo % i == 0)
		{
			iSum = iSum + i;
		}
		
		if(iSum > iNo)
		{
			break;
		}
	}
	
	if(iSum == iNo)
	{
		return True;
	}
	else
	{
		return False;
	}	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

//this helper funtion pass one value to above funcition to get confirmation of perfect Number


void n_perfectDisplay(int Nval)
{
	int i = 1;
	
	
	while(i)
	{
		if(True == (ChkPefect(i)))
		{
			printf("%d\n",i);
			Nval--;
		}
		
		if(Nval == 0)
		{
			break;
		}
		
		i++;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	
	int ival = 0;
	
	printf("Enter a value: ");
	scanf("%d",&ival);
	
	n_perfectDisplay(ival);
	
	
	return 0;
}

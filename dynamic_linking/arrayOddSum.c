//this function accept array and return sum of Odd elements


int arrayOddSum(int iarr[], int isize)
{
	int iSum = 0;
	
	for(int i = 0; i < isize; i++)
	{
		if(iarr[i] % 2 != 0)
		{
			iSum += iarr[i];
		}
	}
	
	return iSum;
}

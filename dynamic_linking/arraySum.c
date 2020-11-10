//this function accept array and return sum of all elements


int arraySum(int iarr[], int isize)
{
	int iSum = 0;
	
	for(int i = 0; i < isize; i++)
	{
		iSum += iarr[i];		
	}
	
	return iSum;	
}

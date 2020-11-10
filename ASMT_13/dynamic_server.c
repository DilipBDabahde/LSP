
void sort(int iarr[], int isize)
{
	int i =0, j = 0, itemp = 0;
	
	for(i = 0;i < isize; i++)
	{		
		for(j = i + 1; j < isize; j++)
		{	
			if(iarr[i] > iarr[j])
			{
				itemp = iarr[j];				//swappig on address
				iarr[j] = iarr[i];
				iarr[i] = itemp;
			}
		}
	}
}


int Search(int iarr[], int isize,  int icmp)
{
	int i= 0;
	
	for(i = 0; i < isize; i++)	
	{
		if(iarr[i] == icmp)
		{
			break;
		}
	}
	
	if(i == isize)
	{
		return 0;
	}
	else
	{
		return 1;
	}	
}

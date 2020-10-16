#include<stdio.h>


int fun(int i, int j)
{
	return i+j;
}

int main()
{
	
	int (*ptr)(int, int);  //prototype to which we call
	
	printf("fun address : %p\n",fun);  //fun name itself contains it's address
	
	ptr = fun;   //address assign to ptr
	
	printf("ptr show address : %p\n",ptr);
	
	
	
	//now we use ptr to call function
	
	int no1 = 10;
	int no2 = 20;
	
	int result = ptr(no1, no2);   //function pointer usage to call function	
	
	printf("addition is : %d\n",result);
	
	return 0;
}

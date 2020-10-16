#include<stdio.h>


void fun(int i, int j)
{
	printf("Addition is :%d\n",i+j);
}

int main()
{
	
	void (*ptr)(int, int);  //prototype to which we call
	
	printf("fun address : %p\n",fun);  //fun name itself contains it's address
	
	ptr = fun;   //address assign to ptr
	
	printf("ptr show address : %p\n",ptr);
	
	
	
	//now we use ptr to call function
	
	int no1 = 10;
	int no2 = 20;
	
	ptr(no1, no2);   //function pointer usage to call function	
	
	return 0;
}

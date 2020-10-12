


#include<stdio.h>
#include<setjmp.h>
#include<stdlib.h>

//function prototype

static void f1(int,int,int,int);
static void f2(void);

static jmp_buf jmpbuffer;
static int globval;


int main()	/// 0
{
	int			 autoval;
	register int regval;
	volatile int volval;
	static int   statval;
	
	globval = 1;
	autoval = 2;
	regval  = 3;
	volval  = 4;
	statval = 5;
	
	//all vars initialized
	
	if(setjmp(jmpbuffer) != 0)
	{
		printf("After long jump\n");
		printf("from if: globval : %d\nautoval: %d\nregval : %d\nvolval : %d\nstatval: %d\n",globval, autoval, regval,volval, statval);
		printf("\n");
		exit(0);
	}
	
	globval = 111;
	autoval = 222;
	regval  = 333;
	volval  = 444;
	statval = 555;
	
	f1(autoval, regval, volval, statval); //cat to f1
	exit(0);

	return 0;
}

static void f1(int i, int j, int k, int l)  //1
{	
	printf("in f1()\n");
	printf("globval : %d\nautoval: %d\nRegval:%d\nvolva:%d\nstatval:%d\n",globval, i,j,k,l);
	printf("\n");
	f2();

}

static void f2(void)  //2
{
	longjmp(jmpbuffer, 1);
}

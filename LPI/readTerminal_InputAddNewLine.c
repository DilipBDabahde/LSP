
#include<unistd.h>

#define MAX_SIZE 1024
char arr[MAX_SIZE + 1];
ssize_t rn;

char err[] = "Error : Unable to read\n";

int main(int argc, char const *argv[])
{
	
	rn = read(0, arr, MAX_SIZE);

	if(rn == -1)
	{
		write(1, err, sizeof(err) );
		return -1;
	}

	arr[rn] = '\0';

	write(1, arr, sizeof(arr));

	return 0;
}
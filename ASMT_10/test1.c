/*
5. Write a program which creates two threads by using pthread API, where
one thread count number of capital characters from demo.txt file and other
threads count number of small characters from same file.

input:	
		demo.txt
				our data in file ->		Hello David			

output:
		2 Caps
		8 Smalls
		
*/

#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>

pthread_mutex_t lock;

char file[] = {"demo.txt"};
char buff[128] = {'\0'};

void *CapCount(void *ptr)
{
	
	pthread_mutex_lock(&lock);

	int fd, ret, icnt, i;
	
	fd = open(file,O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		close(fd);
		pthread_mutex_unlock(&lock);
		pthread_exit(-1);
	}
	
	icnt = 0;
	while((ret = read(fd, buff, sizeof(buff)))!= 0)
	{
		i = 0;
		while(i < ret)	
		{
			if(buff[i] >='A' && buff[i] <= 'Z')
			{
				icnt++;
			}
			i++;
		}
	}
	
	memset(buff, 0, sizeof(buff));
	
	close(fd);
	
	printf("Total Capital chars found :%d\n",icnt);	
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}

void *SmallCount(void *ptr	)
{
	pthread_mutex_lock(&lock);

	int fd, ret, icnt, i;
	
	fd = open(file,O_RDONLY);
	
	if(fd == -1)
	{
		printf("Error to open file\n");
		close(fd);
		pthread_mutex_unlock(&lock);
		pthread_exit(-1);
	}
	
	icnt = 0;
	while((ret = read(fd, buff, sizeof(buff)))!= 0)
	{
		i = 0;
		while(i < ret)	
		{
			if(buff[i] >='a' && buff[i] <= 'z')
			{
				icnt++;
			}
			i++;
		}
	}
	close(fd);
	printf("Total Small chars found :%d\n",icnt);	
	pthread_mutex_unlock(&lock);
		
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	int ret1, ret2, status1, status2;
	
	printf("Our filedata :  Hello David\n");
	
	ret1 = pthread_create(&t1, NULL, (void*)CapCount, NULL);
	ret2 = pthread_create(&t2, NULL, (void*)SmallCount, NULL);
	
	if(ret1 != 0)
	{
		printf("error to create thread\n");
		return -1;
	}
	
	if(ret2 != 0)
	{
		printf("error to create thread\n");
		return -1;
	}
	
	pthread_join(t1, &status1);
	pthread_join(t2, &status2);
	
	printf("status of t1 : %d\n",(int)status1);
	printf("status of t2 : %d\n",(int)status2);
	
	
	pthread_exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

int isprime(int n);

int main(int argc, char *argv[])
{
	long long start_ts;
	long long elapsed_time;
	struct timeval ts;
	
	int start = 0;
	int end = 0;
	
	if(argc > 1){
		start = atoi(argv[1]);
	}
	
	if (argc > 2){
		end = atoi(argv[2]);
	}
	
	gettimeofday(&ts, NULL);
	start_ts = ts.tv_sec; 
	
	int i;
	int count = 0;
	for(i = start; i < end; i++){
		if(isprime(i))
			count++;
	}
	
	gettimeofday(&ts, NULL);
	elapsed_time = ts.tv_sec - start_ts;
	printf("There are %d prime numbers between [%d, %d)\n",count,start, end);
	printf("------------------------------\n");
	printf("TIEMPO TOTAL, %lld segundos\n",elapsed_time);
	return 0;
}

int isprime(int n)
{
	int d=3;
	int prime=0;
	int limit=sqrt(n);
	
	if(n<2)
		prime=0;
	else if(n==2)
		prime=1;
	else if(n%2==0)
		prime=0;
	else
	{
		while(d<=limit && n%d)
			d+=2;
		prime=d>limit;
	}
	return(prime);
}
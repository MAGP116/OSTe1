#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <pthread.h>

#define NTHREADS 4

int isprime(int n);
void * primesearch(void * args);

int start = 0;
int end = 0;
int count = 0;

pthread_mutex_t lock;

int main(int argc, char *argv[])
{
	long long start_ts;
	long long elapsed_time;
	struct timeval ts;

	pthread_mutex_init(&lock,NULL);
	pthread_t tid[NTHREADS];
	int args[NTHREADS];
	
	if(argc > 1){
		start = atoi(argv[1]);
	}
	
	if (argc > 2){
		end = atoi(argv[2]);
	}
	
	gettimeofday(&ts, NULL);
	start_ts = ts.tv_sec; 
	
	int i;
	for(i = 0; i < NTHREADS; i++){
	
		args[i]=i;
		pthread_create(&tid[i],NULL,primesearch,&args[i]);
	}
	
	for(i=0; i < NTHREADS; i++)
		pthread_join(tid[i], NULL);
	
	gettimeofday(&ts, NULL);
	elapsed_time = ts.tv_sec - start_ts;
	
	printf("There are %d prime numbers between [%d, %d)\n",count,start, end);
	printf("------------------------------\n");
	printf("TIEMPO TOTAL, %lld segundos\n",elapsed_time);
	
	return 0;
}


void * primesearch(void * args){
	int nthread = *((int *)args);
	int i;
	int tcount = 0;
	for(i = start + nthread; i < end; i += NTHREADS){
		if(isprime(i))
			tcount++;
	}
	
	pthread_mutex_lock(&lock);
	count += tcount;
	pthread_mutex_unlock(&lock);
	return NULL;
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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
	int deep = 0;
	if(argc > 1){
		deep = atoi(argv[1]);
	}
	int i;
	for(i = 0; i <= deep; i++){
		//printf("%d,%d,%d\n",i, getpid(),getppid());
		printf("%d\n",i);
		if(fork()){
			wait(NULL);
			exit(0);
		}
	}
	
	return 0;
}
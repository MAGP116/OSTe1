#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
	int i;
	for(i = 0; i < 4; i++){
		if(!fork()){
			sleep(1);
			exit(0);
		}
	}
	sleep(10);
	return 0;
}
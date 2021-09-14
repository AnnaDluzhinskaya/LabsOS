#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int n=811;

int main(){
	int pid = fork();
	if (pid == 0){
		printf("Hello from child [%d]\n",(pid-n));
	}else{
		printf("Hello from parent [%d]\n",(pid-n));
	}
}

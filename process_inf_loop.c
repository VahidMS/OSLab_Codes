#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(){
	int i = 0;
	while(1){
		printf("index: %d\n", i++);
		sleep(2);
	}
}

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main(){
	while(1){
		int i;
		for(i=0; i < 10; i++)
			printf("How are you now?");
		sleep(1);
	}
}

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t pid1 = -1, pid2 = -1,  terminated_process_PID;
	int status;
	pid1 = fork();
	
	if(pid1 < 0)
		printf("fork error! (for first child)");
	else if(pid1 == 0){
		printf("\nHello First Child PID:%d started, Parent PID: %d\n",getpid(), getppid());
	}
	else if(pid1 > 0){// This runs in parent
		pid2 = fork();
		if(pid2 < 0)
			printf("fork error! (for second child)");
	}
	if(pid2 == 0){
		printf("\nHello Second Child PID: %d started, Parent PID: %d\n", getpid(), getppid());
		printf("\nSecond child is Sleeping zzzzZZZZZ\n\n");
		sleep(10);
	}
	if (pid2 > 0 && pid1 > 0){ // This runs in parent
		printf("\nParent is waiting ...\n");
		//waitpid(-1, &wstatus, 0);
		//waitpid(pid1);
		//waitpid(pid2);
		//wait(pid2)
		int idx = 2;
		do{
			terminated_process_PID = wait();
			printf("Child Process with pid %d is finished.\n", terminated_process_PID);
			idx--;
		}while(idx > 0);
	}
	
	return 0;
}


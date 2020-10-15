#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
                                                                                     
int main()
{
	pid_t pid;
	pid = fork();
	if (pid < 0) 
	{
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) 
	{
//		execlp("/bin/ls", "ls", NULL);
		sleep(60);
		while(1);
	}
	else 
	{ 
		wait (NULL);
		printf ("Child Complete");
		exit(0);
	}
}

#define _GNU_SOURCE         
#include <sched.h>

#include<stdio.h>
#include<unistd.h>
int main(){
	pid_t pillow, killow, pid;
	int i;

	pillow = fork();

	if (pillow == 0) {
		pillow = getpid();
		execlp("/home/mayabee/Documents/1812176135/Pillow", "Pillow", NULL); 
			


	} else {
	    killow = fork();

		if (killow == 0) {

			killow = getpid();	
			execlp("/home/mayabee/Documents/1812176135/Killow", "Killow", NULL); 
	    } 
		else {
			pid = getpid();
			for(i = 0; i < 1; i--)
			{
				printf("Process-%u, parent of Pillow-%u and Killow-%u, running at CPU-%u.\n", pid, pillow, killow, sched_getcpu());
				// wait(NULL);
				sleep(1);
			}	
	    }
	}
	return 0;

}

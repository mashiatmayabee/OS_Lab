
#define _GNU_SOURCE         
#include <sched.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid;
	int i;
	for(i = 0; i < 1; i--){
		pid = getpid();
		printf("I am child-%u running at CPU-%u.\n",pid, sched_getcpu());
		sleep(1);
	}
	return 0;
}
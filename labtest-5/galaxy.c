#define _GNU_SOURCE
#include<pthread.h>
#include<syscall.h>
#include<stdio.h>
#include<unistd.h>
int main(){

    pid_t pid1, pid2;
    int i;

    pid1 = fork();

    if (pid1 == 0) {
        for(i=0;i<100;i++){
            execlp("./nebula", "Nebula", NULL);
        }
    } else {
        pid2 = fork();

        if (pid2 == 0) {
            for(i=0;i<100;i++){
                execlp("./blackhole", "Blackhole", NULL);
            }
        } else {
            
                printf("This is Galaxy, pid = %u, tid = %ld, cpu = %u\n", getpid(),syscall(SYS_gettid) ,sched_getcpu());
            
        }
    }
    return 0;
}
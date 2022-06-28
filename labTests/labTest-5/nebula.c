#define _GNU_SOURCE

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<syscall.h>
#include<sched.h>
#include<sched.h>

void X(){
    int i;
    for ( i = 0; i < 10; i++)
    {
        printf("X Subthread of nebula pid= %u , tid= %ld, cpu = %u\n", getpid(), syscall(SYS_gettid),sched_getcpu());
    }
    
}
void Y(){
    int i;
    for ( i = 0; i < 10; i++)
    {
        printf("Y Subthread of nebula pid= %u , tid= %ld, cpu = %u\n", getpid(), syscall(SYS_gettid),sched_getcpu());
    }
    

}
int main(){

    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL, (void*)X, NULL);
    pthread_create(&tid2,NULL, (void*)Y, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("Main thread of Nebula - pid= %u, tid = %ld, cpu = %u\n", getpid(), syscall(SYS_gettid), sched_getcpu());

    return 0;
}
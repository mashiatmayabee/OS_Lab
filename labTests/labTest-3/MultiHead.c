#define _GNU_SOURCE
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sched.h>
#include<syscall.h>
#include<stdlib.h>

int result;
void *ittu(void * parm){
    int *param = (int *)parm;
    int a= param[0];
    int b= param[1];
    result= a+b;
    pid_t pid, tid;
    pid = getpid();
    tid = syscall(SYS_gettid);
    printf("Ittu- Process ID = %d, thread ID = %d, CPU = %d, Result = %d\n",pid,tid, sched_getcpu(), result);
}
void *bittu(void * parm){
    int *param = (int *)parm;
    int a= param[0];
    int b= param[1];
    result= a-b;
    pid_t pid, tid;
    pid = getpid();
    tid = syscall(SYS_gettid);
    printf("Bittu- Process ID = %d, thread ID = %d, CPU = %d, Reasult = %d\n",pid,tid, sched_getcpu(), result);

}

void *mittu(void * parm){
    int *param = (int *)parm;
    int a= param[0];
    int b= param[1];
    result= a*b;
    pid_t pid, tid;
    pid = getpid();
    tid = syscall(SYS_gettid);
    printf("Mittu-Process ID = %d, thread ID = %d, CPU = %d, Result = %d\n",pid,tid, sched_getcpu(), result);
   
}


int main(){
    int a, b;
    pthread_t ittu,bittu,mittu;
    pid_t pid, tid;
    int *param = (int *)malloc(2 * sizeof(int));
    // int p[2];
    param[0]=6;
    param[1]=4;
    pthread_create(&ittu,NULL,(void *) ittu, *param);
    pthread_create(&bittu,NULL,(void *)bittu, *param);
    pthread_create(&mittu,NULL,(void *) mittu, param);
    pthread_join(ittu,NULL);
    pthread_join(bittu,NULL);
    pthread_join(mittu,NULL);
    pid=getpid();
    tid = syscall(SYS_gettid);
    printf("Main- Process ID = %d, thread ID = %d, CPU = %d, Result = %d\n",pid,tid, sched_getcpu(), result);

    return 0;


}
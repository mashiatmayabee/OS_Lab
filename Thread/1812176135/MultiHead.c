#define _GNU_SOURCE
#define _POSIX_SOURCE
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sched.h>
#include<syscall.h>
// #include<stdlib.h>
#include<signal.h>

int num[2];
int result;

pthread_mutex_t key;

void *Ittu(void * parm){
    pthread_mutex_lock(&key);
    int *param = (int *)parm;
    int a= param[0];
    int b= param[1];
    result= a+b;
    pid_t pid, tid;
    pid = getpid();
    tid = syscall(SYS_gettid);
    printf("Ittu- Process ID = %d, thread ID = %d, CPU = %d, Sum Result = %d\n",pid,tid, sched_getcpu(), result);
    if(result==100){
        printf("Kill System\n");
        kill(tid, SIGTERM);
    }
    pthread_mutex_unlock(&key);
}
void *Bittu(void * parm){
    pthread_mutex_lock(&key);
    int *param = (int *)parm;
    int a= param[0];
    int b= param[1];
    result= a-b;
    pid_t pid, tid;
    pid = getpid();
    tid = syscall(SYS_gettid);
    printf("Bittu- Process ID = %d, thread ID = %d, CPU = %d, Sub Reasult = %d\n",pid,tid, sched_getcpu(), result);
    if(result==100){
        printf("Kill System\n");
        kill(pid, SIGTERM);
    }
    pthread_mutex_unlock(&key);

}

void *Mittu(void * parm){
    pthread_mutex_lock(&key);
    int *param = (int *)parm;

    int a= param[0];
    int b= param[1];
    pid_t pid, tid;
    pid = getpid();
    tid = syscall(SYS_gettid);
    result= a*b;
    
    printf("Mittu-Process ID = %d, thread ID = %d, CPU = %d, Mul Result = %d\n",pid,tid, sched_getcpu(), result);
    if(result==100){
        printf("Kill System\n");
        kill(tid, SIGTERM);
    }
    pthread_mutex_unlock(&key);
   
}


int main(){
    int a, b;
    pthread_t ittu,bittu,mittu;
    pid_t pid, tid;
    for (int i = 1; i < 10; i++){
        scanf("%d %d", &num[0], &num[1]);
        pthread_create(&ittu,NULL, Ittu, (void*) num);
        pthread_create(&bittu,NULL,Bittu, (void *) num);
        pthread_create(&mittu,NULL,Mittu, (void *) num);

        pthread_join(ittu,NULL);
        pthread_join(bittu,NULL);
        pthread_join(mittu,NULL);

        pthread_mutex_lock(&key);
        pid=getpid();
        tid = syscall(SYS_gettid);
        printf("Main- Process ID = %d, thread ID = %d, CPU = %d, Result = %d\n",pid,tid, sched_getcpu(), result);
        pthread_mutex_unlock(&key);
    }

    return 0;
}
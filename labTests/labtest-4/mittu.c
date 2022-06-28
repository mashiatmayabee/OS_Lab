
#define _GNU_SOURCE
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/shm.h>
#include <string.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/wait.h>
#include<fcntl.h>


int create_shared_mem(){
	key_t key;
	int shmID;
	key = ftok("ittu.c", 'a');
	shmID = shmget(key, 1024, IPC_CREAT | 0666);
	return shmID;
}

void write_to_mem(int x){ 
	int shmID = create_shared_mem();	
	char *str = shmat(shmID, NULL, 0);
	char num[100];
	sprintf(num, "%d", x);
	strcpy(str, num);
	shmdt(str);
}

int read_from_mem(){ 
	int shmID = create_shared_mem();
	char *str = shmat(shmID, NULL, 0);
	int num = (int) strtol(str, (char **)NULL, 10);
	shmdt(str);
	return num;
}
int main(int argc, char *argv[]){
    
    int a,b;
    a=atoi(argv[0]);
    b=atoi(argv[1]);
    int result, x;
	sem_t *sem;
	sem = sem_open("/sem",O_CREAT,0666,1);

	sem_wait(sem);
    x = read_from_mem();
	printf("Mittu process ID= %d, CPU = %d\n", getpid(), sched_getcpu());
    printf("Before multiplication a = %d \n", a);
    printf("Before multiplication b = %d \n", b);
    printf("Before multiplication result = %d \n", x);
    result = result + (a * b);
    write_to_mem(result);
    x = read_from_mem();
    printf("After multiplication a = %d \n", a);
    printf("After multiplication b = %d \n", b);
    printf("After multiplication result = %d \n", x);
	sem_post(sem);
	shmdt(sem);


    
}
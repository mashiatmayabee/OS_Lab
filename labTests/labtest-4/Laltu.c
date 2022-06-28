
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


int main()
{
	pid_t pid, pid1, pid2;
	int a, b , result;
	char s1[10],s2[10];
	result = 0;
    scanf("%d %d", &a, &b);

	sprintf(s1, "%d", a);
	sprintf(s2, "%d", b);

    
	write_to_mem(result);
	int x = read_from_mem();
	printf("At first res = %d\n", x);
	
	pid = fork();
	if (pid == 0) {
        execlp("./ittu", s1, s2, NULL); 
	}

	else {
		pid1 = fork();
		if (pid1 == 0) {
            execlp("./bittu", s1, s2 ,NULL); 
		}
		else {
			pid2 = fork();
			if (pid2 == 0) {
                execlp("./mittu", s1, s2, NULL); 
			}
			else {
				printf("Parent process- pid = %u, CPU= %u\n", getpid(), sched_getcpu());
                
			}
		}
	}

	return 0;
}

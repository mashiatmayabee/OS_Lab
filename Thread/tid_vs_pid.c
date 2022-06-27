
#include <pthread.h> 
#include <stdio.h>
#include <syscall.h>
#include <unistd.h>

void sub_thread1(){
	int i;
	pid_t pid, tid;
	for (i = 1; i < 10; i++){
		pid = getpid();
		tid = syscall(SYS_gettid);
		printf("%d. SubThread1\n", i); 
	}
}

void sub_thread2(){
	pid_t pid, tid;
	for (int i = 1; i < 10; i++){
		pid = getpid();
		tid = syscall(SYS_gettid);
		printf("%d. SubThread1\n", i); 
	}
}


int main(){
	int i;
	pthread_t tid1, tid2;
	pid_t pid, tid;

	// Create two threads.
	pthread_create(&tid1, NULL, (void *) sub_thread1, NULL);
	pthread_create(&tid2, NULL, (void *) sub_thread2, NULL);

	for (i = 1; i < 10; i++){
		pid = getpid();
		tid = syscall(SYS_gettid);
		printf("%d. MainThread1\n", i); 
	}

	// Main thread will wait until sub-threads are running.
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}
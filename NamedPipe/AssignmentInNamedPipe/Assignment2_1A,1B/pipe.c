#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
//#include<stdlib.h>


int main(){
	char *pipepath;
	pipepath=  "/home/mayabee/Documents/pipe1";
	pipepath=  "/home/mayabee/Documents/pipe2";

	mkfifo(pipepath, 0666);
	return 0;
}
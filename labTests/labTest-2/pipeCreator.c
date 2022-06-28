
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int pipeFlag, fd, i;
	for( i=1 ;i<argc ;i++){
		if(access(argv[i], F_OK) == 0) { 
		printf("Already exists\n");
		} else {
			pipeFlag = mkfifo(argv[i], 0666);
			
			printf("Pipe created\n");
			
		}
	}

	
	return 0;
}

#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>S
//#include<stdlib.h>


int main(){
	char *pipepath,*msg,*str, buffer[100];
	
	int fd;
	pipepath= "/home/mayabee/OS-Class-Practices/NamedPipe/AssignmentInNamedPipe/1stpipe";
	
	while(1){
		fgets(buffer, 100, stdin);
		
		fd = open(pipepath, O_WRONLY);
		write(fd, buffer, strlen(msg)+1);
		close(fd);
		if(!strcmp(str, "-999") )
		{
			break;
		}

	}
	
	
	return 0;
	
	
}

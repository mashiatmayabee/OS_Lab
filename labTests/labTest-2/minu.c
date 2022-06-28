#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	int fd;
	char str[200];
    pid_t pid, ppid;
    pid = getpid();
    ppid = getppid();
    sprintf(str, "Hello pid %d ppid %d\n" ,pid,ppid);
    
    fd = open(argv[1], O_WRONLY);	
    write(fd, str, strlen(str) + 1);
    close(fd);

	while(1){
        fgets(str, 200, stdin);
       
        fd = open(argv[1], O_WRONLY);	
        write(fd, str, strlen(str) + 1);
        close(fd);
        if(!strcmp(str, "Bye\n")){
            fd = open(argv[1], O_RDONLY);	
            read(fd,str, sizeof(str)+1);
            close(fd);
            write(STDOUT_FILENO, str, strlen(str));
            return 0;
        }
        

    }
	
	return 0;
}
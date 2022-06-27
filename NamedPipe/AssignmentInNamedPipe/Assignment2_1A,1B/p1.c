#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int fd;
	char *pipePath1,*pipePath2, *msg,*str,buffer[200];

	pipePath1 = "/home/mayabee/Documents/pipe1";
	pipePath2 = "/home/mayabee/Documents/pipe2";
	//writing
	msg = "hey\n";
	fd = open(pipePath1, O_WRONLY);	
	write(fd, msg, strlen(msg) + 1);
	close(fd);

	//reading from pipe2
	fd = open(pipePath2, O_RDONLY);	
	read(fd, buffer, sizeof(buffer));
	close(fd);

	// Display to the monitor.
	write(STDOUT_FILENO, buffer, strlen(buffer));

	return 0;
}
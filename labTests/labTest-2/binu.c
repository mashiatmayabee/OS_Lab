#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include<stdio.h>

int main(int argc, char* argv[]){
	int fd;
	char str[200],m[200];
	char buffer[200];

    fd = open(argv[1], O_RDONLY);	
    read(fd, buffer, sizeof(buffer)+1);
    close(fd);
    write(STDOUT_FILENO, buffer, strlen(buffer)+1);


    while (1){
        fd = open(argv[1], O_RDONLY);	
        read(fd,str, sizeof(str)+1);
        close(fd);
        write(STDOUT_FILENO, str, strlen(str));

        if (!strcmp(str, "Bye\n"))
        {

            fd = open(argv[1], O_WRONLY);
            char* m;
            m="Bye\n";
            write(fd, m, strlen(m) + 1);
            close(fd);
            return 0;
        }
        
       
    }

	return 0;
}
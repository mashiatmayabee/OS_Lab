#include <unistd.h>
#include<stdio.h>
void main(int argc, char *argv[]){
	for (int i = 0; i <argc;  i++)
		fork();
        printf("hi\n");
}

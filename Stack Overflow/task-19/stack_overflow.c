#include<stdio.h>
#include<string.h>
void simple_copy_function(char *str);

int main(int argc, char *argv[]){
    for (int i=0; i<argc;i++){
        printf("Assignment %d %s\n",i,argv[i]);
        simple_copy_function(argv[i]);
    }
    printf("everything is good\n");
    return 0;
}
void simple_copy_function(char *str){
    char buffer[5];
    printf("Strlen = %lu buffer len= %lu\n", strlen(str), strlen(buffer));
    if(strlen(str)<strlen(buffer)){
        strcpy(buffer, str);
        printf("Buffer: %s\n",buffer);
    }
}
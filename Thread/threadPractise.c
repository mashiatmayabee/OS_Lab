#include<stdio.h>
#include<pthread.h>

void sub_thread(){
    int i;
    pid_t pid, tid;
    

}
int main(){

}



/*#include <stdio.h>
#include <pthread.h>

int x = 100;
pthread_mutex_t key;
void sum()
{
    int i;
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&key);
        printf("%d , before sum: %d\n", i, x);
        x = x + 1;
        printf("%d , after sum: %d\n", i, x);
        pthread_mutex_unlock(&key);


    }
}
void sub()
{
    int i;
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&key);

        printf("%d , before sub: %d\n", i, x);
        x = x - 1;
        printf("%d , after sub: %d\n", i, x);
        pthread_mutex_unlock(&key);

    }
}
int main()
{
    int i;
    pthread_t t1, t2;
    pthread_create(&t1, NULL, (void *)sum, NULL);
    pthread_create(&t2, NULL, (void *)sub, NULL);
    for (int i = 0; i < 10; i++)
    {
        printf("%d Main %d\n", i, x);
    }
    pthread_join(t2, NULL);
    pthread_join(t1, NULL);
    return 0;
}*/

// void sum(){
//     for (size_t i = 0; i < 50; i++)
//     {
//         /* code */
//         printf("Sub function\n");
//     }

// }
// int main(){
//     pthread_t t1;
//     pthread_create(&t1, NULL, (void*)sum, NULL);
//     pthread_join(t1, NULL);
//     for (size_t i = 0; i < 50; i++)
//     {
//         /* code */
//         printf("Main\n");
//     }

// }
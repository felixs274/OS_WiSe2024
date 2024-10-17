// Blatt 1
// Aufgabe 2
// Threads

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum; // Data shared by the Thread(s)

void *runner(void *param){ // Threads call this function
    printf("Thread created\n");
    int i, upper = atoi(param);
    sum = 0;

    for(i = 1; i <= upper; i++){
        sum += i;
    }

    pthread_exit(0);
}

int main(int argc, char *argv[]){

    pthread_t tid; // Thread identifier
    pthread_attr_t attr; // Set of Thread attributes

    if(argc != 2){
        fprintf(stderr, "usage: a.out <int>\n");
    }

    // atoi == ASCII to Int
    if(atoi(argv[1]) < 0){
        fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
        return -1;
    }

    // Get Default Attributes
    pthread_attr_init(&attr);
    // Create the Thread
    pthread_create(&tid, &attr, runner, argv[1]);
    printf("After Thread create\n");
    // Wait fot Thread to exit
    pthread_join(tid, NULL);
    printf("Thread finished\n");

    printf("sum = %d\n", sum);

}
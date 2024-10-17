// Blatt 1
// Aufgabe 1
// Prozesse

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int a = 5;

int main(){
    pid_t pid;

    // Create Child Process
    pid = fork();

    if(pid < 0){ // Error
        fprintf(stderr, "Ford Failed");
        return 1;
    } 
    else if(pid == 0){ // Child Process
        //execlp("/bin/ls", "ls", NULL);
        printf("Child PID: %d\n", getpid());
        printf("Var a: %d+1\n", a);
        a += 1;
    } 
    else { // Parent Process
        // Parent will wait for Child to complete
        wait(NULL);
        printf("\nChild complete\n\n");
        printf("Parent PID: %d\n", getpid());
        printf("Var a: %d\n", a);
    }
}
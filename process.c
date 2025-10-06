#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *user_name = "Unknown user";

    if (argc > 1){
        user_name = argv[1];
    }

    printf("I'm child process!\n");
    printf("My PID: %d\n", getpid());
    printf("My PPID: %d\n", getppid());
    printf("Working for: %s", user_name);
    
    for(int i=0; i<=10; i++){
        printf("Working...step %d\n", i)
        sleep(1);
    }

    printf("Child process ended successful!\n");
    return 0;
}


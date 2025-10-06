#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void signal_handler(int sig){
    printf("Получен сигнал %d\n", sig);
}

int main() {
    int status;
    pid_t pid;
    char user_input[100];

    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    printf("Input your name: ");
    if (scanf("%99s", user_input) != 1){
        printf("Input error!\n");
        return 1;
    }
    
    printf("Hello, %s. Creating child process...\n", user_input);

    pid = fork();

    if(pid == -1){
        perror("Error while executing fork()\n");
        return 1;
    }
    else if(pid == 0){
        printf("Child proccess: PID = %d, PPID = %d", getpid(), getppid());
        execl("./process", "process", user_input, NULL);
        perror("Error while executing execl()\n");
        exit(1);
    } 
    else {
        printf("Parent process: PID = %d, created child process with PID = %d\n", getpid(), pid);
        printf("Wait child process close...\n");
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)){
            printf("Child process ended with exit code: %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status)) {
            printf("Child process killed by signal: %d\n", WTERMSIG(status));
        }
    }
    printf("Programm ended up. Goodbye, %s!\n", user_input);
    return 0;
}




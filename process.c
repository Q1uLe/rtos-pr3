/*--------------------------------------------------------*/
/* ИМЯ: SHARIPOV RENAT, ID ПОЛЬЗОВАТЕЛЯ: 23К0210          */
/* СРОК: 07/10/2025                                       */
/* ИМЯ ФАЙЛА: process.c                                   */
/* НАЗНАЧЕНИЕ ПРОГРАММЫ:                                  */
/* Дочерняя программа, которая выполняет работу и         */
/* демонстрирует информацию о процессе                    */
/*--------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/*--------------------------------------------------------*/
/* ФУНКЦИЯ: main                                          */
/* Основная функция дочернего процесса, которая           */
/* демонстрирует работу и информацию о процессе           */
/* ИСПОЛЬЗУЕМЫЕ ПАРАМЕТРЫ:                                */
/* int argc - количество аргументов командной строки      */
/* char *argv[] - массив аргументов командной строки      */
/* ВЫЗЫВАЕМЫЕ ФУНКЦИИ:                                    */
/* printf(), getpid(), getppid(), sleep()*/
/*--------------------------------------------------------*/


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


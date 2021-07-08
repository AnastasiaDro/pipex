#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include "pipex.h"
#include "libft/libft.h"

int main(int argc, char *argv[], char **envp)
{

    char **pathList;
    char *command1;
    char **execArr;
    int pid0;
    int pid1;
    int pfd[2];
    int fileFd;

    pid0 = -1;
    pid1 = -1;
    if(argc != 5)
        return (printf("неправильное число аргументов!\n"));
    //далее если 4 аргумента нам нужно разбить на 2 массива,
    //в одном аргументы для одного массива, в другом для другого

    //здесь будем искать бинарники
    pathList = pipexSplit(findPath(envp), ':');


    //пайп
    pipe(pfd);
    printf("fork1\n");
    pid0 = fork(); //дочка 1 пид0 = 0 пид 1 = 0


    if (pid0 == 0)  //дочка 1
    {
        close(pfd[0]);
        printf("дочка1\n");
        //write(1, "Here!1\n", 7);
        command1 = argv[2];
       //write(1, "Here!10\n", 8);
        execArr = getExecArr(command1, pathList);
       // write(1, "Here!11\n", 8);
        fileFd = open(argv[1], O_RDWR); //открываем файл, из которого берём данные
        printf("fileFd = %d\n", fileFd);
      //  write(1, "Here!12\n", 8);

        dup2(fileFd, 0); //меняем stdin на fd-шник файла

//      //  write(1, "Here!13\n", 8);
        close(fileFd); //dup2 создает копию, поэтому мы закрываем фд-шник файла, копия уже вместе stdin
        dup2(pfd[1], 1); //меняем stdout на вывод в пайп
        close(pfd[1]); //закрываем
      //  dup2(pfd[0], fileFd);
////
//        close(pfd[0]);
      //  write(1, "Here!14\n", 8);
        //dup2(fileFd, 1); //м
        execve(execArr[0], execArr, envp); //выполняем команду
    }
    char arr[50];
    read(pfd[0], arr, 50);
    printf("%.10s \n", arr);
//    if (pid0 != 0)
//    {
//        printf("fork2\n");
//        pid1 = fork(); //дочка2
//    }
//    if (pid1 == 0)   //дочка 2
//    {
//        printf("дочка2\n");
//        command1 = argv[3];
//        execArr = getExecArr(command1, pathList);
////        write(1, execArr[0], ft_strlen(execArr[0]));
////        write(1, "\n", 1);
////        write(1, execArr[1], ft_strlen(execArr[1]));
////        write(1, "\n", 1);
//       // fileFd = open(argv[4], O_WRONLY);
//        dup2(pfd[0], 0);
//      //  close(pfd[0]);
//        write(1, "Here!21\n", 8);
//    //    dup2(fileFd, 1);
//     //   close(fileFd);
//        execve(execArr[0], execArr, envp);
//    }
        close(pfd[0]);
        close(pfd[1]);
    write(1, "Here!3\n", 7);
    printf("pid 0 = %d\n", pid0);
    printf("pid1 = %d\n", pid1);
    wait(NULL);
  //  wait(NULL);
    write(1, "Here!4\n", 7);
    return (0);
}

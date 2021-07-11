#include <unistd.h>
#include <printf.h>
#include "_bonus.h"
#include "pipex.h"

//
// Created by Cesar Erebus on 7/11/21.
//
int _bonus_parseCmd(int ***fd, int current_index, int commands_num, char *argv[], char **pathList)
{
    int **tmp;
    char *command;
    char **execArr;
    int pid;


   // printf("current index = %d\n", current_index);
    pid = fork();
    if (pid == 0)
    {

        tmp = *fd;
       // write(1, "III\n", 4);
        dup2(tmp[current_index][0], STDIN_FILENO); //перенаправили ввод
        dup2(tmp[current_index + 1][1], STDOUT_FILENO); //перенаправили вывод
     //   write(1, "III\n", 4);
        _bonus_closeAllFds(fd, commands_num);
        command = argv[2 + current_index];
      //  printf("argv[%d] = %s\n", 2 + current_index, argv[2 + current_index]);
        execArr = getExecArr(command, pathList);
      //  write(1, "UUU\n", 4);
        execve(execArr[0], execArr, NULL); //вы
    }
    return 0;
}


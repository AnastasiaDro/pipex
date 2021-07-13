//
// Created by Cesar Erebus on 7/13/21.
//

#include <unistd.h>
#include <sys/fcntl.h>
#include "pipex.h"
#include "_bonus.h"

int parseFirstCommand(char *argv[], char **pathList, int **fd, int commands_num)
{
    int pid;
    char *command;
    char **execArr;
    int fileFd;

    pid = fork();
    if (pid < 0)
        return (2);
    if (pid == 0)
    {
        command = argv[2];
        execArr = getExecArr(command, pathList);
        fileFd = open(argv[1], O_RDWR); //открываем файл, из которого берём данные
        if (fileFd == -1)
        {
            printError(FILE_ERR, argv[1]);
            _bonus_closeAllFds(&fd, commands_num);
            return 9;
        }
        dup2(fd[1][1], STDOUT_FILENO);
        dup2(fileFd, STDIN_FILENO);
        close(fileFd);
        _bonus_closeAllFds(&fd, commands_num);
        execve(execArr[0], execArr, NULL);
    }
    return (1);
}
//
// Created by Cesar Erebus on 7/13/21.
//

#include <unistd.h>
#include <sys/fcntl.h>
#include "pipex.h"
#include "_bonus.h"
#include <string.h>

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
        fileFd = open(argv[1], O_RDWR); //открываем файл, из которого берём данные
        if (fileFd == -1)
        {
            printError(argv[1], 0);
            mFree(pathList);
            _bonus_closeAllFds(&fd, commands_num);
            exit(0);
        }
        execArr = getExecArr(command, pathList);
        if (!execArr)
        {
            _bonus_closeAllFds(&fd, commands_num);
            mFree(pathList);
            exit(0);
        }
        dup2(fd[1][1], STDOUT_FILENO);
        dup2(fileFd, STDIN_FILENO);
        close(fileFd);
        _bonus_closeAllFds(&fd, commands_num);
        mFree(pathList);
        execve(execArr[0], execArr, NULL);
    }
    return (1);
}

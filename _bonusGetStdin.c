//
// Created by Cesar Erebus on 7/17/21.
//
#include <sys/fcntl.h>
#include "pipex.h"
#include "_bonus.h"

int _bonusGetStdin(int **fd, char *command, char **pathList, int tmpFd, int commands_num)
{
    int pid;
    char **execArr;
    pid = fork();
    if (pid < 0)
        return (2);
    if(pid == 0)
    {
        tmpFd = open("tmpFile", O_RDONLY, 0644);
        dup2(tmpFd, STDIN_FILENO);
        execArr = getExecArr(command, pathList);
        dup2(fd[1][1], STDOUT_FILENO);
        close(tmpFd);
        close(fd[0][0]);
        close(fd[1][1]);
        _bonus_closeAllFds(&fd, commands_num);
        mFree(pathList);
        execve(execArr[0], execArr, NULL);
    }
    return (0);
}

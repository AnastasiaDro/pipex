//
// Created by Cesar Erebus on 7/17/21.
//
#include <sys/fcntl.h>
#include "pipex.h"
#include "pipex_bonus.h"

int bonusGetStdin(int **fd, char *command, int tmpFd, t_bstruct *bStruct)
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
        execArr = getExecArr(command, bStruct->pathList);
        dup2(fd[1][1], STDOUT_FILENO);
        close(tmpFd);
        close(fd[0][0]);
        close(fd[1][1]);
        closeAllFds(&fd, bStruct->commands_num);
        mFree(bStruct->pathList);
        execve(execArr[0], execArr, NULL);
    }
    return (0);
}


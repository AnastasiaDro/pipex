//
// Created by Cesar Erebus on 7/13/21.
//

#include <unistd.h>
#include <sys/fcntl.h>
#include "pipex_bonus.h"
#include <string.h>

int parseFirstCommand(int **fd, t_bstruct *bStruct)
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
        command = (bStruct->argv)[2];
        fileFd = open((bStruct->argv)[1], O_RDWR); //открываем файл, из которого берём данные
        if (fileFd == -1)
        {
            printError((bStruct->argv)[1], 0);
            mFree(bStruct->pathList);
            closeAllFds(&fd, bStruct->commands_num);
            exit(0);
        }
        execArr = getExecArr(command, bStruct->pathList);
        if (!execArr)
        {
            closeAllFds(&fd, bStruct->commands_num);
            mFree(bStruct->pathList);
            exit(0);
        }
        dup2(fd[1][1], STDOUT_FILENO);
        dup2(fileFd, STDIN_FILENO);
        close(fileFd);
        closeAllFds(&fd, bStruct->commands_num);
        mFree(bStruct->pathList);
        execve(execArr[0], execArr, NULL);
    }
    return (1);
}

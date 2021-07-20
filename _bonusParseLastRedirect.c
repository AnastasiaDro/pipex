//
// Created by Cesar Erebus on 7/17/21.
//
#include "pipex.h"
#include "pipex_bonus.h"

int _bonusParseLastRedirect(char **pathList, int **fd, t_bstruct *bStruct)
{
    int pid;
    char *command;
    int fileFd;
    char **execArr;

    pid = fork();
    if (pid < 0)
        return (2);
    if(pid == 0)
    {
        command = bStruct->argv[bStruct->argc - 2];
        execArr = getExecArr(command, pathList);
        if(!access(bStruct->argv[bStruct->argc - 1], 0))
            fileFd = open(bStruct->argv[bStruct->argc - 1], O_RDWR | O_APPEND);
        else
            fileFd = open(bStruct->argv[bStruct->argc - 1], O_CREAT | O_RDWR, 0644);
        if (fileFd == -1)
        {
            printError(bStruct->argv[bStruct->argc - 1], 0);
        }
        dup2(fd[bStruct->commands_num - 1][0], STDIN_FILENO);
        dup2(fileFd, STDOUT_FILENO);
        close(fileFd);
        closeAllFds(&fd, bStruct->commands_num);
        mFree(pathList);
        execve(execArr[0], execArr, NULL);
        return (1);
    }
    return (0);
}

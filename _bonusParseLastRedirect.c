//
// Created by Cesar Erebus on 7/17/21.
//
#include "pipex.h"
#include "_bonus.h"

int _bonusParseLastRedirect(char *argv[], char **pathList, int **fd, int commands_num, int argc)
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
        command = argv[argc - 2];
        execArr = getExecArr(command, pathList);
        if(!access(argv[argc - 1], 0))
            fileFd = open(argv[argc - 1], O_RDWR | O_APPEND);
        else
            fileFd = open(argv[argc - 1], O_CREAT | O_RDWR, 0644);
        if (fileFd == -1)
        {
            printError(argv[argc - 1], 0);
        }
        dup2(fd[commands_num - 1][0], STDIN_FILENO);
        dup2(fileFd, STDOUT_FILENO);
        close(fileFd);
        _bonus_closeAllFds(&fd, commands_num);
        mFree((void **)pathList);
        execve(execArr[0], execArr, NULL);
        return (1);
    }
    return (0);
}

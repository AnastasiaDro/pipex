#include <unistd.h>
#include <sys/fcntl.h>
#include "pipex_bonus.h"

int parseLastCommand(int **fd, t_bstruct *bStruct)
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
        command = bStruct->argv[bStruct->argc - 2];
        execArr = getExecArr(command, bStruct->pathList);
        if(!access(bStruct->argv[bStruct->argc - 1], 0))
            fileFd = open(bStruct->argv[bStruct->argc - 1], O_TRUNC | O_RDWR); //открываем файл, из которого берём данные
        else
            fileFd = open(bStruct->argv[bStruct->argc - 1], O_CREAT | O_RDWR, 0644);
        if (fileFd == -1)
        {
            printError(bStruct->argv[bStruct->argc - 1], 0);
        }
        dup2(fd[bStruct->commands_num - 1][0], STDIN_FILENO);
        dup2(fileFd, STDOUT_FILENO);
        close(fileFd);
        bonusCloseAllFds(&fd, bStruct->commands_num);
        execve(execArr[0], execArr, NULL);
        free(fd);
    }
    return (1);
}
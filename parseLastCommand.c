#include <unistd.h>
#include <sys/fcntl.h>
#include "pipex.h"
#include "_bonus.h"

int parseLastCommand(char *argv[], char **pathList, int **fd, int commands_num, int argc)
{
    int pid;
    char *command;
    char **execArr;
    int fileFd;

    pid = fork();
    if (pid == 0)
    {
        command = argv[argc - 2];
        execArr = getExecArr(command, pathList);
        if(!access(argv[argc - 1], 0))
            fileFd = open(argv[argc - 1], O_TRUNC | O_RDWR); //открываем файл, из которого берём данные
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
        execve(execArr[0], execArr, NULL);
    }
    return (1);
}
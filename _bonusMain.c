#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include "pipex.h"
#include "libft/libft.h"
#include "_bonus.h"

int main(int argc, char *argv[], char **envp)
{

    char **pathList;
    char *command;
    char **execArr;
    int pid;
    int **fd;
    int fileFd;

    pathList = pipexSplit(findPath(envp), ':');
    fd = malloc((argc - 2) * sizeof (int *));
    int commands_num = 0;
    while(commands_num < argc - 2)
    {
        fd[commands_num] = malloc(2 * sizeof (int));
        pipe(fd[commands_num]); //сразу сделали пайпы
        commands_num++;
    }
    commands_num--;

    pid = fork();
    if (pid < 0)
        return (2);

    //обработка первой команды
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
        execve(execArr[0], execArr, envp);
    }
    int j = 1;
    while(j < commands_num - 1)
    {
        pid = fork();
        if (pid == 0)
            _bonus_parseCmd(&fd, j, commands_num, argv, pathList);
        j++;
    }
    pid = fork();
    if (pid == 0)
    {
        command = argv[argc - 2];
        execArr = getExecArr(command, pathList);
        fileFd = open(argv[argc - 1], O_TRUNC | O_RDWR); //открываем файл, из которого берём данные
        if (fileFd == -1)
        {
            printError(FILE_ERR, argv[argc - 1]);
        }
        dup2(fd[commands_num - 1][0], STDIN_FILENO);
        dup2(fileFd, STDOUT_FILENO);
        close(fileFd);
        _bonus_closeAllFds(&fd, commands_num);
        execve(execArr[0], execArr, envp);
    }
    _bonus_closeAllFds(&fd, commands_num);
    while(1)
    {
        if (wait(NULL) == -1)
            break;
    }
}

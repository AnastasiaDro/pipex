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
    int pid1;
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
        command = argv[2];
        execArr = getExecArr(command, pathList);
        execve(execArr[0], execArr, envp); //вы
    }

    //обработка комманд между
    int j = 1; //счетчик команд
    while(j < commands_num - 1)
    {
       // printf("j = %d\n", j);
        _bonus_parseCmd(&fd, j, commands_num, argv, pathList);
        printf("j = %d\n", j);
        j++;
    }

    pid1 = fork();
    if (pid1 == 0)
    {
        fileFd = open(argv[argc - 1], O_TRUNC | O_RDWR); //открываем файл, из которого берём данные
        if (fileFd == -1)
        {
            printError(FILE_ERR, argv[argc - 1]);
        }
        dup2(fd[commands_num - 1][0], STDIN_FILENO);
        dup2(fileFd, STDOUT_FILENO);
        close(fileFd);
        _bonus_closeAllFds(&fd, commands_num);
        command = argv[argc - 2];
        execArr = getExecArr(command, pathList);
        execve(execArr[0], execArr, envp); //вы
    }
    _bonus_closeAllFds(&fd, commands_num);
    while(1)
    {
        if (wait(NULL) == -1)
            break;
    }
}

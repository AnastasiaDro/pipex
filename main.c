#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include "pipex.h"
#include "libft/libft.h"

int main(int argc, char *argv[], char **envp)
{

    char **pathList;
    char **execArr;
    char *command;
    int pid1;
    int pid2;
    int pfd[2];
    int fileFd;


    if(argc != 5)
        return ((int)write(1, ARGNUM_ERR, (int)ft_strlen(ARGNUM_ERR)));
    pathList = pipexSplit(findPath(envp), ':');

    //пайп
    if (pipe(pfd) == -1)
        return (1);
    pid1 = fork();
    if (pid1 < 0)
        return (2);

    if (pid1 == 0)
    {
        fileFd = open(argv[1], O_RDWR); //открываем файл, из которого берём данные
        if (fileFd == -1)
        {
            printError(argv[1], 0);
            return 9;
        }
        dup2(pfd[1], STDOUT_FILENO);
        dup2(fileFd, STDIN_FILENO);
        close(pfd[0]);
        close(pfd[1]);
        close(fileFd);
        command = argv[2];
        execArr = getExecArr(command, pathList);
        mFree(pathList);
        execve(execArr[0], execArr, envp); //вы
    }

    pid2 = fork();
    if (pid2 < 0)
        return 3;

    if (pid2 == 0 )
    {
        if(!access(argv[argc - 1], 0))
            fileFd = open(argv[argc - 1], O_TRUNC | O_RDWR);
        else
            fileFd = open(argv[argc - 1], O_CREAT | O_RDWR, 0644);
        if (fileFd == -1)
        {
            printError( argv[4], 0);
            return 9;
        }
        dup2(pfd[0], STDIN_FILENO);
        close(pfd[0]);
        close(pfd[1]);
        dup2(fileFd, STDOUT_FILENO);
        close(fileFd);
        command = argv[3];
        execArr = getExecArr(command, pathList);
        execve(execArr[0], execArr, envp);
    }
    close(pfd[0]);
    close(pfd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    system("leaks pipex");
}

#include <unistd.h>
#include "_bonus.h"
#include "pipex.h"

int _bonus_parseCmd(int ***fd, int current_index, int commands_num, char *argv[], char **pathList)
{
    int **tmp;
    char *command;
    char **execArr;
    int pid;

    pid = fork();
    if (pid == 0)
    {
        tmp = *fd;
        dup2(tmp[current_index][0], STDIN_FILENO); //перенаправили ввод
        dup2(tmp[current_index + 1][1], STDOUT_FILENO); //перенаправили вывод
        _bonus_closeAllFds(fd, commands_num);
        command = argv[2 + current_index];
        execArr = getExecArr(command, pathList);
        execve(execArr[0], execArr, NULL); //вы
    }
    return 0;
}

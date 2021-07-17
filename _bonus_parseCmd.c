#include <unistd.h>
#include "_bonus.h"
#include "pipex.h"
#include "libft/libft.h"

int _bonus_parseCmd(int ***fd, int current_index, int commands_num, char *argv[], char **pathList, int flag)
{
    int **tmp;
    char *command;
    char **execArr;
    int coef;

    if (flag == HERE_DOC)
        coef = 3;
    else
        coef = 2;
    command = argv[coef + current_index];
    execArr = getExecArr(command, pathList);
    tmp = *fd;
    if (execArr == NULL)
    {
        _bonus_closeAllFds(fd, commands_num);
         exit(0);
    }
    dup2(tmp[current_index][0], STDIN_FILENO);
    dup2(tmp[current_index + 1][1], STDOUT_FILENO);
    _bonus_closeAllFds(fd, commands_num);
    execve(execArr[0], execArr, NULL);
    return (0);
}

#include <unistd.h>
#include "_bonus.h"
#include "pipex.h"
#include "libft/libft.h"

int _bonus_parseCmd(int ***fd, int current_index, int commands_num, char *argv[], char **pathList)
{
    int **tmp;
    char *command;
    char **execArr;

    command = argv[2 + current_index];
    execArr = getExecArr(command, pathList);
    tmp = *fd;
    dup2(tmp[current_index][0], STDIN_FILENO);
    dup2(tmp[current_index + 1][1], STDOUT_FILENO);
    _bonus_closeAllFds(fd, commands_num);
    execve(execArr[0], execArr, NULL);
    return (0);
}

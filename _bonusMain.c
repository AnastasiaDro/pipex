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
    int **fd;
    int commands_num;

    if (argc < 5)
    {
        write(1, ARGNUM_ERR, ft_strlen(ARGNUM_ERR));
        return (1);
    }
    pathList = pipexSplit(findPath(envp), ':');
    fd = malloc((argc - 2) * sizeof (int *));
    commands_num = 0;
    while(commands_num < argc - 2)
    {
        fd[commands_num] = malloc(2 * sizeof (int));
        pipe(fd[commands_num]); //сразу сделали пайпы
        commands_num++;
    }
    commands_num--;
    parseFirstCommand(argv, pathList, fd, commands_num);
    _bonus_parseMiddleCommands(commands_num, fd, argv, pathList);
    parseLastCommand(argv, pathList, fd, commands_num, argc);
    _bonus_closeAllFds(&fd, commands_num);
    waitChildren();
}

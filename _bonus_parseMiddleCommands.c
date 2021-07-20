#include <unistd.h>
#include "pipex_bonus.h"

int _bonus_parseMiddleCommands(int **fd, char **pathList, t_bstruct *bStruct)
{
    int j;
    int pid;

    j = 1;
    while(j < bStruct->commands_num - 1)
    {
        pid = fork();
        if (pid == 0)
        {
            _bonus_parseCmd(&fd, j, pathList, bStruct);
        }
        j++;
    }
    return (0);
}


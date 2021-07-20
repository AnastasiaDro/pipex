#include <unistd.h>
#include "pipex_bonus.h"

int bonusParseMiddleCommands(int **fd, t_bstruct *bstruct)
{
    int j;
    int pid;

    j = 1;
    while(j < bstruct->commands_num - 1)
    {
        pid = fork();
        if (pid == 0)
        {
            bonusParseCmd(&fd, j, bstruct);
        }
        j++;
    }
    return (0);
}

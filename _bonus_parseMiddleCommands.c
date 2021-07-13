#include <unistd.h>
#include "_bonus.h"

int _bonus_parseMiddleCommands(int commands_num, int **fd, char *argv[], char **pathList)
{
    int j;
    int pid;

    j = 1;
    while(j < commands_num - 1)
    {
        pid = fork();
        if (pid == 0)
            _bonus_parseCmd(&fd, j, commands_num, argv, pathList);
        j++;
    }
    return (0);
}

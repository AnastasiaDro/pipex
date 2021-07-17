#include <unistd.h>
#include <printf.h>
#include "_bonus.h"

int _bonus_parseMiddleCommands(int commands_num, int **fd, char *argv[], char **pathList, int flag)
{
    int j;
    int pid;

    j = 1;
    printf("commands_num = %d\n", commands_num);
    while(j < commands_num - 1)
    {
        pid = fork();
        if (pid == 0)
        {
            _bonus_parseCmd(&fd, j, commands_num, argv, pathList, flag);
        }
        j++;
    }
    return (0);
}

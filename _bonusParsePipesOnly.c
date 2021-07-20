//
// Created by Cesar Erebus on 7/17/21.
//
#include "bonus.h"

int _bonusParsePipesOnly(char *argv[], char **pathList, int **fd, int commands_num)
{
    parseFirstCommand(argv, pathList, fd, commands_num);
    _bonus_parseMiddleCommands(commands_num, fd, argv, pathList, 0);
    parseLastCommand(argv, pathList, fd, commands_num);
    closeAllFds(&fd, commands_num);
    mFree(pathList);
    waitChildren();
    system("leaks pipex");
    return (0);
}

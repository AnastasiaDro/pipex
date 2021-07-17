//
// Created by Cesar Erebus on 7/17/21.
//
#include "_bonus.h"

int _bonusParsePipesOnly(char *argv[], char **pathList, int **fd, int commands_num, int argc)
{
    parseFirstCommand(argv, pathList, fd, commands_num);
    _bonus_parseMiddleCommands(commands_num, fd, argv, pathList, 0);
    parseLastCommand(argv, pathList, fd, commands_num, argc);
    _bonus_closeAllFds(&fd, commands_num);
    waitChildren();
}
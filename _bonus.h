//
// Created by Cesar Erebus on 7/10/21.
//

#ifndef _BONUS_H
#define _BONUS_H
#define HERE_DOC 1
#include "pipex.h"

void _bonus_closeAllFds(int ***fd, int commands_num);
int _bonus_parseCmd(int ***fd, int current_index, int commands_num, char *argv[], char **pathList, int flag);
int _bonus_parseMiddleCommands(int commands_num, int **fd, char *argv[], char **pathList, int flag);
int _bonusParseHereDoc(char *argv[], char **pathList, int **fd, int commands_num, int argc);
int _bonusCheckHereDoc(char *argv[]);
int _bonusGetCommandsNum(int argc, int ***fd, int flag);
int  _bonusGetTmpFile(char *argv[]);
int _bonusGetStdin(int **fd, char *command, char **pathList, int tmpFd, int commands_num);
int _bonusParsePipesOnly(char *argv[], char **pathList, int **fd, int commands_num, int argc);
int _bonusParseLastRedirect(char *argv[], char **pathList, int **fd, int commands_num, int argc);

#endif //PIPEX__BONUS_H

//
// Created by Cesar Erebus on 7/10/21.
//

#ifndef _BONUS_H
#define _BONUS_H
#define HERE_DOC 1

void _bonus_closeAllFds(int ***fd, int commands_num);
int _bonus_parseCmd(int ***fd, int current_index, int commands_num, char *argv[], char **pathList, int flag);
int _bonus_parseMiddleCommands(int commands_num, int **fd, char *argv[], char **pathList, int flag);
int _bonusParseHereDoc(char *argv[], char **pathList, int **fd, int commands_num, int argc);

int _bonusGetCommandsNum(int argc, int ***fd, int flag);
int  _bonusGetTmpFile(int **fd, char *argv[]);
int _bonusGetStdin(int **fd, char *command, char **pathList, int tmpFd, int commands_num);

#endif //PIPEX__BONUS_H

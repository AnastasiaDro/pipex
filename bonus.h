#ifndef PIPEX_BONUS_H
#define PIPEX_BONUS_H
# define HERE_DOC 1
# include "pipex.h"

void closeAllFds(int ***fd, int commands_num);
int _bonus_parseCmd(int ***fd, int current_index, int commands_num, char *argv[], char **pathList, int flag);
int _bonus_parseMiddleCommands(int commands_num, int **fd, char *argv[], char **pathList, int flag);
int _bonusParseHereDoc(char *argv[], char **pathList, int **fd, int commands_num);
int _bonusCheckHereDoc(char *argv[]);
int  _bonusGetTmpFile(char *argv[]);
int _bonusGetStdin(int **fd, char *command, char **pathList, int tmpFd, int commands_num);
int _bonusParsePipesOnly(char *argv[], char **pathList, int **fd, int commands_num);
int _bonusParseLastRedirect(char *argv[], char **pathList, int **fd, int commands_num);

#endif
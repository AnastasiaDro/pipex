//
// Created by Cesar Erebus on 7/10/21.
//

#ifndef PIPEX_BONUS_H
#define PIPEX_BONUS_H
#define HERE_DOC 1
#include "pipex.h"

typedef struct s_bstruct
{
    int     argc;
    int     flag;
    int     commands_num;
    char    **argv;
}              t_bstruct;

void    initStruct(t_bstruct *bstruct, int argc, char *argv[]);
void closeAllFds(int ***fd, int commands_num);
int _bonus_parseCmd(int ***fd, int current_index, char **pathList, t_bstruct *bStruct);
int _bonus_parseMiddleCommands(int **fd, char **pathList,  t_bstruct *bstruct);
int _bonusParseHereDoc(char **pathList, int **fd, t_bstruct *bStruct);
int _bonusCheckHereDoc(char *argv[]);
int  _bonusGetTmpFile(char *argv[]);
int _bonusGetStdin(int **fd, char *command, char **pathList, int tmpFd, t_bstruct *tBstruct);
int _bonusParsePipesOnly(char **pathList, int **fd,  t_bstruct *tBstruct);
int _bonusParseLastRedirect(char **pathList, int **fd, t_bstruct *bstruct);
int parseLastCommand(char **pathList, int **fd, t_bstruct *bStruct);
int parseFirstCommand(char **pathList, int **fd, t_bstruct *bStruct);
#endif

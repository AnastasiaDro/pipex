//
// Created by Cesar Erebus on 7/10/21.
//

#ifndef _BONUS_H
#define _BONUS_H

void _bonus_closeAllFds(int ***fd, int commands_num);
int _bonus_parseCmd(int ***fd, int current_index, int commands_num, char *argv[], char **pathList);
int _bonus_parseMiddleCommands(int commands_num, int **fd, char *argv[], char **pathList);
int _bonusParseHereDoc(char **argv, char **pathList, int argc);

#endif //PIPEX__BONUS_H

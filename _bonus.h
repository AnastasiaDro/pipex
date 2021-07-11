//
// Created by Cesar Erebus on 7/10/21.
//

#ifndef _BONUS_H
#define _BONUS_H

int     _bonus_countArgs(char *argv[]);
void _bonus_closeLazyDescs(int ***fd, int currentIndex, int commands_num);
void _bonus_closeAllFds(int ***fd, int commands_num);
int _bonus_parseCmd(int ***fd, int current_index, int commands_num, char *argv[], char **pathList);

#endif //PIPEX__BONUS_H

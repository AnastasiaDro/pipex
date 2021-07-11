//
// Created by Cesar Erebus on 7/10/21.
//

#ifndef _BONUS_H
#define _BONUS_H

void _bonus_closeAllFds(int ***fd, int commands_num);
int _bonus_parseCmd(int ***fd, int current_index, int commands_num, char *argv[], char **pathList);

#endif //PIPEX__BONUS_H

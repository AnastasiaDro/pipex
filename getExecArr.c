//
// Created by Cesar Erebus on 7/6/21.
//

#include "pipex.h"

char **getExecArr(char *command, char **pathList)
{
    int arrLen;
    char **execArr;

    execArr = execArrSplit(command, ' ', &arrLen);
    char *path_command = findCommand(pathList, command); //нашли путь к команде
    execArr[0] = path_command;
  //  execArr[arrLen-1] = filename;
    return (execArr);
}

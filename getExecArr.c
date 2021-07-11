//
// Created by Cesar Erebus on 7/6/21.
//

#include <printf.h>
#include "pipex.h"

char **getExecArr(char *command, char **pathList)
{
    int arrLen;
    char **execArr;


    execArr = execArrSplit(command, ' ', &arrLen);
    char *path_command = findCommand(pathList, command); //нашли путь к команде
    //printf("execArr[0] = %s\n", execArr[0]);
    execArr[0] = path_command;
    return (execArr);
}


#include <string.h>
#include "pipex.h"

char **getExecArr(char *command, char **pathList)
{
    int arrLen;
    char **execArr;

    execArr = execArrSplit(command, ' ', &arrLen);
    char *path_command = findCommand(pathList, command); //нашли путь к команде
    if (path_command == NULL)
    {
        printError(command, 1);
        return (NULL);
    }
    execArr[0] = path_command;
    return (execArr);
}

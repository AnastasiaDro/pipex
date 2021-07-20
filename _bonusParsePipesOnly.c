
#include "pipex_bonus.h"

int _bonusParsePipesOnly(char **pathList, int **fd, t_bstruct *bStruct)
{
    parseFirstCommand(pathList, fd, bStruct);
    _bonus_parseMiddleCommands(fd, pathList, bStruct);
    parseLastCommand(pathList, fd, bStruct);
    closeAllFds(&fd, bStruct->commands_num);
    mFree(pathList);
    waitChildren();
    system("leaks pipex");
    return (0);
}

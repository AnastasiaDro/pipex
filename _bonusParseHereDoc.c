#include "pipex.h"
#include "pipex_bonus.h"
#include "libft/libft.h"
# include "get_next_line/get_next_line.h"

int _bonusParseHereDoc(char **pathList, int **fd, t_bstruct *bStruct)
{
    char *command;
    int tmpFd;
    int commands_num;

    commands_num = bStruct->commands_num;
    command = bStruct->argv[3];
    tmpFd = _bonusGetTmpFile(bStruct->argv);
    _bonusGetStdin(fd, command, pathList, tmpFd, bStruct);
    _bonus_parseMiddleCommands(fd, pathList, bStruct);
    close(tmpFd);
    _bonusParseLastRedirect(pathList, fd, bStruct);
    mFree(pathList);
    closeAllFds(&fd, commands_num);
    waitChildren();
    unlink("tmpFile");
    system("leaks pipex");
    return (0);
}

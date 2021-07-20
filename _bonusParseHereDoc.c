#include "pipex.h"
#include "pipex_bonus.h"
#include "libft/libft.h"
# include "get_next_line/get_next_line.h"

int bonusParseHereDoc(int **fd, t_bstruct *bStruct)
{
    char *command;
    int tmpFd;
    int commands_num;

    commands_num = bStruct->commands_num;
    command = bStruct->argv[3];
    tmpFd = bonusGetTmpFile(bStruct->argv);
    bonusGetStdin(fd, command, tmpFd, bStruct);
    bonusParseMiddleCommands(fd, bStruct);
    close(tmpFd);
    bonusParseLastRedirect(fd, bStruct);
    mFree(bStruct->pathList);
    closeAllFds(&fd, commands_num);
    waitChildren();
    unlink("tmpFile");
    system("leaks pipex");
    return (0);
}

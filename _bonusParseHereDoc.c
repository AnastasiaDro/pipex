#include "pipex.h"
#include "bonus.h"
# include "get_next_line/get_next_line.h"

int _bonusParseHereDoc(char *argv[], char **pathList, int **fd, int commands_num)
{
    char *command;
    int tmpFd;

    command = argv[3];
    tmpFd = _bonusGetTmpFile(argv);
    _bonusGetStdin(fd, command, pathList, tmpFd, commands_num);
    _bonus_parseMiddleCommands(commands_num, fd, argv, pathList, HERE_DOC);
    close(tmpFd);
    _bonusParseLastRedirect(argv, pathList, fd, commands_num);
    mFree(pathList);
    closeAllFds(&fd, commands_num);
    waitChildren();
    unlink("tmpFile");
    system("leaks pipex");
    return (0);
}

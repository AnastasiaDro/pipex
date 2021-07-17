#include "pipex.h"
#include "_bonus.h"
#include "libft/libft.h"
# include "get_next_line/get_next_line.h"

int _bonusParseHereDoc(char *argv[], char **pathList, int **fd, int commands_num, int argc)
{
    int pid;
    char *command;
    char **execArr;
    int fileFd;
    int tmpFd;


    //обработка первой команды
    command = argv[3];
    tmpFd = _bonusGetTmpFile(argv);
    _bonusGetStdin(fd, command, pathList, tmpFd, commands_num);
    //обработка команд посередине
    _bonus_parseMiddleCommands(commands_num, fd, argv, pathList, HERE_DOC);


    close(tmpFd);


    pid = fork();
    if (pid < 0)
        return (2);
    if(pid == 0) {
        command = argv[argc - 2];
        execArr = getExecArr(command, pathList);
        if(!access(argv[argc - 1], 0))
            fileFd = open(argv[argc - 1], O_RDWR | O_APPEND); //открываем файл, из которого берём данные
        else
            fileFd = open(argv[argc - 1], O_CREAT | O_RDWR, 0644);
        if (fileFd == -1)
        {
            printError(argv[argc - 1], 0);
        }
        dup2(fd[commands_num - 1][0], STDIN_FILENO);
        dup2(fileFd, STDOUT_FILENO);
        close(fileFd);
        _bonus_closeAllFds(&fd, commands_num);
        free(fd);
        execve(execArr[0], execArr, NULL);
    }
    _bonus_closeAllFds(&fd, commands_num);
    free(fd);
    waitChildren();
    unlink("tmpFile");
    return (0);
}

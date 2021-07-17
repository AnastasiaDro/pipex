#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"
#include "libft/libft.h"
#include "_bonus.h"

int main(int argc, char *argv[], char **envp)
{

    char **pathList;
    int **fd;
    int *hereFd;
    int commands_num;
    int flag;

    if(!ft_strcmp("here_doc", argv[1]))
        flag = HERE_DOC;
    else
        flag = 0;

    if (argc < 5)
    {
        write(1, ARGNUM_ERR, ft_strlen(ARGNUM_ERR));
        return (1);
    }
    pathList = pipexSplit(findPath(envp), ':');
//    if (!ft_strcmp("here_doc", argv[1]))
//    {
//        _bonusParseHereDoc(argv, pathList, argc);
//        exit(0);
//    }
    fd = malloc((argc - 2) * sizeof (int *));
    //на выходе получаем массив fd-шников
  //  commands_num = _bonusGetCommandsNum(argc, &fd, 0);
    //printf("commands num = %d\n", commands_num);
   // return 0;

    if (flag == HERE_DOC)
    {
        fd = malloc((argc - 3) * sizeof (int *));
        commands_num = _bonusGetCommandsNum(argc, &fd, HERE_DOC);
        _bonusParseHereDoc(argv, pathList, fd, commands_num, argc);
        exit(0);
    }
    commands_num = _bonusGetCommandsNum(argc, &fd, 0);
//    while(commands_num < argc - 2)
//    {
//        fd[commands_num] = malloc(2 * sizeof (int));
//        pipe(fd[commands_num]);
//        commands_num++;
//    }
    //commands_num--;
    fd = malloc((argc - 2) * sizeof (int *));
    parseFirstCommand(argv, pathList, fd, commands_num);
    _bonus_parseMiddleCommands(commands_num, fd, argv, pathList, 0);
    parseLastCommand(argv, pathList, fd, commands_num, argc);
    _bonus_closeAllFds(&fd, commands_num);
    waitChildren();
}

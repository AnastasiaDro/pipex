#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"
#include "libft/libft.h"

int main(int argc, char *argv[], char **envp)
{

    char **pathList;
    char *command1;
    char **execArr;

    //fork();
    command1 = argv[2];
    pathList = pipexSplit(findPath(envp), ':'); //разбили на папки, где нужно искать бинарники

    execArr = getExecArr(command1, pathList, argv[1]);

    execve(execArr[0], execArr, envp);

    return 0;
}

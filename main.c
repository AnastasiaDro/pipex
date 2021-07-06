#include <stdio.h>
#include "pipex.h"
#include "libft/libft.h"

int main(int argc, char *argv[], char **envp)
{

    char *path;
    char **pathList;
    int i;

    i = 0;

    path = findPath(envp);
    pathList = ft_split(path, ':'); //разбили на папки, где нужно искать бинарники


    return 0;
}

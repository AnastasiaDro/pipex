//
// Created by Cesar Erebus on 7/6/21.
//
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <printf.h>
#include "libft/libft.h"
#include "pipex.h"

char *findCommand(char **pathList, char *command)
{
    int i;
    char *tmp;
    char *command_path;

    i = 0;
    command_path = NULL;
    getBinaryName(&command);

    while(pathList[i])
    {
        tmp = command_path;
        command_path = ft_strjoin(pathList[i], command);
        printf("errno = %d\n", errno);
        if(!access (command_path, 0))
        {
      //      execArr[0] = command_path;
            return (command_path);
        }
        free(tmp);
        i++;
    }

    return (command_path);
}


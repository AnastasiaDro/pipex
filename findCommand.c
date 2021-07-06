//
// Created by Cesar Erebus on 7/6/21.
//
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <printf.h>
#include "libft/libft.h"
#include "pipex.h"

char *findCommand(char **pathList, char *command, char ***flags)
{
    int i;
    char *tmp;
    char *flags_tmp;
    char *command_path;

    i = 0;
    command_path = NULL;
    flags_tmp = getCommandFlags(&command);
    *flags = ft_split(flags_tmp, ' ');

    while(pathList[i])
    {
        tmp = command_path;
        command_path = ft_strjoin(pathList[i], command);
        printf("errno = %d\n", errno);
        if(!access (command_path, 0))
            return (command_path);
        free(tmp);
        i++;
    }

    return (command_path);
}


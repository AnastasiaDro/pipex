//
// Created by Cesar Erebus on 7/11/21.
//
#include <errno.h>
#include <stdio.h>
#include "pipex.h"
#include "unistd.h"
#include "libft/libft.h"
#include "libft/bonus.h"

void printError(char *command, int flag)
{
 //   int res;
    char *prefix;

    if (flag == 0)
    {
        prefix = ft_strjoin(NAME, command);
        perror(prefix);
        return;
    }
    if (flag == 1)
    {
        prefix = _bonusThreeStr_join(NAME, command, COMMAND_ERR);
        errno = 127;
        write(2, prefix, ft_strlen(prefix));
        write(2, "\n", 1);
    }
}
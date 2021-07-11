//
// Created by Cesar Erebus on 7/11/21.
//
#include "pipex.h"
#include "unistd.h"
#include "libft/libft.h"

int printError(char *error, char *command)
{
    int res;

    res = (int)(write(1, NAME, ft_strlen(NAME)) +
            write(1, error, ft_strlen(error))  +
            write(1, command, ft_strlen(command)) +
            write(1, "\n", 1));
    return (res);
}
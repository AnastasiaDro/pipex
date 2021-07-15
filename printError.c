//
// Created by Cesar Erebus on 7/11/21.
//
#include <errno.h>
#include "pipex.h"
#include "unistd.h"
#include "libft/libft.h"

int printError(char *error, char *command, int error_code)
{
    int res;

    errno = error_code;
    res = (int)(write(2, NAME, ft_strlen(NAME)) +
            write(2, error, ft_strlen(error))  +
            write(2, command, ft_strlen(command)) +
            write(2, "\n", 1));
    return (res);
}
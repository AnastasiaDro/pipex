//
// Created by Cesar Erebus on 7/11/21.
//
#include "libft/libft.h"
#include "unistd.h"

int printError(char *error, char *command)
{
    int res;

    res = (int)write(1, error, ft_strlen(error));
    res += (int)write(1, command, ft_strlen(command));
    res += (int)write(1, "\n", 1);
    return (res);
}

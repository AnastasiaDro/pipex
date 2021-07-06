//
// Created by Cesar Erebus on 7/6/21.
//
#include "libft/libft.h"

char *findPath(char **envp)
{
    int i;

    i = 0;
    while(envp[i])
    {
        if(!ft_strncmp("PATH", envp[i], 4))
            return (envp[i] + 5); //сдвигаем мимо кавычек
        i++;
    }
    return (0);
}
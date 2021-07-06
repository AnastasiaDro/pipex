//
// Created by Cesar Erebus on 7/6/21.
//
#include "libft/libft.h"

void getBinaryName(char **command)
{
    char *s;
    int i;

    s = *command;
    i = 0;
    while(s[i])
    {
        if (s[i] == ' ')
        {
            *command = ft_substr(s, 0, i);
            return;
        }
        i++;
    }
}
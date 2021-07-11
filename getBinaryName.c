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
        if(!ft_strncmp(s, "/bin/", 5))
        {
            *command = ft_substr(&(s[5]), 0, ft_strlen(&(s[5])));
            return;
        }
        if (s[i] == ' ')
        {
            *command = ft_substr(s, 0, i);
            return;
        }
        i++;
    }
}
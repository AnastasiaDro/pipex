//
// Created by Cesar Erebus on 7/6/21.
//
#include "libft/libft.h"
#include "stdlib.h"
#include "stdio.h"

char *getCommandFlags(char **command)
{
    char *s;
    int i;
    char *flags;
    char *tmp;

    s = *command;
    i = 0;
    while(s[i])
    {
        if (s[i] == ' ')
        {
            //flags = ft_substr(s, i+1, ft_strlen(&s[i + 1]));
            flags = ft_strdup(&s[i+1]);
            printf("&s[i+1] =%s   ft_strlen(&s[i]) = %d", &s[i+1], (int)ft_strlen(&s[i+1]));
            tmp = *command;
            *command = ft_substr(s, 0, i);
          //  free(tmp);
            tmp = NULL;
            return (flags);
        }
        i++;
    }
    return (NULL);
}
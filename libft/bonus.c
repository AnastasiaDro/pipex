//
// Created by Cesar Erebus on 7/4/21.
//
#include <printf.h>
#include "bonus.h"
#include "stdlib.h"

int ft_strcmp(const char *s1, const char *s2)
{
    int s1_len;
    int s2_len;
    int max_len;

    s1_len = (int)ft_strlen(s1);
    s2_len = (int)ft_strlen(s2);

    if (s1_len > s2_len)
        max_len = s1_len;
    else
        max_len = s2_len;
    return (ft_strncmp(s1, s2, max_len));
}

int ft_doubleArrlen(void **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}

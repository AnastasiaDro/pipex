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

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);

    if (s1_len > s2_len)
        max_len = s1_len;
    else
        max_len = s2_len;
    return (ft_strncmp(s1, s2, max_len));
}

char	*_bonusThreeStr_join(char const *s1, char const *s2, char const *s3)
{
    char	*newstr;
    size_t	src_len;
    size_t	new_s_flen;

    if (!s1 || !s2 || !s3)
        return (NULL);
    new_s_flen = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1;
    newstr = (char *)malloc(new_s_flen * sizeof(char));
    if (!newstr)
        return (NULL);
    src_len = ft_strlcpy(newstr, s1, new_s_flen);
    printf("1 scrlen = %d newstr = %s\n", (int)src_len, newstr);
    src_len = ft_strlcpy(&newstr[src_len], s2, new_s_flen);
    printf("2 scrlen = %d newstr = %s\n", (int)src_len, newstr);
    src_len = ft_strlcpy(&newstr[ft_strlen(newstr)], s3, new_s_flen);
    printf("s3 = %s\n", s3);
    printf("3 scrlen = %d newstr = %s\n", (int)src_len, newstr);
    newstr[new_s_flen - 1] = '\0';
    return (newstr);
}


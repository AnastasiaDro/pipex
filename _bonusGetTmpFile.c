//
// Created by Cesar Erebus on 7/17/21.
//

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
# include "get_next_line/get_next_line.h"

int  _bonusGetTmpFile(int **fd, char *argv[])
{
    char *line;
    char *str;
    int tFileFd;

    line = "";
    str = malloc(1 * sizeof (char));

    str[0] = '\0';
    tFileFd = open("tmpFile", O_CREAT | O_RDWR, 0644);
    write(1, "> ", 2);
//    get_next_line(STDIN_FILENO, &line);
//    write(tFileFd, line, ft_strlen(line));
    while (ft_strcmp(line, argv[2]))
    {
        //write(1, "> ", 2);
        write(tFileFd, line, ft_strlen(line));
        write(tFileFd, "\n", 1);
        write(1, "> ", 2);
        get_next_line(STDIN_FILENO, &line);
    }
    return tFileFd;
}

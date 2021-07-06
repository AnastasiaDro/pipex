//
// Created by Cesar Erebus on 7/6/21.
//

#include <unistd.h>
#include <fcntl.h>
#include <printf.h>
#include <errno.h>
#include "libft/libft.h"

int redirectOut(char **filename, char *command)
{
    int fd;
    char *content;

    //check_command
  //  execve()

    fd = open(*filename, O_TRUNC | O_WRONLY);
    if(fd == -1)
    {
        printf("%s: %s: No such file or directory\n", command, *filename);
        return (-1);
    }
    //вставить команду - найти бинарник по имени

    write(fd, content, ft_strlen(content));
    close(fd);
    return(0);
}
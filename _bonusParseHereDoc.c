#include "pipex.h"
#include "_bonus.h"
#include "libft/libft.h"
# include "get_next_line/get_next_line.h"

int _bonusParseHereDoc(char **argv, char **pathList, int argc)
{
   char *line;
    int *fd;
    int pid;
    char *command;
    char **execArr;
    int fileFd;
    char *str;
    int tmpFd;

    line = "";
    str = malloc(1 * sizeof (char));
    str[0] = '\0';
    fd = malloc(2 * sizeof (int));
    pipe(fd);



    tmpFd = open("tmpFile", O_CREAT | O_RDWR, 0644);
    write(1, "> ", 2);
    get_next_line(STDIN_FILENO, &line);
    write(tmpFd, line, ft_strlen(line));
    while (ft_strcmp(line, argv[2]))
    {
        write(1, "> ", 2);
        write(tmpFd, line, ft_strlen(line));
        write(tmpFd, "\n", 1);
        get_next_line(STDIN_FILENO, &line);
    }
    pid = fork();
    if (pid < 0)
        return (2);
    if(pid == 0)
    {
        tmpFd = open("tmpFile", O_RDONLY, 0644);
        command = argv[3];
        dup2(tmpFd, STDIN_FILENO);
        execArr = getExecArr(command, pathList);
        dup2(fd[1], STDOUT_FILENO);
        close(tmpFd);
        close(fd[0]);
        close(fd[1]);
        execve(execArr[0], execArr, NULL);
    }
    pid = fork();
    if (pid < 0)
        return (2);
    if(pid == 0) {
        close(tmpFd);
        command = argv[argc - 2];
        execArr = getExecArr(command, pathList);
        if(!access(argv[argc - 1], 0))
            fileFd = open(argv[argc - 1], O_RDWR | O_APPEND); //открываем файл, из которого берём данные
        else
            fileFd = open(argv[argc - 1], O_CREAT | O_RDWR, 0644);
        dup2(fileFd, STDOUT_FILENO);
        dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
        close(fd[0]);
        close(fileFd);
        execve(execArr[0], execArr, NULL);
    }
    close(fd[0]);
    close(fd[1]);
    free(fd);
    waitChildren();
    close(tmpFd);
    unlink("tmpFile");
    return (0);
}

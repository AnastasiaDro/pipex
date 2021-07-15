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
    char *tmp;
    char *str;

    line = NULL;
    str = malloc(1 * sizeof (char));
    str[0] = '\0';
    fd = malloc(2 * sizeof (int));
    pipe(fd);

//    while (!line || ft_strcmp(line, argv[2]))
//    {
//        write(1, "> ", 2);
//       // line = NULL;
//        get_next_line(STDIN_FILENO, &line);
//        tmp = str;
//        str = ft_strjoin(str, line);
//        free(tmp);
//        printf("line = %s\n", line);
//        printf("str = %s\n", str);
//    }
//    printf("END!\n");

   // write(0, str, ft_strlen(str));
    //int res = write(0, str, ft_strlen(str));
    //printf("res = %d\n", res);
    pid = fork();
    if (pid < 0)
        return (2);
    if(pid == 0)
    {
        while (!line || ft_strcmp(line, argv[2]))
        {
            write(1, "> ", 2);
            // line = NULL;
            get_next_line(STDIN_FILENO, &line);
            tmp = str;
            str = ft_strjoin(str, line);
            free(tmp);
            printf("line = %s\n", line);
            printf("str = %s\n", str);
        }
        command = argv[3];
        write(0, str, ft_strlen(str));
//        int res =  write(0, "\0", 1);
//        printf("res = %d\n", res);
        execArr = getExecArr(command, pathList);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execve(execArr[0], execArr, NULL);
    }
    pid = fork();
    if (pid < 0)
        return (2);
    if(pid == 0) {
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
        write(1, "VVV\n", 4);
        execve(execArr[0], execArr, NULL);
    }
    close(fd[0]);
    close(fd[1]);
    free(fd);
    waitChildren();
    return (0);
}

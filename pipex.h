
#ifndef PIPEX_H
# define PIPEX_H
# define NAME "pipex: "
# define ARGNUM_ERR "Invalid arguments number!\n"
# define FILE_ERR "No such file or directory: "
# define COMMAND_ERR "command not found: "

char    *findPath(char **envp);

char    **pipexSplit(char const *s, char c);

char    **getBinaryName(char **command);

char    *findCommand(char **pathList, char *command);

char    **execArrSplit(char const *s, char c, int *arrLen);

char    **getExecArr(char *command, char **pathList);

int     printError(char *error, char *command);

void    waitChildren(void);

int parseFirstCommand(char *argv[], char **pathList, int **fd, int commands_num);


#endif

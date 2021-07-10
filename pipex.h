//
// Created by Cesar Erebus on 7/6/21.
//

#ifndef PIPEX_H
# define PIPEX_H
# define ARGNUM_ERR "Invalid arguments number!\n"


char    *findPath(char **envp);

char    **pipexSplit(char const *s, char c);

char    **getBinaryName(char **command);

char    *findCommand(char **pathList, char *command);

char    **execArrSplit(char const *s, char c, int *arrLen);

char    **getExecArr(char *command, char **pathList);


#endif //PIPEX_PIPEX_H

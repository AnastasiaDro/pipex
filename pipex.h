#ifndef PIPEX_H
# define PIPEX_H
# define NAME "pipex: "
# define ARGNUM_ERR "Invalid arguments number!\n"
# define COMMAND_ERR "command not found"
# include <errno.h>
# include "unistd.h"
# include "libc.h"
# include "libft/libft.h"
# include "libft/bonus.h"

int		mFree(char **pathlist);
char	*findPath(char **envp);
char	**pipexSplit(char const *s, char c);
char	**getBinaryName(char **command);
char	*findCommand(char **pathList, char *command);
char	**execArrSplit(char const *s, char c, int *arrLen);
char	**getExecArr(char *command, char **pathList);
void	printError(char *command, int flag);
void	waitChildren(void);

#endif

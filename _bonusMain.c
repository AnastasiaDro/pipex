#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"
#include "libft/libft.h"
#include "_bonus.h"

int	main(int argc, char *argv[], char **envp)
{
	char	**pathList;
	int		**fd;
	int		commands_num;
	int		flag;

	if (argc < 5)
	{
		write(1, ARGNUM_ERR, ft_strlen(ARGNUM_ERR));
		return (1);
	}
	flag = _bonusCheckHereDoc(argv);
	fd = malloc((argc - 2 - flag) * sizeof (int *));
	commands_num = _bonusGetCommandsNum(argc, &fd, flag);
	pathList = pipexSplit(findPath(envp), ':');
	if (flag == HERE_DOC)
		_bonusParseHereDoc(argv, pathList, fd, commands_num, argc);
	else
		_bonusParsePipesOnly(argv, pathList, fd, commands_num, argc);
}

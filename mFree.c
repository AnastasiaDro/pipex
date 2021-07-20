#include "pipex.h"

int	mFree(char **pathlist)
{
	int	i;

	i = 0;
	while (pathlist[i])
	{
		free(pathlist[i]);
		i++;
	}
	free(pathlist);
	return (0);
}

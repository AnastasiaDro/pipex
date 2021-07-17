#include <unistd.h>
#include <stdlib.h>

void	_bonus_closeAllFds(int ***fd, int commands_num)
{
	int	i;
	int	**tmp;

	i = 0;
	tmp = *fd;
	while (i < commands_num)
	{
		close(tmp[i][0]);
		close(tmp[i][1]);
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
}

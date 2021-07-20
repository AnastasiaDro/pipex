#include "pipex_bonus.h"

int	bonusParsePipesOnly(int **fd, t_bstruct *bStruct)
{
	parseFirstCommand(fd, bStruct);
	bonusParseMiddleCommands(fd, bStruct);
	parseLastCommand(fd, bStruct);
	bonusCloseAllFds(&fd, bStruct->commands_num);
	mFree(bStruct->pathList);
	waitChildren();
    system("leaks pipex");
	return (0);
}

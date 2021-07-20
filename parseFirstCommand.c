#include <unistd.h>
#include <sys/fcntl.h>
#include "pipex_bonus.h"
#include <string.h>

int	parseFirstCommand(int **fd, t_bstruct *bStruct)
{
	int		pid;
	char	*command;
	char	**execArr;
	int		fileFd;

	pid = fork();
	if (pid == 0)
	{
		command = (bStruct->argv)[2];
		fileFd = open((bStruct->argv)[1], O_RDWR);
		execArr = getExecArr(command, bStruct->pathList);
		if (fileFd == -1)
			printError((bStruct->argv)[1], 0);
		if (fileFd == -1 || !execArr)
		{
			bonusClean(fd, bStruct);
			exit(0);
		}
		dup2(fd[1][1], STDOUT_FILENO);
		dup2(fileFd, STDIN_FILENO);
		close(fileFd);
		bonusClean(fd, bStruct);
		execve(execArr[0], execArr, NULL);
	}
	return (pid);
}

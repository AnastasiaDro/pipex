
#include "pipex.h"
#include "_bonus.h"

int _bonusGetCommandsNum(int argc, int ***fd, int flag)
{
    int commands_num;

    commands_num = 0;
    while(commands_num < argc - 2)
    {
        (*fd)[commands_num] = malloc(2 * sizeof (int));
        pipe((*fd)[commands_num]);
        commands_num++;
    }
    if (flag != HERE_DOC)
        commands_num--;
    else
        commands_num -= 2;
    return commands_num;
}

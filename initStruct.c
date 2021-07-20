//
// Created by Cesar Erebus on 7/20/21.
//
#include "pipex_bonus.h"
void    initStruct(t_bstruct *bstruct, int argc, char *argv[])
{
    bstruct->argc = argc;
    bstruct->flag = _bonusCheckHereDoc(argv);
    bstruct->commands_num = argc - 3 - bstruct->flag;
    bstruct->argv = argv;
}

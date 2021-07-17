//
// Created by Cesar Erebus on 7/17/21.
//
#include "pipex.h"

int mFree(void **pathlist)
{
    int i;

    i = 0;
    while(pathlist[i])
    {
        free(pathlist[i]);
        i++;
    }
   free(pathlist);
    return (0);
}

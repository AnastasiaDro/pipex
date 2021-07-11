//
// Created by Cesar Erebus on 7/11/21.
//

#include <unistd.h>
#include <printf.h>

void _bonus_closeLazyDescs(int ***fd, int currentIndex, int commands_num)
{
    int i;

    i = 0;
    int **tmp = *fd;

    while (i < commands_num)
    {
        if(i == currentIndex)
        {
            printf("i = %d\n", i);
            i++;
            continue;
        }
        close(tmp[i][0]);
        close(tmp[i][1]);
        i++;
    }
}
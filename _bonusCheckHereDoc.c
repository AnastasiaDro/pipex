
#include "bonus.h"

int _bonusCheckHereDoc(char *argv[])
{
    int flag;

    if(!ft_strcmp("here_doc", argv[1]))
        flag = HERE_DOC;
    else
        flag = 0;
    return (flag);
}
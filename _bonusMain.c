#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include "pipex.h"
#include "libft/libft.h"
#include "_bonus.h"

int main(int argc, char *argv[], char **envp)
{

    char **pathList;
    char *command;
    char **execArr;
    int pid1;
    int **fd;
    int fileFd;

    int argv_index = 0;

//    if(argc < 5)
//        return ((int)write(1, ARGNUM_ERR, (int)ft_strlen(ARGNUM_ERR)));
    pathList = pipexSplit(findPath(envp), ':');


    //сперва проверить на доступ файлы
    //как посчитать пайпы?

    argv_index = 2; //0 - это имя, 1 - это файл, 2 - первая команда
    fd = malloc((argc - 2) * sizeof (int *));
    int commands_num = 0;
    while(commands_num < argc - 2)
    {
        fd[commands_num] = malloc(2 * sizeof (int));
        pipe(fd[commands_num]); //сразу сделали пайпы
        commands_num++;
    }
    commands_num--;
  //  printf("намаллочили %d команд\n", (commands_num)); //работает



    //настроить первую команду
    //настроить команды между
    //настроить вывод последней команды в файл

    pid1 = fork();
    if (pid1 < 0)
        return (2);

    //обработка первой команды
    if (pid1 == 0)
    {
        fileFd = open(argv[1], O_RDWR); //открываем файл, из которого берём данные
        dup2(fd[1][1], STDOUT_FILENO);
        dup2(fileFd, STDIN_FILENO);
    //    write(1, "TTT\n", 4);
      //  _bonus_closeLazyDescs(&fd, 0, commands_num);
     //   write(1, "TTT\n", 4);
        //close(fd[0][0]);
        close(fileFd);
        _bonus_closeAllFds(&fd, commands_num);
        command = argv[2];
        execArr = getExecArr(command, pathList);
     //   write(1, "UUU\n", 4);
        execve(execArr[0], execArr, envp); //вы
    }

    //обработка комманд между
    int j = 1; //счетчик команд
    while(j < commands_num - 1)
    {
        _bonus_parseCmd(&fd, j, commands_num, argv, pathList);
      //  write(1, "1\n", 2);
        j++;
    }



    //обработка последней команды
    pid1 = fork();

    if (pid1 == 0)
    {
        fileFd = open(argv[argc - 1], O_RDWR); //открываем файл, из которого берём данные

       // printf("fd index last = %d\n", commands_num - 1);

        dup2(fd[commands_num - 1][0], STDIN_FILENO);
        dup2(fileFd, STDOUT_FILENO);
        close(fileFd);
        _bonus_closeAllFds(&fd, commands_num);
        command = argv[argc - 2];
        execArr = getExecArr(command, pathList);
        execve(execArr[0], execArr, envp); //вы
    }


    _bonus_closeAllFds(&fd, commands_num);
    while(wait(NULL) != -1)
        wait(NULL);

}

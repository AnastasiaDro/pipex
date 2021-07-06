#include <stdio.h>
#include <unistd.h>
#include "pipex.h"
#include "libft/libft.h"

int main(int argc, char *argv[], char **envp)
{

    char **pathList;
    char *command1;
    char command2;
//    char *file1 = argv[1];
//    char command1 = argv[2];
//    char command2 = argv[3];
//    char *file2 = argv[4];


//    char *args[5];
//    args[0] = "/bin/ls";
//    args[1] = "-l";
//    args[2] = "-a";
//
//    args[3] = "/Users/cerebus/projects/pipex/";
//    args[4] = NULL;
//    execve(args[0], args, NULL);
//
//
//
////    execve(argv[1], &argv[1], envp);
////
    //на
 //   path = findPath(envp);
   // printf("path = %s\n", path);
    pathList = pipexSplit(findPath(envp), ':'); //разбили на папки, где нужно искать бинарники


    //разбить команду на команду и аргументы

    // найти команду
    char **flags;
  //  flags = NULL;
    char *path_command = findCommand(pathList, "ls -l -a", &flags); //нашли путь к команде
   // char *flags = getCommandFlags(&path_command); //отделили команду от флагов
    printf("path_command = %s\n", path_command);
    printf("command flags %s\n", flags[0]);
    printf("command flags %s\n", flags[1]);
  //  выполним команду



    return 0;
}

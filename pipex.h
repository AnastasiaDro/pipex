//
// Created by Cesar Erebus on 7/6/21.
//

#ifndef PIPEX_H
# define PIPEX_H

char *findPath(char **envp);

int redirectOut(char **filename, char *command, char *content);

//char *findCommand(char **pathList, char *command);

char		**pipexSplit(char const *s, char c);

char **getExecArr(char **command);

char *findCommand(char **pathList, char *command);

void execute(char *file1, char command1, char *command2, char file2);

#endif //PIPEX_PIPEX_H

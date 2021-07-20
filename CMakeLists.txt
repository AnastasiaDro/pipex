cmake_minimum_required(VERSION 3.19)
project(pipex C)


set(CMAKE_C_STANDARD 99)

add_executable(pipex _bonusMain.c findPath.c redirectOut.c findCommand.c pipexSplit.c getBinaryName.c execArrSplit.c
                getExecArr.c _bonus_parseCmd.c closeAllFds.c printError.c waitChildren.c parseFirstCommand.c
                _bonus_parseMiddleCommands.c parseLastCommand.c _bonusParseHereDoc.c libft/bonus.c
                 get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
        _bonusGetTmpFile.c _bonusGetStdin.c _bonusCheckHereDoc.c _bonusParsePipesOnly.c mFree.c _bonusParseLastRedirect.c bonus.h)

#add_executable(pipex main.c findPath.c redirectOut.c findCommand.c pipexSplit.c getBinaryName.c execArrSplit.c
#        getExecArr.c _bonus_parseCmd.c closeAllFds.c printError.c waitChildren.c parseFirstCommand.c
#        _bonus_parseMiddleCommands.c parseLastCommand.c _bonusParseHereDoc.c libft/bonus.c
#        get_next_line/get_next_line.c get_next_line/get_next_line_utils.c _bonusGetCommandsNum.c
#        _bonusGetTmpFile.c _bonusGetStdin.c _bonusCheckHereDoc.c _bonusParsePipesOnly.c mFree.c _bonusParseLastRedirect.c)


target_link_libraries(pipex "/Users/cerebus/CLionProjects/pipex/libft/libft.a")
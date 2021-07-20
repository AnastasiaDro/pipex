cmake_minimum_required(VERSION 3.19)
project(pipex C)


set(CMAKE_C_STANDARD 99)

add_executable(pipex bonusMain.c findPath.c redirectOut.c findCommand.c pipexSplit.c getBinaryName.c execArrSplit.c
                getExecArr.c bonusParseCmd.c closeAllFds.c printError.c waitChildren.c parseFirstCommand.c
        bonusParseMiddleCommands.c parseLastCommand.c bonusParseHereDoc.c libft/bonus.c get_next_line/gnl_wrap_utils.c
                 get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
        bonusGetTmpFile.c bonusGetStdin.c bonusCheckHereDoc.c bonusParsePipesOnly.c mFree.c bonusParseLastRedirect.c initStruct.c bonusClean.c checkFileFd.c)

#add_executable(pipex main.c findPath.c redirectOut.c findCommand.c pipexSplit.c getBinaryName.c execArrSplit.c
#        getExecArr.c bonusParseCmd.c bonusCloseAllFds.c printError.c waitChildren.c parseFirstCommand.c
#        bonusParseMiddleCommands.c parseLastCommand.c bonusParseHereDoc.c libft/bonus.c
#        get_next_line/get_next_line.c get_next_line/get_next_line_utils.c _bonusGetCommandsNum.c
#        bonusGetTmpFile.c bonusGetStdin.c bonusCheckHereDoc.c bonusParsePipesOnly.c mFree.c bonusParseLastRedirect.c)


target_link_libraries(pipex "/Users/cerebus/CLionProjects/pipex/libft/libft.a")
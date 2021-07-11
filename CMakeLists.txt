cmake_minimum_required(VERSION 3.19)
project(pipex C)


set(CMAKE_C_STANDARD 99)

add_executable(pipex _bonusMain.c findPath.c redirectOut.c findCommand.c pipexSplit.c getBinaryName.c execArrSplit.c
                getExecArr.c _bonus_parseCmd.c _bonus_closeAllFds.c printError.c)


target_link_libraries(pipex "/Users/cerebus/projects/clion_cub3d2/libft.a")
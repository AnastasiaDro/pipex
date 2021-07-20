NAME	=	pipex
MAIN	= 	main.c
SRC		=	execArrSplit.c findCommand.c findPath.c getBinaryName.c getExecArr.c \
			pipexSplit.c printError.c waitChildren.c simpleFirstCommand.c simpleLastCommand.c\
			mFree.c simpleCloseFds.c simpleCheckFileFd.c simpleCheckExecArr.c
BONUS	= 	bonusMain.c bonusParseCmd.c bonusFirstCommand.c bonusLastCommand.c bonusParseMiddleCommands.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c get_next_line/gnl_wrap_utils.c\
			bonusCheckHereDoc.c bonusGetStdin.c bonusGetTmpFile.c bonusParseHereDoc.c\
			bonusParsePipesOnly.c bonusParseLastRedirect.c checkFileFd.c initStruct.c\
			bonusClean.c closeAllFds.c checkExecArr.c
CFLAGS	= 	-Wall -Wextra -Werror
LIBFT	= 	libft/libft.a
OMAIN	= 	$(MAIN:.c=.o)
OBJS	= 	$(SRC:.c=.o)
BOBJS 	= 	$(BONUS:.c=.o)

%.o: %.c
			@$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME):	$(OMAIN) $(OBJS)
			@make bonus -C libft
			@gcc $(OBJS) $(OMAIN) $(LIBFT) -o $(NAME)


all:		$(NAME)

bonus:		$(OBJS) $(BOBJS)
			@make bonus -C libft
			@gcc $(OBJS) $(BOBJS) $(LIBFT) -o $(NAME)

valgs:
			@gcc -g3 $(OMAIN) $(OBJS) $(LIBFT) -o $(NAME)
			@echo ""
			@echo "=====TEST 1====="
			@echo "check leaks valid args"
			valgrind --tool=memcheck  ./pipex text1 "cat -e" "cat -e" txt69
			@echo ""
			@echo "=====TEST 2====="
			@echo "invalid file"
			valgrind --tool=memcheck ./pipex text000 "cat -e" "cat -e" txt69
			@echo
			@echo "=====TEST 3====="
			@echo "invalid first arg"
			valgrind --tool=memcheck ./pipex text1 "scat -e" "cat -e" txt69
			@echo ""
			@echo "invalid second arg"
			valgrind --tool=memcheck ./pipex text1 "cat -e" "ls -sla" txt69


valgb:		bonus
			@gcc -g3 $(OBJS) $(BOBJS) $(LIBFT) -o $(BNAME)
			@echo ""
			@echo "=====BONUS 1 text3 ======"
			@echo "check leaks valid args NO here_doc"
			valgrind --tool=memcheck  ./pipex text1 "cat -e" "cat -e" "cat -e" text3
			@echo ""
			@echo "=====BONUS 2 text4 ======"
			@echo "check leaks invalid file NO here_doc"
			valgrind --tool=memcheck  ./pipex text000 "cat -e" "cat -e" "cat -e" text4
			@echo ""
			@echo "=====BONUS 3 text 5======"
			@echo "check leaks invalid first arg NO here_doc"
			valgrind --tool=memcheck  ./pipex text1 "scat -e" "cat -e" "cat -e" text5
			@echo ""
			@echo "=====BONUS 4 text6 ======"
			@echo "check leaks invalid middle arg NO here_doc"
			valgrind --tool=memcheck  ./pipex text1 "cat -e" "scat -e" "cat -e" text6
			@echo ""
			@echo "=====BONUS 5 text7====="
			@echo "check leaks invalid last arg NO here_doc"
			valgrind --tool=memcheck  ./pipex text1 "cat -e" "scat -e" "cat -e" text7
			@echo ""
			@echo "HEREDOC"
			@echo ""
			@echo "=====BONUS 6 text8====="
			@echo "here_doc VALID args"
			valgrind --tool=memcheck ./pipex here_doc L "cat -e" "cat -e" "cat -e" text8
			@echo ""
			@echo "=====BONUS 7 text9====="
			@echo "here_doc INVALID first command"
			valgrind --tool=memcheck ./pipex here_doc L "scat -e" "cat -e" "cat -e" text9


clean:
			@rm -f $(OBJS)
			@rm -f $(BOBJS)
			@rm -f $(OMAIN)
			@make bfclean -C libft

fclean:		clean
			@rm -f $(NAME)
			@make bfclean -C libft

re:			fclean all

.PHONY:		all clean fclean re bonus

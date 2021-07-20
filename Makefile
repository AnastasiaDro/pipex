NAME	=	pipex
MAIN 	= 	main.c
SRC		=	execArrSplit.c findCommand.c findPath.c getBinaryName.c getExecArr.c \
			pipexSplit.c printError.c waitChildren.c parseFirstCommand.c parseLastCommand.c \
			mFree.c closeAllFds.c
BONUS	= 	_bonusMain.c _bonus_parseCmd.c _bonus_parseMiddleCommands.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			_bonusCheckHereDoc.c _bonusGetStdin.c _bonusGetTmpFile.c \
			_bonusParseHereDoc.c _bonusParsePipesOnly.c _bonusParseLastRedirect.c
CFLAGS	= 	-Wall -Wextra -Werror
LIBFT	= 	libft/libft.a

OBJS	= 	$(SRC:.c=.o)
BOBJS 	= 	$(BONUS:.c=.o)
OMAIN	=	$(MAIN:.c=.o)

%.o: %.c
			@$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME):	$(OMAIN) $(OBJS)
			@make bonus -C libft
			@gcc $(OMAIN) $(OBJS) $(LIBFT) -o $(NAME)


all:		$(NAME)

bonus:		$(OBJS) $(BOBJS)
			@make bonus -C libft
			@gcc $(OBJS) $(BOBJS) $(LIBFT) -o $(NAME)

valg:		bonus
			@gcc -g3 $(OBJS) $(BOBJS) $(LIBFT) -o $(BNAME)

clean:
			@rm -f $(OBJS)
			@rm -f $(BOBJS)
			@make bfclean -C libft

fclean:		clean
			@rm -f $(NAME)
			@make bclean -C libft

re:			fclean all

.PHONY:		all clean fclean re bonus

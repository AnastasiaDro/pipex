NAME	=	pipex
MAIN 	= 	main.c
SRC		=	execArrSplit.c findCommand.c findPath.c getBinaryName.c getExecArr.c \
			pipexSplit.c printError.c waitChildren.c parseFirstCommand.c
BONUS	= 	_bonusMain.c _bonus_closeAllFds.c _bonus_parseCmd.c _bonus_parseMiddleCommands.c
BNAME	= 	bonus_pipex
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
			@gcc $(OBJS) $(BOBJS) $(LIBFT) -o $(BNAME)

clean:
			@rm -f $(OBJS)
			@rm -f $(BOBJS)
			@make bfclean -C libft

fclean:		clean
			@rm -f $(NAME)
			@make bfclean -C libft

re:			fclean all

.PHONY:		all clean fclean re bonus
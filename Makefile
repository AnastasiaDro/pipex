NAME	=	pipex
MAIN	= 	main.c
SRC		=	execArrSplit.c findCommand.c findPath.c getBinaryName.c getExecArr.c \
			pipexSplit.c printError.c
BONUS	= 	_bonusMain.c _bonus_closeAllFds.c _bonus_parseCmd.c
BNAME	= 	bonus_pipex
CFLAGS	= 	-Wall -Wextra -Werror
LIBFT	= 	libft/libft.a

OBJS	= 	$(SRC:.c=.o)
EXEC	=	$(MAIN:.c=.o)
BOBJS 	= 	$(BONUS:.c=.o)

%.o: %.c
			@$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(EXEC)
			@make bonus -C libft
			@gcc $(SRC) $(LIBFT) -o $(NAME)


all:		$(NAME)

bonus:		$(BOBJS) $(OBJS)
			@make bonus -C libft
			@gcc $(BOBJS) $(OBJS) $(LIBFT) -o $(BNAME)

clean:
			@rm -f $(OBJS)
			@rm -f $(BOBJS)
			@rm -f $(EXEC)
			@make bfclean -C libft

fclean:		clean
			@rm -f $(NAME)
			@make bfclean -C libft

re:			fclean all

.PHONY:		all clean fclean re bonus
NAME	=	pipex
SRC		=	main.c execArrSplit.c findCommand.c findPath.c getBinaryName.c getExecArr.c \
			pipexSplit.c
BONUS	= 	_bonusMain.c execArrSplit.c findCommand.c findPath.c getBinaryName.c \
			getExecArr.c pipexSplit.c
BNAME	= 	bonus_pipex
CFLAGS	= 	-Wall -Wextra -Werror
LIBFT	= 	libft/libft.a

OBJS	= 	$(SRC:.c=.o)
BOBJS 	= 	$(BONUS:.c=.o)

%.o: %.c
			@$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@make bonus -C libft
			@gcc $(SRC) $(LIBFT) -o $(NAME)


all:		$(NAME)

bonus:		$(BOBJS)
			@make bonus -C libft
			@gcc $(BOBJS) $(LIBFT) -o $(BNAME)

clean:
			@rm -f $(OBJS)
			@rm -f $(BOBJS)
			@make bfclean -C libft

fclean:		clean
			@rm -f $(NAME)
			@make bfclean -C libft

re:			fclean all

.PHONY:		all clean fclean re bonus
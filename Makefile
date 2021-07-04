NAME	=	pipex
SRC		=	
CFLAGS	= 	-Wall -Wextra -Werror
LIBFT	= 	libft/libft.a

OBJS	= 	$(SRC:.c=.o)

%.o: %.c
			@$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@make bonus -C libft
			gcc $(SRC) -L . $(LIBFT) $(LIBMX) -framework OpenGL -framework AppKit -o $(NAME)


all:		$(NAME)

clean:
			rm -f $(OBJS)
			@make bfclean -C libft

fclean:		clean
			rm -f $(NAME)
			@make bfclean -C libft

re:			fclean all

.PHONY:		all clean fclean re
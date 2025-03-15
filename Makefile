SRCS = main.c

NAME = push_swap
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror # -g3 -fsanitize=address
RM = rm -f

all: $(NAME)



${NAME}: ${OBJS}
	make -C ./libft bonus
	${CC} ${CFLAGS} ${OBJS} libft/libft.a -o ${NAME}
clean:
	make -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all
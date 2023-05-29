CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCS		=	main.c \
				init.c \
				thread.c \
				utils.c

OBJS		= $(SRCS:%.c=%.o)

NAME = philo

all : $(NAME)

$(NAME) : $(OBJS)
		gcc -o $(NAME) $(OBJS)

%.o : %.c
		gcc $(CFLAGS) -c $^ -o $@

clean:
		rm -f $(OBJS)
		
fclean:
		make clean
		rm -f $(NAME)
		
re:	fclean all

.PHONY		:	all clean fclean re

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCS		=	main.c \
				init.c \
				thread.c \
				thread_utils.c \
				check_finish.c \
				utils.c

OBJS		= $(SRCS:%.c=%.o)

NAME = philo

all : $(NAME)

$(NAME) : $(OBJS)
		gcc $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
		gcc $(CFLAGS) -c $^ -o $@

clean:
		rm -f $(OBJS)
		
fclean:
		make clean
		rm -f $(NAME)
		
re:	fclean all

.PHONY		:	all clean fclean re

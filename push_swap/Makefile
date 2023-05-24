CC=gcc
SRCS=src/main.c \
	src/push_swap.c \
	src/setnum.c \
	src/ft_split.c \
	src/ft_string.c \
	src/go_error.c \
	src/push_swap_utils.c \
	src/ft_sort.c \
	src/operation_r.c \
	src/operation_rr.c \
	src/operation_s.c

SRCSB=bonus/main.c \
	bonus/checker.c \
	bonus/ft_split.c \
	bonus/ft_string.c \
	bonus/ft_strcmp.c \
	bonus/get_next_line_utils.c \
	bonus/get_next_line.c \
	bonus/go_error.c \
	bonus/operation_r.c \
	bonus/operation_rr.c \
	bonus/operation_s.c \
	bonus/setnum.c

OBJS=$(SRCS:.c=.o)
OBJSB=$(SRCSB:.c=.o)
NAME=push_swap
NAMEB=checker
HEADER=-I ./includes/push_swap
HEADERB=-I ./includes/checker
CFLAG=-Wall -Werror -Wextra

ifdef WITH_BONUS
	OBJ_FILES = $(OBJSB)
	NAME=checker
else
	OBJ_FILES = $(OBJS)
endif

ifdef WITH_BONUS
%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADERB)
else
%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADER)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAG) -o $@ $^

bonus:
	make WITH_BONUS=1 all

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: all bonus clean fclean re
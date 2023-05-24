CC=gcc
HEADER=-I srcs/
CFLAG=-Wall -Werror -Wextra

CLIENT=client
BCLIENT=client_bonus
SRCS_CLIENT=srcs/client/main.c \
			srcs/utils/utils.c
BSRCS_CLIENT=srcs/client/main_bonus.c \
			srcs/utils/utils_bonus.c
OBJS_CLIENT=$(SRCS_CLIENT:.c=.o)
BOBJS_CLIENT=$(BSRCS_CLIENT:.c=.o)

SERVER=server
BSERVER=server_bonus
SRCS_SERVER=srcs/server/main.c \
			srcs/utils/utils.c
BSRCS_SERVER=srcs/server/main_bonus.c \
			srcs/utils/utils_bonus.c
OBJS_SERVER=$(SRCS_SERVER:.c=.o)
BOBJS_SERVER=$(BSRCS_SERVER:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAG) -o $(CLIENT) $(OBJS_CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAG) -o $(SERVER) $(OBJS_SERVER)

%.o: %.c
	$(CC) $(CFLAG) $(HEADER) -c $< -o $@

bonus: $(BCLIENT) $(BSERVER)

$(BCLIENT): $(BOBJS_CLIENT)
	$(CC) $(CFLAG) -o $(BCLIENT) $(BOBJS_CLIENT)

$(BSERVER): $(BOBJS_SERVER)
	$(CC) $(CFLAG) -o $(BSERVER) $(BOBJS_SERVER)

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(BCLIENT) $(BSERVER)

clean:
	rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(BOBJS_CLIENT) $(BOBJS_SERVER)

re: fclean all

.PHONY: all fclean clean re bonus
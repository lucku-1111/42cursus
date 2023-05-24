CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRC_NAME	= ft_pars_spec.c \
			ft_print_csp_utils.c \
			ft_print_csp.c \
			ft_print_percent.c \
			ft_print_di.c \
			ft_print_di_utils.c \
			ft_print_u.c \
			ft_print_x.c \
			ft_print_x_utils.c \
			ft_printf.c
SRC_PATH	= ./
SRC			= $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ_PATH	= ./
OBJ			= $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC_LINK	= -I./includes
LIBFT_FILE	= ./libft/libft.a
AR			= ar rcs
NAME		= libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C ./libft all
	@cp $(LIBFT_FILE) ./$(NAME)
	$(AR) $(NAME) $(OBJ)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(INC_LINK) -o $@ -c $<

$(LIBFT_FILE) : libft

# libft compile
libft :
	@$(MAKE) -C ./libft all

clean :
	@$(MAKE) -C ./libft clean
	@rm -rf $(OBJ)

fclean :
	@$(MAKE) -C ./libft fclean
	@rm -rf $(OBJ) $(NAME)

re : fclean all
.PHONY: libft all clean fclean re
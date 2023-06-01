CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

TARGET		=	so_long

SRCS_DIR	=	./srcs/
INCS_DIR	=	./includes/
LIB_DIR		=	./libft/
MLX_DIR		=	./mlx/
GNL_DIR		=	./gnl/

SRC			=	main.c \
				check_err.c \
				utils.c \
				read_map.c \
				check_valid.c \
				init_mlx.c \
				map_to_win.c \
				key_hook.c \
				move.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRC))
OBJS		=	$(SRCS:.c=.o)

MLX_FLAGS	=	-lmlx -framework OpenGL -framework AppKit

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $? -o $@

$(TARGET) : $(OBJS)
	make -C $(LIB_DIR)
	make -C $(MLX_DIR)
	make -C $(GNL_DIR)
	$(CC) -o $(TARGET) $(OBJS) -L $(GNL_DIR) -lgnl -L $(LIB_DIR) -lft -L $(MLX_DIR) $(MLX_FLAGS)

clean:
	make clean -C libft
	make clean -C mlx
	make clean -C gnl
	rm -rf $(OBJS)

fclean:
	make clean
	make fclean -C libft
	make fclean -C gnl
	rm -rf $(TARGET)

re:
	make fclean
	make all

.PHONY: all clean fclean re all

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

# make옵션
# -C dir: Makefile을 계속 읽지 말고 우선은 dir로 이동하라는 것.

# gcc옵션
#-c: 소스 파일을 컴파일만 하고 링크를 수행하지 않으며, 오브젝트 파일을 생성함.
#-o: 바이너리 형식의 출력 파일 이름을 지정하는데, 지정하지 않으면 a.out라는 기본 이름이 적용됨.
#-I: 헤더 파일을 검색하는 디렉토리 목록을 추가함.
#-L: 라이브러리 파일을 검색하는 디렉토리 목록을 추가함.
#-l: 라이브러리 파일을 컴파일 시 링크함.
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	megaphone.cpp
OBJ			=	$(SRC:.cpp=.o)

NAME		=	megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ) 

.o: .c
	$(CXX) $(CXXFLAGS) -c $? -o $@

clean:
	rm -f $(OBJ)

fclean:
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re
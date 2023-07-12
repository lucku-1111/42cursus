CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME		=	zombie

SRCS		=	main.cpp \
				Zombie.cpp \
				newZombie.cpp \
				randomChump.cpp
OBJS		=	$(SRCS:.cpp=.o)
HEADER		=	Zombie.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

.cpp.o: $(HEADER)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
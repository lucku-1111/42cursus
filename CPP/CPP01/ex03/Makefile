CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME		=	violence

SRCS		=	main.cpp \
				HumanA.cpp \
				HumanB.cpp \
				Weapon.cpp
OBJS		=	$(SRCS:.cpp=.o)
HEADERS		=	HumanA.hpp HumanB.hpp Weapon.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

.cpp.o: $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME		=

SRCS		=	main.cpp \
				Fixed.cpp
OBJS		=	$(SRCS:.cpp=.o)
HEADER		=	Fixed.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

.cpp.o: $(HEADER)
	$(CXX) $(CXXFLAG) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
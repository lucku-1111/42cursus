CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME		=	phonebook

SRCS		=	main.cpp \
				PhoneBook.cpp \
				Contact.cpp
OBJS		=	$(SRCS:.cpp=.o)
HEADERS		=	PhoneBook.hpp Contact.hpp

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
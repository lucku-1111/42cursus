CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INCS		=	./

SRCS		=	main.cpp \
				PhoneBook.cpp \
				Contact.cpp
OBJS		=	$(SRCS:.cpp=.o)

NAME		=	phonebook

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

.o: .c
	$(CXX) $(CXXFLAGS) -c $? -o $@ -I $(INCS)

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re
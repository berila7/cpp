NAME		=	fixed
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	Fixed.cpp main.cpp Point.cpp bsp.cpp
INC			=	Fixed.hpp Point.hpp
OBJ			=	${SRC:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:	
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
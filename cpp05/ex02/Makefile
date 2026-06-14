NAME		=	program
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRC			=	ShrubberyCreationForm.cpp Bureaucrat.cpp main.cpp AForm.cpp
INC			=	ShrubberyCreationForm.hpp Bureaucrat.hpp AForm.hpp
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
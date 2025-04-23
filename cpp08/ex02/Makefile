NAME = Mutant
SRC = main.cpp
CXX = c++ 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	

fclean: clean
	rm -rf $(NAME)

re: fclean all

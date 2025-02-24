NAME = claptrap
SRC = main.cpp ClapTrap.hpp ClapTrap.cpp
CXX = c++ 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

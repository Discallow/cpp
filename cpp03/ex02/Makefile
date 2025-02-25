NAME = fragtrap
SRC = main.cpp ClapTrap.hpp ClapTrap.cpp ScavTrap.hpp ScavTrap.cpp FragTrap.cpp FragTrap.hpp
CXX = c++ 
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

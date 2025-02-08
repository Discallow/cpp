NAME = phonebook
SRC = Phonebook.cpp Contact.cpp main.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./
OBJS = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = span
SOURCES = main.cpp Span.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(NAME) $(OBJECTS)

re: fclean all

.PHONY: all clean fclean re
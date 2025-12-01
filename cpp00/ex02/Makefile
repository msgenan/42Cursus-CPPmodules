NAME        = account

# Compiler & flags
CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98

# Directories
OBJ_DIR     = obj

# Sources & objects
SRCS        = Account.cpp tests.cpp
OBJS        = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
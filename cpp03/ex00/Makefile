# ********************************* SETUP ************************************ #

NAME        = claptrap

# Compiler & Flags
CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98

# Directories
OBJ_DIR     = obj

# Sources & Objects
SRCS        = ClapTrap.cpp main.cpp
OBJS        = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Colors
RESET       = \033[0m
BOLD        = \033[1m
RED         = \033[31m
GREEN       = \033[32m
YELLOW      = \033[33m
BLUE        = \033[34m

# ********************************* RULES ************************************ #

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo ""
	@echo "$(GREEN)$(BOLD)--- SUCCESS ---$(RESET)"
	@echo "$(GREEN)Executable created: $(BOLD)$(NAME)$(RESET)"
	@SIZE=$$(du -h $(NAME) | cut -f1); \
	echo "$(GREEN)Size: $(BOLD)$$SIZE$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Compiling: $(BOLD)$<$(RESET)"
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Object files cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re

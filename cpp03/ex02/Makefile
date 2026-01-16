# ********************************* SETUP ************************************ #

NAME        = FragTrap

# Compiler & Flags
CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98

# Directories
OBJ_DIR     = obj

# Sources & Objects
SRCS        = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp
OBJS        = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Color codes and styles
RESET       = \033[0m
BOLD        = \033[1m
RED         = \033[31m
BLUE        = \033[34m
CYAN        = \033[36m
GREEN       = \033[32m
YELLOW      = \033[33m

# Message templates
MSG_COMPILING = $(CYAN)Compiling:$(RESET) $(BOLD)$<$(RESET)
MSG_CREATED   = $(GREEN)Executable created:$(RESET) $(BOLD)$(NAME)$(RESET)
MSG_CLEAN     = $(YELLOW)Object files removed.$(RESET)
MSG_FCLEAN    = $(YELLOW)Executable removed.$(RESET)
MSG_SUCCESS   = $(BLUE)$(BOLD)--- SUCCESS ---$(RESET)

# ********************************* RULES ************************************ #

all: $(NAME)

# Create object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compilation rule
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CPP) $(CPPFLAGS) -c $< -o $@
	@echo "$(MSG_COMPILING)"

# Linking rule
$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(MSG_SUCCESS)"
	@echo "$(MSG_CREATED)"
	@echo "$(BLUE)Size: $(RESET)\c"
	@ls -lh $(NAME) | awk '{print $$5}'

# Cleaning rule
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(MSG_CLEAN)"

# Full cleaning rule
fclean: clean
	@rm -f $(NAME)
	@echo "$(MSG_FCLEAN)"

# Rebuild rule
re: fclean all

# Phony targets
.PHONY: all clean fclean re

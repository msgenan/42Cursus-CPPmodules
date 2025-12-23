# ********************************* SETUP ************************************ #

NAME        = violence

# Compiler & Flags
CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98

# Directories
OBJ_DIR     = obj

# Sources & Objects
SRCS        = Weapon.cpp HumanA.cpp HumanB.cpp main.cpp
OBJS        = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# ******************************** STYLE ************************************ #

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

# ******************************** RULES ************************************* #

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
	@du -h $(NAME) 2>/dev/null | awk '{print $$1}' || echo "N/A"
	@echo

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)--- CLEAN ---$(RESET)"
	@echo "$(MSG_CLEAN)\n"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(BOLD)--- FCLEAN ---$(RESET)"
	@echo "$(MSG_FCLEAN)\n"

re: fclean all

.PHONY: all clean fclean re

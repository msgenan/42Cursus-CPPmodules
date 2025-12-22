# ********************************* SETUP ************************************ #

NAME        = replace

# Compiler & Flags
CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98

# Directories
OBJ_DIR     = obj

# Sources & Objects
SRCS        = main.cpp
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
	@printf "$(MSG_COMPILING)\n"

# Linking rule
$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@printf "\n$(MSG_SUCCESS)\n"
	@printf "$(MSG_CREATED)\n"
	@printf "$(BLUE)Size: $(RESET)"
	@du -h $(NAME) 2>/dev/null | awk '{print $$1}' || echo "N/A"
	@printf "\n"

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)$(BOLD)--- CLEAN ---$(RESET)\n"
	@printf "$(MSG_CLEAN)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)$(BOLD)--- FCLEAN ---$(RESET)\n"
	@printf "$(MSG_FCLEAN)\n"

re: fclean all

.PHONY: all clean fclean re

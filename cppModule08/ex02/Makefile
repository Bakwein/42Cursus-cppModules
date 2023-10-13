NAME	= ex02

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRC		= main.cpp
		  
OBJ		= $(SRC:.cpp=.o)

#COLORS
RED        = \033[0;31m
GREEN    = \033[0;32m
YELLOW    = \033[0;33m
RESET    = \033[0m


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "$(GREEN)✅Compiled✅$(RESET)"

%.o: %.cpp
	@echo "$(GREEN)🔜Compiling🔜$(YELLOW)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🔜Deleting Object Files🔜$(YELLOW)"
	rm -f *.o
	@echo "$(RED)🗑️ Object Files Deleted🗑️$(YELLOW)"

fclean: clean
	@echo "$(RED)🔜Deleting NAME🔜 $(YELLOW)"
	rm -f $(NAME)
	@echo "$(RED)🗑️ NAME Deleted🗑️ $(YELLOW)"

re: fclean all

.PHONY: all re clean fclean
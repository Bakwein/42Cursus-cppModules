# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 19:09:54 by stunca            #+#    #+#              #
#    Updated: 2023/09/21 17:16:21 by stunca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= test

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRC		= Account.cpp \
		  tests.cpp

OBJ		= $(SRC:.cpp=.o)

#COLORS
BLACK    = \033[0;30m
RED        = \033[0;31m
GREEN    = \033[0;32m
YELLOW    = \033[0;33m
BLUE    = \033[0;34m
PURPLE    = \033[0;35m
CYAN    = \033[0;36m
WHITE    = \033[0;37m
END        = \033[m
RESET    = \033[0m
X        = \033[m
B_CYAN        = \033[1;36m
B_BLUE        = \033[1;34m
B_YELLOW    = \033[1;33m
B_GREEN        = \033[1;32m
B_RED        = \033[1;31m
B_RESET        = \033[1m


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
	rm -f *.log
	@echo "$(RED)🗑️ NAME and *.log Deleted🗑️ $(YELLOW)"

re: fclean all

.PHONY: all re clean fclean
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 21:57:25 by JFikents          #+#    #+#              #
#    Updated: 2023/11/08 21:20:02 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -rf
CC = cc
CCFLAGS = -Wall -Wextra -Werror
ADD = -fsanitize=address -g -D BUFFER_SIZE=1
OBJ+ = $(C_FILES:.c=.o) $(BONUS_FILES:.c=.o)
DEBUGGER = debugger/

NAME = 
MAIN = main.c
H_FILE = get_next_line.h
C_FILES = get_next_line.c get_next_line_utils.c

.PHONY: clean fclean re all c

all: $(NAME)

# bonus: all

$(NAME) : $(OBJ+)
	@$(LIB) $(NAME) $(OBJ+)

%.o : %.c 
	@$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJ+)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

t: c
	@$(CC) $(ADD) $(CCFLAGS) $(H_FILE) $(C_FILES) $(MAIN)
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
	@mv *.gch $(DEBUGGER)
	@make fclean

c: fclean
	@$(RM) $(DEBUGGER)* 
	@$(RM) *.out *.dSYM *.gch 
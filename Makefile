# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 01:14:40 by abesneux          #+#    #+#              #
#    Updated: 2024/03/20 19:01:36 by abesneux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
INCLUDES    = includes/
SRC_DIR     = src/
OBJ_DIR     = obj/

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
PRFLAGS     = -ldl -lglfw -pthread -lm
RM          = rm -rf

LIBFT_DIR    = $(INCLUDES)Libft/
LIBFT        = $(LIBFT_DIR)libft.a
LIBFT_CFLAGS = -fPIC


MOVES_DIR  = moves/
MOVE      = push reverse_rotates rotates swaps

SORT_DIR = sort/
SORT = simple_sort big_sort sort_utils

SRC_FILES  += main utils check_args stack stack_utils
SRC_FILES  += $(addprefix $(MOVES_DIR), $(MOVE))
SRC_FILES  += $(addprefix $(SORT_DIR), $(SORT))

SRC         = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ         = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJ_CACHE   = .cache_exists

###

all: 			 $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) CFLAGS+=$(LIBFT_CFLAGS)


$(NAME): 		$(OBJ)
					$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
					@echo "\033[0;32m$(shell echo $(NAME) | tr '[:lower:]' '[:upper:]') : COMPILED\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)
					@mkdir -p $(OBJ_DIR)$(MOVES_DIR)
					@mkdir -p $(OBJ_DIR)$(SORT_DIR)

clean:
					@make clean -C $(LIBFT_DIR)
					$(RM) $(OBJ_DIR)
					$(RM) $(OBJ_CACHE)
					@echo "push_swap and libs object files cleaned!"

fclean: 		clean
					@make fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					@echo "push_swap and libs executable files cleaned!"

re: 			fclean all
					@echo "Cleaned and rebuilt everything for push_swap!"

.PHONY:			all clean fclean re

.SILENT:
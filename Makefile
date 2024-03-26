# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 01:14:40 by abesneux          #+#    #+#              #
#    Updated: 2024/03/26 20:07:35 by abesneux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME        = push_swap
# BONUS_NAME  = checker
# INCLUDES    = includes/
# SRC_DIR     = src/
# OBJ_DIR     = obj/

# CC          = cc
# CFLAGS      = -Wall -Wextra -Werror -g
# PRFLAGS     = -ldl -lglfw -pthread -lm
# RM          = rm -rf

# LIBFT_DIR    = $(INCLUDES)Libft/
# LIBFT        = $(LIBFT_DIR)libft.a
# LIBFT_CFLAGS = -fPIC


# MOVES_DIR  = moves/
# MOVE      = push reverse_rotates rotates swaps

# SORT_DIR = sort/
# SORT = simple_sort big_sort sort_utils

# SRC_FILES  += main utils check_args stack stack_utils
# SRC_FILES  += $(addprefix $(MOVES_DIR), $(MOVE))
# SRC_FILES  += $(addprefix $(SORT_DIR), $(SORT))
# BONUS_SRC = bonus.c

# SRC         = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
# OBJ         = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

# OBJ_CACHE   = .cache_exists



# all: 			 $(LIBFT) $(NAME)

# bonus: 			$(LIBFT) $(BONUS_NAME)

# $(LIBFT):
# 	@make -C $(LIBFT_DIR) CFLAGS+=$(LIBFT_CFLAGS)


# $(NAME): 		$(OBJ)
# 					$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
# 					@echo "\033[0;32m$(shell echo $(NAME) | tr '[:lower:]' '[:upper:]') : COMPILED\033[0m"
					
# $(BONUS_NAME):	$(OBJ)
# 					$(CC) $(CFLAGS) $(SRC_DIR)$(BONUS_SRC) $(filter-out $(SRC_DIR)main.c, $(SRC)) $(LIBFT) -o $(BONUS_NAME)
# 					@echo "\033[0;32m$(shell echo $(BONUS_NAME) | tr '[:lower:]' '[:upper:]') : COMPILED\033[0m"

# $(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_CACHE)
# 					@echo "Compiling $<"
# 					@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

# $(OBJ_DIR_BONUS)%.o:	$(SRC_DIR)%.c | $(OBJ_CACHE)
# 					@echo "Compiling $<"
# 					@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

# $(OBJ_CACHE):
# 					@mkdir -p $(OBJ_DIR)
# 					@mkdir -p $(OBJ_DIR)$(MOVES_DIR)
# 					@mkdir -p $(OBJ_DIR)$(SORT_DIR)

# clean:
# 					@make clean -C $(LIBFT_DIR)
# 					$(RM) $(OBJ_DIR)
# 					$(RM) $(OBJ_CACHE)
# 					@echo "push_swap and libs object files cleaned!"

# fclean: 		clean
# 					@make fclean -C $(LIBFT_DIR)
# 					$(RM) $(NAME) $(BONUS_NAME)
# 					@echo "push_swap and libs executable files cleaned!"

# re: 			fclean all
# 					@echo "Cleaned and rebuilt everything for push_swap!"


# .PHONY:			all clean fclean re bonus

# .SILENT:



NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror 
LIBFTDIR = includes/Libft/
LIBFT_CFLAGS = -fPIC
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = src/

SRC_1 = src/main.c \

SRC_2 = src/stack.c \
		src/check_args.c \
		src/moves/rotates.c \
		src/moves/reverse_rotates.c \
		src/moves/swaps.c \
		src/moves/push.c \
		src/stack_utils.c \
		src/utils.c \
		src/sort/simple_sort.c \
		src/sort/big_sort.c \
		src/sort/sort_utils.c \

BONUS_SRC = src/bonus.c \
			

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

INCLUDE = includes/Libft/libft.a

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR) FLAGS+=$(LIBFT_CFLAGS)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE} -fPIE

${BONUS}: ${OBJ_2} ${BONUS_OBJ} 
	make -C $(LIBFTDIR) FLAGS+=$(LIBFT_CFLAGS)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INCLUDE} -fPIE

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT:



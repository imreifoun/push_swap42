# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 14:20:23 by areifoun          #+#    #+#              #
#    Updated: 2023/05/23 11:11:10 by areifoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SOURCES = ./src
OBJECTS = ./obj
SOURCES_BONUS = ./bonus
OBJECTS_BONUS = ./obj_bonus
INCLUDE = ./inc

CC = CC

UFLAGS = -Wall -Werror -Wextra

SRC  = main.c ft_convert_args.c ft_arg_checker.c ft_linked_outils.c ft_stack_index.c ft_list_actions.c ft_instructions.c ft_extra_instructions.c ft_extra_instructions2.c ft_sort_small.c ft_sort_small_outils.c ft_long_sort.c \
		utils2.c ft_split.c utils1.c

SRC_B = checker.c ft_convert_args.c ft_arg_checker.c ft_linked_outils.c ft_list_actions.c ft_instructions.c ft_extra_instructions.c ft_extra_instructions2.c ft_is_sorted.c utils2.c ft_split.c utils1.c ft_strcmp.c get_next_line.c

OBJ = $(addprefix $(OBJECTS)/, $(SRC:.c=.o))

OBJ_B = $(addprefix $(OBJECTS_BONUS)/, $(SRC_B:.c=.o))

all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJ)
	@$(CC) $(UFLAGS) $(OBJ) -o $@
	
$(OBJECTS)/%.o : $(SOURCES)/%.c $(INCLUDE)/push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(UFLAGS) -c $< -o $@

$(NAME_BONUS): $(OBJ_B)
	@$(CC) $(UFLAGS) $(OBJ_B) -o $@

${OBJECTS_BONUS}/%.o : ${SOURCES_BONUS}/%.c $(INCLUDE)/push_swap_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(UFLAGS) -c $< -o $@
	
clean: 
	@-rm -rf $(OBJECTS)
	@-rm -rf $(OBJECTS_BONUS)

fclean: clean
	@-rm -rf $(NAME)
	@-rm -rf $(NAME_BONUS)

re: fclean all

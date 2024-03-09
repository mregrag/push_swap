# ****************************************************************************
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 01:45:00 by mregrag           #+#    #+#              #
#    Updated: 2024/03/09 16:38:36 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = push_swap
NAME_BONUS = checker

SRC = \
	mandatory/check_input.c\
	mandatory/ft_list.c\
	mandatory/main.c\
	mandatory/movement.c\
	mandatory/move_push.c\
	mandatory/push.c\
	mandatory/swap.c\
	mandatory/retate.c\
	mandatory/rev_retate.c\
	mandatory/sort_stack.c\
	mandatory/sort_three.c\
	mandatory/stack_init.c\
	mandatory/stack_utils.c\
	Libft/ft_atoi.c\
	Libft/ft_isdigit.c\
	Libft/ft_putendl_fd.c\
	Libft/ft_split.c\
	Libft/ft_strchr.c\
	Libft/ft_strdup.c\
	Libft/ft_strlen.c\
	Libft/ft_strncmp.c\
	Libft/ft_substr.c

SRCB = \
	bonus/check_input.c\
	bonus/ft_list.c\
	bonus/push.c\
	bonus/swap.c\
	bonus/retate.c\
	bonus/rev_retate.c\
	bonus/stack_init.c\
	bonus/stack_utils.c\
	bonus/checker.c\
	bonus/get_next_line.c\
	Libft/ft_atoi.c\
	Libft/ft_isdigit.c\
	Libft/ft_putendl_fd.c\
	Libft/ft_split.c\
	Libft/ft_strchr.c\
	Libft/ft_strdup.c\
	Libft/ft_strjoin.c\
	Libft/ft_strlen.c\
	Libft/ft_strncmp.c\
	Libft/ft_substr.c


OBJ  := ${SRC:.c=.o}
OBJB := ${SRCB:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

%.o: %.c ./include/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(OBJB)
	$(CC) $(OBJB) $(CFLAGS) -o $(NAME_BONUS)
clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY:		all clean fclean re

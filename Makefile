# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/18 15:57:11 by moel-oua          #+#    #+#              #
#    Updated: 2025/02/03 11:01:13 by moel-oua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = ./main.c ./utils/utils.c ./utils/ft_split.c ./utils/ft_atoi.c \
       ./utils/error.c ./utils/ft_lstnew.c ./utils/ft_lstadd_back.c \
       ./utils/ft_lstsize.c ./utils/ft_lstlast.c \
       ./rules/swap.c ./rules/rotate.c ./rules/reverse_rotate.c \
       ./rules/push.c ./rules/five_or_less.c ./rules/sorting.c

BONUS = ./bonus/checker.c \
		./bonus/gnl/get_next_line.c \
		./bonus/gnl/get_next_line_utils.c  \
		./bonus/rules/push_bonus.c  \
		./bonus/rules/reverse_rotate_bonus.c  \
		./bonus/rules/rotate_bonus.c  \
		./bonus/rules/swap_bonus.c  \
		./bonus/utils/error_bonus.c  \
		./bonus/utils/ft_atoi_bonus.c  \
		./bonus/utils/ft_lstadd_back_bonus.c  \
		./bonus/utils/ft_lstlast_bonus.c  \
		./bonus/utils/ft_lstnew_bonus.c  \
		./bonus/utils/ft_lstsize_bonus.c  \
		./bonus/utils/ft_split_bonus.c  \
		./bonus/utils/ft_strncmp.c \
		./bonus/utils/utils_bonus.c

OBJECTS = $(SRCS:.c=.o)
BONUS_OBJECTS = $(BONUS:.c=.o)
NAME = push_swap
BONUS_NAME = checker
HEADER = push_swap.h
HEADER_BONUS = checker.h

all: $(NAME)

$(NAME): $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

./%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: %.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY:	clean 

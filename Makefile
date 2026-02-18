# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: your-login <your-login@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 02:35:00 by your-login          #+#    #+#              #
#    Updated: 2026/02/18 02:35:00 by your-login         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = string.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

SRCS        = string.c libft_functions.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

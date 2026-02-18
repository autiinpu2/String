NAME        = string.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I includes
RM          = rm -f

SRC_DIR     = src/
SRC_FILES   = string.c libft_functions.c
SRCS        = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS        = $(SRCS:.c=.o)

all: $(NAME)
	$(MAKE) clean

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
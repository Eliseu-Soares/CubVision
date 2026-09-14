NAME = libftprintf.a
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
SRC = numeric.c pointer.c string.c ft_printf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

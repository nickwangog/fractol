NAME = libft.a
CC = gcc
SRCDIR = ./srcs/
SRC = $(wildcard $(SRCDIR)*.c)
OBJ = $(patsubst $(SRCDIR)%.c, objs/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

force:
	@true

objs/%.o: srcs/%.c
	@mkdir -p objs
	@$(CC) -Wall -Wextra -Werror -I$(SRCDIR) -c $^ -o $@

clean:
	@rm -rf objs
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

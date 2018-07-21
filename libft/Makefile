NAME = libft.a
LIBFT = ./libft/libft.a
SRCDIR = ./srcs/
LIBDIR = ./libft/
OBJDIR = ./objs/
INCDIR = ./includes/
SRC = $(wildcard $(SRCDIR)*.c)
OBJ = $(patsubst $(SRCDIR)%.c, objs/%.o, $(SRC))
LIB = ./libft/objs/ft*.o
INC = -I $(INCDIR)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

objs/%.o: srcs/%.c
	@mkdir -p objs
	@gcc $(FLAGS) $(INC) -c $^ -o $@

$(LIBFT):
	@make -C $(LIBDIR)

$(NAME): $(LIBFT) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(LIB)

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBDIR)

fclean:
	@make clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBDIR)

re:	
	@make fclean
	@make all

.PHONY: all clean fclean re

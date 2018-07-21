NAME = fractol
LIBDIR = ./libft/libft.a
SRCDIR = ./srcs/
LIBDIR = ./libft/
OBJDIR = ./objs/
INCDIR = ./includes/
MLXDIR = ./minilibx/
SRCFILES =	main.c

OBJFILES =	$(SRCFILES:.c=.o)
SRCS        = $(addprefix $(SRCDIR), $(SRCFILES))
OBJ        = $(addprefix $(OBJDIR), $(OBJFILES))
LIBFT      = $(addprefix $(LIBDIR), libft.a)
MLXLIB      = $(addprefix $(MLXDIR), libmlx.a)
LNK  = -L $(LIBDIR) -lft -L $(MLXDIR) \
		-Ofast -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Werror -Wextra

all: obj $(LIBFT) $(MLXLIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@gcc $(FLAGS) -I $(MLXDIR) -I $(MLXDIR) -I $(INCDIR) -o $@ -c $<

$(LIBFT):
	@make -C $(LIBDIR)

$(MLXLIB):
	@make -C $(MLXDIR)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LNK)
	@echo "Butterhorn!"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBDIR)
	@make clean -C $(MLXDIR)

fclean:
	@make clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBDIR)

re:	
	@make fclean
	@make all

.PHONY: all clean fclean re

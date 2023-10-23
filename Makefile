NAME	:= cub3d
CC		:= gcc
INCLUDE = src/cub3d.h
CFLAGS	:= -ggdb -I $(INCLUDE) -I ./libft
LIBFT	= libft
FLAGS	= -Wall -Wextra -Werror -g
LFLAGS	= -framework OpenGL -framework AppKit
SRCDIR	:= src
SRC		:= $(shell find $(SRCDIR) -name '*.c')
OBJDIR	:= ./obj
OBJ		:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: minilibx $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(LFLAGS) -g $(FLAGS) $(CFLAGS) $(OBJ) -o $(NAME) ./mlx/libmlx.a ./libft/libft.a

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -g $(CFLAGS) -c $< -o $@

minilibx:
	@make -C mlx
	@cp mlx/libmlx.a .
	echo "MINILIBX compile edildi !"

clean:
	make clean -C $(LIBFT)
	rm -rf libmlx.a
	@rm -rf $(OBJDIR)

fclean:
	make fclean -C $(LIBFT)
	rm -rf libmlx.a
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re:	fclean all
.PHONY = all minilibx clean fclean re